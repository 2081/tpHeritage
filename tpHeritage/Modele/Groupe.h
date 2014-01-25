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
#include <deque>
#include "ElementGeo.h"


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef deque<ElementGeo *> Elements_groupe ;

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
	bool Calculer_dependance() ;

	string Obtenir_descripteur();

	bool Deplacer(long int dx, long int dy, int id = -1);

	bool Ajouter_membre(ElementGeo * elt);

	bool Enlever_membre(ElementGeo * elt);


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

    Groupe (string & nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Groupe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Elements_groupe membres;
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Groupe>

#endif // GROUPE_H_

