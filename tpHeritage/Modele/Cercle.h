/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H_ )
#define CERCLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "ElementGeo.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
class Point ;

//------------------------------------------------------------------------ 
// Rôle de la classe <Cercle>
//
//
//------------------------------------------------------------------------ 

class Cercle : public ElementGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	string Obtenir_descripteur() ;

	bool Deplacer(long int dx, long int dy, int id = -1);

//------------------------------------------------- Surcharge d'opérateurs
    Cercle & operator = ( const Cercle & unCercle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cercle ( const Cercle & unCercle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cercle ( string & nom, Point* centre, long int rayon);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cercle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point* centre;
    long int rayon;

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_

