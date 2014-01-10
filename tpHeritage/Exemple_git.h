/*************************************************************************
                           Exemple_git  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Exemple_git> (fichier Exemple_git.h) ------
#if ! defined ( EXEMPLE_GIT_H_ )
#define EXEMPLE_GIT_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Exemple_git>
//
//
//------------------------------------------------------------------------ 

class Exemple_git
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
    Exemple_git & operator = ( const Exemple_git & unExemple_git );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Exemple_git ( const Exemple_git & unExemple_git );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Exemple_git ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Exemple_git ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Exemple_git>

#endif // EXEMPLE_GIT_H_

