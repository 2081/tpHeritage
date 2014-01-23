/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>      // std::istringstream

#include <istream>
#include <sstream>
#include <iterator>

//------------------------------------------------------ Include personnel
#include "../Vue/ConsoleUI.h"	//Vue
#include "../Vue/FichierUI.h"	//Vue
#include "../Commande/Commande.h" //Commande
//#include "../Commande/CmdAjouterElement.h/"
#include "../Modele/Modele.h"	//Modele
#include "Controleur.h"
#include "../Commande/CmdAjouterElement.h"
#include "../Commande/CmdDeplacer.h"
#include "../Commande/CmdGrouper.h"
#include "../Commande/CmdSupprimer.h"
#include "../Commande/CmdVider.h"
#include "../Commande/Commande.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Controleur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Controleur::Lancer_console()
{
	console->Attendre_instruction();
}

bool Controleur::VerifierSaveLoad(string& filename)
{
	if(tab_instruction.size()>2) return false ;

	filename = tab_instruction[1] ;
	cout << filename << ", retour de true" << endl ;
	return true ;
}

Commande * Controleur::Traduire_instruction(string instruction) // Pas de Faire() ici
{
	/*Traduction de soit : "C","R","L","PL","OA","DELETE","MOVE",
	"LIST"*/
	cout << "# Appel de traduction" << endl ;

	Commande * renvoi = 0;

	if (premier_argument == "DELETE")
	{
		renvoi = new CmdSupprimer(modele) ;

	} else if(premier_argument == "MOVE")
	{
		renvoi = new CmdDeplacer(modele) ;

	}
	else if(premier_argument == "CLEAR")
	{
		//Créer instance de CmdSequence.
	}
	else if(premier_argument == "LOAD")
	{
		string filename;
		if (VerifierSaveLoad(filename))
		{
			cout << "appel de cherger" << endl ;
			renvoi = fichierUI->Charger_modele(filename) ;
		}
	}
	else	//Création d'un objet ou objet agrégé.
	{
		//cout << "# Appel de CmdAjouterElement depuis Traduire." << endl ;
		renvoi = new CmdAjouterElement(modele) ;
	}
	if(!renvoi->Initialisation(instruction)){
		cout << "Retour dans traduire - bloc d'erreur" << endl ;
		cout << "renvoi avant le delete" << renvoi << endl ;
		delete renvoi;	//Le programme bugue à cet endroit.
		cout << "arpès le delete" << endl ;
		renvoi = 0;
	}
	cout << "renvoi dans 0 : " << renvoi << endl ;
	return renvoi;
}


bool Controleur::Executer_instruction(string instruction) // retourne toujours true, sauf si EXIT
// Algorithme :
//
{	premier_argument = "pas_trouve" ;
	tab_instruction.clear();
	istringstream flux_commande(instruction);
	istream_iterator<string> begin(flux_commande), end;
	tab_instruction = vector<string>(begin, end);


	string premier = tab_instruction[0];
	//Recherche dans la liste de commandes attendues.
	for( pt = liste_commandes ; pt != liste_commandes+14; pt++)
	{
		if(*pt == premier && premier_argument=="pas_trouve")
		{
			premier_argument = *pt ;
		}
	}

	//Analyse du résultat et appel des procédures de commandes.
	if(premier_argument=="pas_trouve")
	{
		cout << "# \"" << premier << "\"" << " n'est pas une commande valide" << endl ;
		//return true ;
	}
	else if(premier_argument == "SAVE")
	{
		string filename;
		if (VerifierSaveLoad(filename))
		{
			cout << "appel de sauvegarder" << endl ;
			// && !modele->elements.empty()
			fichierUI->Sauvegarder_modele(filename);
		}
		//return true ;

	}

	else if(premier_argument == "LIST")
	{
		console->Lister_modele();
		return true ;
		//Créer instance de CmdSequence.
	}
	else if(premier_argument == "EXIT")
	{
		//demande si l'utilisateur veut enregistrer sa figure /// <--- C'est pas dans les spec !
		//Verif si la dernière commande était une sauvegarde
		/*if (liste_cmd.top() != ##sauvegarde)
		{*/
			cout << "# Passage dans exit\n" ;
			bool reponse_pas_bonne = true ;
			while(reponse_pas_bonne == true)
			{
				string reponse_question ;
				cout << "# Voulez-vous sauvegarder votre travail avant de quitter ? (y/yes ; n/no) :" ;
				getline(cin,reponse_question);
				if (reponse_question == "y" || reponse_question == "yes" || reponse_question == "Yes" || reponse_question == "Y")
				{
					cout << "# Yes ! " << endl ;
					reponse_pas_bonne = false ;
					string filename;
					cout << "# Veuillez rentrer le nom de votre sauvegarde." << endl ;
					getline(cin , filename);
					fichierUI->Sauvegarder_modele(filename);
				}
				else if (reponse_question == "n" || reponse_question == "no" || reponse_question == "No" || reponse_question == "N")
				{
					reponse_pas_bonne = false ;
				}
				else
				{
					cout << "# \"" << reponse_question << "\" n'est pas une réponse valide, veuillez répondre à nouveau." << endl ;
				}
			}

		return false;
	}
	else if(premier_argument == "REDO")
	{
		//Appel de faire de l'avant dernière commande de la pile.
		//return true ;
	}
	else if(premier_argument == "UNDO")
	{
		//Appel de defaire de la dernière commande de la pile.
		//return true ;
	}
	else
	{
		/*Appel de la fonction traduire.*/
		//liste_cmd.push_back( ) ;
		Commande * retour = Traduire_instruction(instruction) ;
		cout << "retour dans exécuter - bloc d'erreur" << endl ;
		cout << "retour : " << retour << endl ;
		if(retour != 0)
		{
			if(retour->Faire()){
				cout << "La commande s'est exécutée correctement, on l'ajoute dans le pile." << endl ;
				liste_cmd.push_back(retour);
				cout << "OK" << endl;
			} else {
				cout << "ERR" << endl;
			}
		} else {
			cout << "ERR" << endl;
		}
	}

	return true ;
	//liste des elsif
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Controleur & Controleur::operator = ( const Controleur & unControleur )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur ( )
// Algorithme :
//
{
	pt = liste_commandes ;	//Réinitialisé à chaque fois dans
		//Executer_instruction
	modele = new Modele() ;
	console = new ConsoleUI(modele , this) ;
	fichierUI = new FichierUI( this , modele ) ;
#ifdef MAP
    cout << "# Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur ( )
// Algorithme :
//
{
	cout << "# A bientôt ! " << endl ;
	delete console ;
	delete fichierUI ;
#ifdef MAP
    cout << "# Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

