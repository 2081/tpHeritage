/*************************************************************************
                           ElementGeo  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <ElementGeo> (fichier ElementGeo.h) ------
#if ! defined ( ELEMENTGEO_H_ )
#define ELEMENTGEO_H_

#include <string>
#include <vector>
//#include "Groupe.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class Groupe ;
typedef vector<Groupe *> Groupes ;


//------------------------------------------------------------------------ 
// Rôle de la classe <ElementGeo>
//
//
//------------------------------------------------------------------------ 

class ElementGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	virtual bool Deplacer(long int dx, long int dy, int id = -1) = 0;
	// Mode d'emploi :
	//
	// Contrat : Les méthodes filles doivent vérifier si elles sont hors limite !
	//

	bool Ajouter_au_groupe( Groupe * groupe);
	bool Enlever_du_groupe( Groupe * groupe);

	virtual string Obtenir_descripteur() = 0;


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

    ElementGeo (string nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ElementGeo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


    int dependance;
	string nom;
	Groupes groupes;

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    static int prochain_id_deplacement;

private:
    int dernier_deplacement;

};

//--------------------------- Autres définitions dépendantes de <ElementGeo>

#endif // ELEMENTGEO_H_

