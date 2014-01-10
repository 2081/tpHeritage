/*************************************************************************
                           CmdVider.  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdVider.> (fichier CmdVider..h) ------
#if ! defined ( CMDVIDER__H_ )
#define CMDVIDER__H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdVider.>
//
//
//------------------------------------------------------------------------ 

class CmdVider
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
    CmdVider. & operator = ( const CmdVider. & unCmdVider. );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdVider. ( const CmdVider. & unCmdVider. );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdVider. ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdVider. ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CmdVider.>

#endif // CMDVIDER__H_

