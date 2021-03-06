/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H_ )
#define RECTANGLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "ElementGeo.h"


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
class Point ;

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public ElementGeo
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
    Rectangle & operator = ( const Rectangle & unRectangle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Rectangle (string nom, Point * p1, Point * p2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Rectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
    Point* coord[2];
//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Rectangle>

#endif // RECTANGLE_H_

