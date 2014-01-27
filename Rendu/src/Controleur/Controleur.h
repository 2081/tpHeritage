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
#include <vector>
using namespace std ;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class Commande ;
class ConsoleUI ;
class Modele ;
class FichierUI ;
typedef deque <Commande*> Pile_Commande;
typedef deque <string> Sauvegardes ;
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
	void Save_systeme();

	void Demarrer() ;

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
    bool VerifierSaveLoad(string& filename);
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

//----------------------------------------------------- Attributs protégés
    Modele* modele;
    FichierUI* fichierUI;
    ConsoleUI* console ;
    string* pt;	//Pointeur de recherche dans liste_commandes.
    string liste_commandes[14] = {"C","R","L","PL","OA","DELETE","MOVE",
    			   		"LIST","UNDO","REDO","LOAD","SAVE","CLEAR","EXIT"};
    //rajouter -std=c++11 aux options de compilation si problème pour l'attribut liste_commandes
    string premier_argument = "pas_trouve";
    vector<string> tab_instruction ;
    Pile_Commande liste_cmd ;	//Pointeur sur la pile de Commandes.
    Pile_Commande::iterator curseur_cmd ;
    Sauvegardes sauvegardes ;


};

//--------------------------- Autres définitions dépendantes de <Controleur>

#endif // CONTROLEUR_H_

