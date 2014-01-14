/*************************************************************************
                           CmdDeplacer  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdDeplacer> (fichier CmdDeplacer.h) ------
#if ! defined ( CMDDEPLACER_H_ )
#define CMDDEPLACER_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "../Modele/ElementGeo.h"


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdDeplacer>
//
//
//------------------------------------------------------------------------ 

class CmdDeplacer : public Commande
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
    CmdDeplacer & operator = ( const CmdDeplacer & unCmdDeplacer );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    CmdDeplacer ( const CmdDeplacer & unCmdDeplacer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdDeplacer ( Modele * fmodele );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdDeplacer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
ElementGeo * element;
int dx, dy;
//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CmdDeplacer>

#endif // CMDDEPLACER_H_

