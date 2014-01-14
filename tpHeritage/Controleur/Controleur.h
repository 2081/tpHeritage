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
#include <list>
#include <string>


#include "../Vue/ConsoleUI.h"	//Vue
#include "../Vue/FichierUI.h"	//Vue
#include "../Commande/Commande.h" //Commande
#include "../Modele/Modele.h"	//Modele

using namespace std ;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef stack <Commande*> Pile_Commande;
class ConsoleUI ;
class Modele ;

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
    Controleur ( const Controleur & unControleur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

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
    FichierUI fichier;
    ConsoleUI* console ;
    string liste_commandes[14] = {"C","R","L","PL","OA","DELETE","MOVE",
    			   		"LIST","UNDO","REDO","LOAD","SAVE","CLEAR","EXIT"};
    //rajouter -std=c++11 aux options de compilation si problème pour l'attribut liste_commandes
    string*pt ;		//Pointeur de recherche dans liste_commandes.
    string premier_argument = "pas_trouve";

    Pile_Commande commandes_executees ;
    //commandes_executees::iterator curseur_commandes=commandes_executees.size();
    //curseur sur une stack ?

};

//--------------------------- Autres définitions dépendantes de <Controleur>

#endif // CONTROLEUR_H_

