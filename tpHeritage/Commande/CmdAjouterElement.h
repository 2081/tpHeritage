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
#include "Commande.h"



//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdAjouterElement>
//
//
//------------------------------------------------------------------------ 

class CmdAjouterElement : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool Faire();
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool Defaire();
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool Initialisation( string instruction );
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

    CmdAjouterElement (Modele * fmodele);
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
ElementGeo * element;
//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <CmdAjouterElement>

#endif // CMDAJOUTERELEMENT_H_

