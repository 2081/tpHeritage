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

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

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


//------------------------------------------------- Surcharge d'opérateurs
    ConsoleUI & operator = ( const ConsoleUI & unConsoleUI );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ConsoleUI ( const ConsoleUI & unConsoleUI );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ConsoleUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ConsoleUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <ConsoleUI>

#endif // CONSOLEUI_H_

