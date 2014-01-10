/*************************************************************************
                           CmdGrouper  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdGrouper> (fichier CmdGrouper.h) ------
#if ! defined ( CMDGROUPER_H_ )
#define CMDGROUPER_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdGrouper>
//
//
//------------------------------------------------------------------------ 

class CmdGrouper
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
    CmdGrouper & operator = ( const CmdGrouper & unCmdGrouper );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdGrouper ( const CmdGrouper & unCmdGrouper );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdGrouper ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdGrouper ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CmdGrouper>

#endif // CMDGROUPER_H_

