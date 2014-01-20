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

bool Controleur::VerifierSaveLoad(string& filename, string& ligne_de_commande_restante, istringstream& flux_commande)
{
	//gestion des noms de fichier avec apostrophe.
	size_t found = instruction_cours.find("\'") ;
	if (found!=string::npos)
	{
		//première apostrophe
		unsigned int premiere = found ;
		found = instruction_cours.find("\'" , found+1) ;
		if(found!=string::npos)
		{
			//les deux apostrophes sont présentes
			int longueur = found - premiere -1 ;
			filename = instruction_cours.substr(++premiere , longueur) ;

			int fin_commande = instruction_cours.size() - found ;
			ligne_de_commande_restante = instruction_cours.substr(++found , fin_commande) ;
		}
	}
	else
	{
		getline(flux_commande , filename , ' ');
		getline(flux_commande , ligne_de_commande_restante , ' ');
	}

	if (ligne_de_commande_restante == "")
	{
		return true ;
	}
	else
	{
		cout << "SAVE ne prend qu'un seul paramètre : son nom de fichier sans espaces." << endl ;
		return false ;
	}
}

Commande * Controleur::Traduire_instruction(string instruction)
{
	/*Traduction de soit : "C","R","L","PL","OA","DELETE","MOVE",
	"LIST"*/
	cout << "Appel de traduction" << endl ;

	if (premier_argument == "DELETE")
	{
		Commande * Nouvelle_commande = new CmdSupprimer(modele) ;
		if(Nouvelle_commande->Initialisation(instruction) && Nouvelle_commande->Faire())
		{
			return Nouvelle_commande ;
		}
		else
		{
			return 0 ;
		}
	}
	else if(premier_argument == "MOVE")
	{
		Commande * Nouvelle_commande = new CmdDeplacer(modele) ;
		if(Nouvelle_commande->Initialisation(instruction) && Nouvelle_commande->Faire())
		{
			return Nouvelle_commande ;
		}
		else
		{
			return 0 ;
		}
	}

	else if(premier_argument == "LOAD")
	{
		string filename;
		string ligne_de_commande_restante ;

		/*if (VerifierSaveLoad(filename, ligne_de_commande_restante, flux_commande))
		{
			//Savegarder l'ancien modèle -> on appelle save.
			fichierUI->Sauvegarder_modele("modele");
			fichierUI->Charger_modele(filename);
			//Créer instance de CmdSequence.
		}
		return true ;*/
		return 0 ;
	}
	else if(premier_argument == "CLEAR")
	{
		//Créer instance de CmdSequence.
		return 0 ;
	}

	else	//Création d'un objet ou objet agrégé.
	{
		cout << "Appel de CmdAjouterElement depuis Traduire." << endl ;
		Commande * Nouvelle_commande = new CmdAjouterElement(modele) ;
		if(Nouvelle_commande->Initialisation(instruction) && Nouvelle_commande->Faire())
		{
			return Nouvelle_commande ;
		}
		else
		{
			return 0 ;
		}
	}
}


bool Controleur::Executer_instruction(string instruction)
// Algorithme :
//
{
	instruction_cours = instruction ;	//Pour l'appel de SAVE/LOAD
	premier_argument = "pas_trouve" ;
	istringstream flux_commande (instruction_cours) ;
	string premier ;
	getline(flux_commande , premier , ' ');
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
		cout << "\"" << premier << "\"" << " n'est pas une commande valide" << endl ;
		return true ;
	}
	else if(premier_argument == "SAVE")
	{
		string filename;
		string ligne_de_commande_restante ;

		if (VerifierSaveLoad(filename, ligne_de_commande_restante, flux_commande))
		{
			fichierUI->Sauvegarder_modele(filename);
		}
		return true ;

	}

	else if(premier_argument == "EXIT")
	{
		//demande si l'utilisateur veut enregistrer sa figure
		//Verif si la dernière commande était une sauvegarde
		/*if (liste_cmd.top() != ##sauvegarde)
		{*/
			cout << "Passage dans exit\n" ;
			bool reponse_pas_bonne = true ;
			while(reponse_pas_bonne == true)
			{
				string reponse_question ;
				cout << "Voulez-vous sauvegarder votre travail avant de quitter ? (y/yes ; n/no) :" ;
				getline(cin,reponse_question);
				if (reponse_question == "y" || reponse_question == "yes" || reponse_question == "Yes" || reponse_question == "Y")
				{
					cout << "Yes ! " << endl ;
					reponse_pas_bonne = false ;
					string filename;
					cout << "Veuillez rentrer le nom de votre sauvegarde." << endl ;
					getline(cin , filename);
					fichierUI->Sauvegarder_modele(filename);
				}
				else if (reponse_question == "n" || reponse_question == "no" || reponse_question == "No" || reponse_question == "N")
				{
					reponse_pas_bonne = false ;
				}
				else
				{
					cout << "\"" << reponse_question << "\" n'est pas une réponse valide, veuillez répondre à nouveau." << endl ;
				}
			}

		return false;
	}
	else if(premier_argument == "REDO")
	{
		//Appel de faire de l'avant dernière commande de la pile.
		return true ;
	}
	else if(premier_argument == "UNDO")
	{
		//Appel de defaire de la dernière commande de la pile.
		return true ;
	}
	else
	{
		/*Appel de la fonction traduire.*/
		//liste_cmd.push_back( ) ;
		Commande * retour = Traduire_instruction(instruction) ;
		if(retour != 0)
		{
			//La commande s'est exécutée correctement, on l'ajoute dans le pile.
			liste_cmd.push_back(retour);
		}
		premier_argument = "pas_trouve"; //Pour le prochain appel
		return true ;
	}

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
	console = new ConsoleUI(modele , this) ;
	modele = new Modele() ;
	fichierUI = new FichierUI( this , modele ) ;
#ifdef MAP
    cout << "Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur ( )
// Algorithme :
//
{
	cout << "A bientôt ! " << endl ;
	delete console ;
	delete fichierUI ;
#ifdef MAP
    cout << "Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

