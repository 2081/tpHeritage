/*************************************************************************
                           ElementGeo  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <ElementGeo> (fichier ElementGeo.h) ------
#if ! defined ( ELEMENTGEO_H_ )
#define ELEMENTGEO_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ElementGeo>
//
//
//------------------------------------------------------------------------ 

class ElementGeo : public Ancetre
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
    ElementGeo & operator = ( const ElementGeo & unElementGeo );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ElementGeo ( const ElementGeo & unElementGeo );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ElementGeo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ElementGeo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <ElementGeo>

#endif // ELEMENTGEO_H_

