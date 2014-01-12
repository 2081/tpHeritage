/*************************************************************************
                           Groupe  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Groupe> (fichier Groupe.h) ------
#if ! defined ( GROUPE_H_ )
#define GROUPE_H_

//--------------------------------------------------- Interfaces utilisées
#include "ElementGeo.h"


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Groupe>
//
//
//------------------------------------------------------------------------ 

class Groupe : public ElementGeo
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
    Groupe & operator = ( const Groupe & unGroupe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Groupe ( const Groupe & unGroupe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Groupe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Groupe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Groupe>

#endif // GROUPE_H_

