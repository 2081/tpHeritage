/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ------
#if ! defined ( CONTROLEUR_H_ )
#define CONTROLEUR_H_

//--------------------------------------------------- Interfaces utilisées
#include <stack> //Pile
#include <string>



using namespace std ;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class Commande ;
class ConsoleUI ;
class Modele ;
class FichierUI ;
typedef deque <Commande*> Pile_Commande;
//------------------------------------------------------------------------ 
// Rôle de la classe <Controleur>
//
//
//------------------------------------------------------------------------ 

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	void Lancer_console() ;

	bool VerifierSaveLoad(string& filename, string& ligne_de_commande_restante, istringstream& flux_commande);
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Commande * Traduire_instruction(string instruction);
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool Executer_instruction(string instruction);
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
//    Controleur & operator = ( const Controleur & unControleur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Modele modele;
    FichierUI* fichierUI;
    ConsoleUI* console ;
    string liste_commandes[14] = {"C","R","L","PL","OA","DELETE","MOVE",
    			   		"LIST","UNDO","REDO","LOAD","SAVE","CLEAR","EXIT"};
    //rajouter -std=c++11 aux options de compilation si problème pour l'attribut liste_commandes
    string*pt ;		//Pointeur de recherche dans liste_commandes.
    string premier_argument = "pas_trouve";

    Pile_Commande liste_cmd ;
    //Pile_Commande liste_construction ;
    string instruction_cours ;
    //liste_cmd::iterator curseur_commandes=liste_cmd.size();
    //curseur sur une stack ?

};

//--------------------------- Autres définitions dépendantes de <Controleur>

#endif // CONTROLEUR_H_

