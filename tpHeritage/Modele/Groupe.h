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
#include <list>


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
	bool Ajouter_membre( ElementGeo * elt);
	bool Enlever_membre( ElementGeo * elt);

	bool Deplacer(int dx, int dy, int id = 0);

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

    Groupe ( string & nom );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Groupe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    list<ElementGeo *> membres;

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Groupe>

#endif // GROUPE_H_

