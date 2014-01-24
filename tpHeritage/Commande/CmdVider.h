/*************************************************************************
                           CmdVider  -  description
                             -------------------
    début                : 12 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdVider> (fichier CmdVider.h) ------
#if ! defined ( CMDVIDER_H_ )
#define CMDVIDER_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef vector<ElementGeo*> Elements_cleared ;
//------------------------------------------------------------------------ 
// Rôle de la classe <CmdVider>
//
//
//------------------------------------------------------------------------ 

class CmdVider : public Commande
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

//-------------------------------------------- Constructeurs - destructeur
    CmdVider ( Modele * fmodele );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdVider ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Elements_cleared elements_cleared ;

};

//--------------------------- Autres définitions dépendantes de <CmdVider>

#endif // CMDVIDER_H_

