/*************************************************************************
                           CmdAjouterElement  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdAjouterElement> (fichier CmdAjouterElement.h) ------
#if ! defined ( CMDAJOUTERELEMENT_H_ )
#define CMDAJOUTERELEMENT_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdAjouterElement>
//
//
//------------------------------------------------------------------------ 

class CmdAjouterElement : public Ancetre
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
    CmdAjouterElement & operator = ( const CmdAjouterElement & unCmdAjouterElement );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdAjouterElement ( const CmdAjouterElement & unCmdAjouterElement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CmdAjouterElement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjouterElement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CmdAjouterElement>

#endif // CMDAJOUTERELEMENT_H_
