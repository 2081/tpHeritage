/*************************************************************************
                           CmdSequence  -  description
                             -------------------
    début                : 17 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <CmdSequence> (fichier CmdSequence.h) ------
#if ! defined ( CMDSEQUENCE_H_ )
#define CMDSEQUENCE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "../Modele/Modele.h"
using namespace std ;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef deque<Commande *> Commandes ;

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdSequence>
//
//
//------------------------------------------------------------------------ 

class CmdSequence : public Commande
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

	bool Defaire();

	bool Initialisation(string instruction);


//------------------------------------------------- Surcharge d'opérateurs
    CmdSequence & operator = ( const CmdSequence & unCmdSequence );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CmdSequence ( Modele * modele);
	// Mode d'emploi :
	//
	// Contrat :
	//

    CmdSequence ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdSequence ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Commandes cmds ;

};

//--------------------------- Autres définitions dépendantes de <CmdSequence>

#endif // CMDSEQUENCE_H_

