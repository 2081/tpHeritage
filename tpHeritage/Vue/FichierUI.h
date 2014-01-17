/*************************************************************************
                           FichierUI  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <FichierUI> (fichier FichierUI.h) ------
#if ! defined ( FICHIERUI_H_ )
#define FICHIERUI_H_

//--------------------------------------------------- Interfaces utilisées
#include "../Controleur/Controleur.h"
#include "../Modele/Modele.h"

#include <string>
#include <vector>
using namespace std ;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef vector<string> Commandes_objet ;
typedef vector<Commandes_objet> Situation_modele ;
class Controleur ;

//------------------------------------------------------------------------ 
// Rôle de la classe <FichierUI>
//
//
//------------------------------------------------------------------------ 

class FichierUI
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool Sauvegarder_modele(string nom_fichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool Charger_modele(string nom_fichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
    /*FichierUI & operator = ( const FichierUI & unFichierUI );
    // Mode d'emploi :
    //
    // Contrat :
    //
*/

//-------------------------------------------- Constructeurs - destructeur
    FichierUI ( const FichierUI & unFichierUI );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FichierUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FichierUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Controleur* controleur ;
    Modele* modele ;
    Situation_modele situation_modele ;

};

//--------------------------- Autres définitions dépendantes de <FichierUI>

#endif // FICHIERUI_H_

