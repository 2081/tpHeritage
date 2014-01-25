/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Modele> (fichier Modele.h) ------
#if ! defined ( MODELE_H_ )
#define MODELE_H_

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <limits>
#include "ElementGeo.h"

//------------------------------------------------------------- Constantes 
const long int BORD_DROIT = std::numeric_limits<long int>::max();
const long int BORD_HAUT = std::numeric_limits<long int>::max();
const long int BORD_GAUCHE = std::numeric_limits<long int>::min();
const long int BORD_BAS = std::numeric_limits<long int>::min();

//------------------------------------------------------------------ Types 
typedef map <string , ElementGeo*> Elements ;

//------------------------------------------------------------------------ 
// Rôle de la classe <Modele>
//
//
//------------------------------------------------------------------------ 

class Modele
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	bool Ajouter_element( ElementGeo *);

	bool Enlever_element( ElementGeo *);

	ElementGeo * Element_par_nom( string nom);


//------------------------------------------------- Surcharge d'opérateurs
    Modele & operator = ( const Modele & unModele );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Modele ( const Modele & unModele );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Elements elements ;

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Modele>

#endif // MODELE_H_

