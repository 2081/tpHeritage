/*************************************************************************
                           CmdSupprimer  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdSupprimer> (fichier CmdSupprimer.h) ------
#if ! defined ( CMDSUPPRIMER_H_ )
#define CMDSUPPRIMER_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdSupprimer>
//
//
//------------------------------------------------------------------------ 

class CmdSupprimer : public Commande
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
    CmdSupprimer & operator = ( const CmdSupprimer & unCmdSupprimer );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdSupprimer ( const CmdSupprimer & unCmdSupprimer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdSupprimer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdSupprimer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CmdSupprimer>

#endif // CMDSUPPRIMER_H_

