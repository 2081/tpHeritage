/*************************************************************************
                           ConsoleUI  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <ConsoleUI> (fichier ConsoleUI.h) ------
#if ! defined ( CONSOLEUI_H_ )
#define CONSOLEUI_H_

//--------------------------------------------------- Interfaces utilisées
#include "../Controleur/Controleur.h"
#include "../Modele/Modele.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class Controleur ;

//------------------------------------------------------------------------ 
// Rôle de la classe <ConsoleUI>
//
//
//------------------------------------------------------------------------ 

class ConsoleUI
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Attendre_instruction() ;
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Lister_modele() ;
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
    ConsoleUI & operator = ( const ConsoleUI & unConsoleUI );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    ConsoleUI(Modele* m , Controleur* c);
    // Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

    ConsoleUI();

    virtual ~ConsoleUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Controleur * pt_controleur ;
    Modele * pt_modele ;


};

//--------------------------- Autres définitions dépendantes de <ConsoleUI>

#endif // CONSOLEUI_H_

