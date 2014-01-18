/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <PolyLigne> (fichier PolyLigne.h) ------
#if ! defined ( POLYLIGNE_H_ )
#define POLYLIGNE_H_

//--------------------------------------------------- Interfaces utilisées
#include "ElementGeo.h"
#include "Point.h"
#include <vector>


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <PolyLigne>
//
//
//------------------------------------------------------------------------ 

class PolyLigne : public ElementGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool Deplacer(int dx, int dy, int id = 0);

//------------------------------------------------- Surcharge d'opérateurs
    PolyLigne & operator = ( const PolyLigne & unPolyLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PolyLigne ( const PolyLigne & unPolyLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PolyLigne (string & fnom, vector<Point> & p);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PolyLigne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    vector<Point> coord;
};

//--------------------------- Autres définitions dépendantes de <PolyLigne>

#endif // POLYLIGNE_H_

