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

void Controleur::Demarrer()
{
	console->Attendre_instruction();
}

bool Controleur::VerifierSaveLoad(string& filename)
{
	//cerr << "VerifierSaveLoad"<<endl;
	//if(tab_instruction.size()>2) return false ;
	//cerr << "VerifierSaveLoad - 2"<<endl;
	//filename = tab_instruction[1] ;
	return true ;
}

Commande * Controleur::Traduire_instruction(string instruction) // Pas de Faire() ici
{
	/*Traduction de soit : "C","R","L","PL","OA","DELETE","MOVE",
	"LIST"*/
	cout << "# Appel de traduction : "<<instruction << endl ;

	vector<string> donnees;
	Commande::Decouper(instruction,donnees);

	Commande * renvoi = 0;

	if (donnees[0] == "DELETE")
	{
		renvoi = new CmdSupprimer(modele) ;

	} else if(donnees[0] == "MOVE")
	{
		renvoi = new CmdDeplacer(modele) ;

	}
	else if(donnees[0] == "CLEAR")
	{
		renvoi = new CmdVider(modele);
	}
	else if(donnees[0] == "LOAD")
	{
		if(donnees.size()==2){
			string filename = donnees[1];
			if (VerifierSaveLoad(filename))
			{
				//cout << "appel de charger" << endl ;
				renvoi = fichierUI->Charger_modele(filename) ;
			}
		}
	}
	else if(donnees[0] == "OA")
	{
		renvoi = new CmdGrouper(modele);
	}
	else	//Création d'un objet ou objet agrégé.
	{
		cout << "# Appel de CmdAjouterElement depuis Traduire." << endl ;
		renvoi = new CmdAjouterElement(modele) ;
	}
	if((renvoi!=0)&&!(renvoi->Initialisation(instruction))){
		cout << "# Initialisation echouee."<< endl;
		delete renvoi;	//Le programme bugue à cet endroit.
		renvoi = 0;
	} else {
		//cout << "Initialisation ok" << endl;
	}
	return renvoi;
}


bool Controleur::Executer_instruction(string instruction) // retourne toujours true, sauf si EXIT
// Algorithme :
//
{
	vector<string> donnees;
	Commande::Decouper(instruction,donnees);

	//premier_argument = "pas_trouve" ;
	/**
	tab_instruction.clear();
	istringstream flux_commande(instruction);
	istream_iterator<string> begin(flux_commande), end;
	tab_instruction = vector<string>(begin, end);*/


	string premier = donnees[0];
	//Recherche dans la liste de commandes attendues.

	//string * pt = liste_commandes;

	/*while( pt != liste_commandes+14)
	{
		if(*pt == premier && donnees[0]=="pas_trouve")
		{
			donnees[0] = *pt ;
			pt = liste_commandes+14;
		}
		else pt++;
	}*/
	bool instruction_connue = false;
	for(int i = 0; i < 14; i++){
		if(liste_commandes[i] == donnees[0]){
			instruction_connue = true;
			i = 14;
		}
	}


	//Analyse du résultat et appel des procédures de commandes.
	if(!instruction_connue)
	{
		cout << "# \"" << donnees[0] << "\"" << " n'est pas une commande valide" << endl ;
		//return true ;
	}
	else if(donnees[0] == "SAVE")
	{
		string filename;
		if (VerifierSaveLoad(filename))
		{
			// && !modele->elements.empty()
			fichierUI->Sauvegarder_modele(filename);
		}
		//return true ;

	}

	else if(donnees[0] == "LIST")
	{
		console->Lister_modele();
		//return true ;
		//Créer instance de CmdSequence.
	}
	else if(donnees[0] == "EXIT")
	{
		return false;
	}
	else if(donnees[0] == "REDO")
	{
		//cout << "redo" ;
		if(curseur_cmd != liste_cmd.end()){
			(*curseur_cmd)->Faire();
			curseur_cmd++ ;
		}
		//Appel de faire de l'avant dernière commande de la pile.
		//return true ;
	}
	else if(donnees[0] == "UNDO")
	{
		if(curseur_cmd != liste_cmd.begin()){
			curseur_cmd-- ;
			(*curseur_cmd)->Defaire();
		}
		//Appel de defaire de la dernière commande de la pile.
		//return true ;
	}
	else
	{
		/*Appel de la fonction traduire.*/
		//liste_cmd.push_back( ) ;
		Commande * retour = Traduire_instruction(instruction) ;
		if(retour != 0)
		{
			if(retour->Faire()){
				if(liste_cmd.size()>0 && curseur_cmd != liste_cmd.end()){
					Pile_Commande::iterator curseur_cmd2;
					do {
						curseur_cmd2 = liste_cmd.end();
						curseur_cmd2--;
						delete (*curseur_cmd2);
						liste_cmd.pop_back();

					} while(curseur_cmd2 != curseur_cmd); // On supprime aussi curseur_cmd
				}
				liste_cmd.push_back(retour);
				curseur_cmd = liste_cmd.end();
				cout << "OK" << endl;
			} else {
				//cout << "Faire erreur"<< endl;
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
	this->curseur_cmd = this->liste_cmd.end();
#ifdef MAP
    cout << "# Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur ( )
// Algorithme :
//
{
	delete console ;
	delete fichierUI ;
#ifdef MAP
    cout << "# Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

