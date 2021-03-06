/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ------
#if ! defined ( COMMANDE_H_ )
#define COMMANDE_H_

#include <string>
#include <vector>
#include "../Modele/Modele.h"

using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
class Modele ;

//------------------------------------------------------------------------ 
// Rôle de la classe <Commande>
//
//strtol end of string
//------------------------------------------------------------------------ 

class Commande
{
//----------------------------------------------------------------- PUBLIC
public:

	static const string message[];

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	static void Decouper(string & str, vector<string> & vect);
	// Mode d'emploi :
	//
	// Contrat :
	//

	static bool Est_un_nombre(string & str, long int & l);
	// Mode d'emploi :
	//
	// Contrat :
	//

	static void Message(unsigned int num);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual bool Faire() = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual bool Defaire() = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual bool Initialisation( string instruction) = 0;
	// Mode d'emploi : Renvoie false si la commande n'a pas pu etre initalisee.
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
    Commande & operator = ( const Commande & unCommande );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Commande ( Modele * fmodele );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Commande ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
Modele * modele;
static const unsigned int N_MESSAGE;
/*Message d'erreur : une initialisation en dehors de la classe est requise.*//*= {
		"# Instruction incorrecte. ",
		"# Ce nom est déjà utilisé. ",
		"# Une opération a échoué. ",
		"# Poursuite de l'opération malgré une ou plusieur erreurs. "
};*/

};

//--------------------------- Autres définitions dépendantes de <Commande>

#endif // COMMANDE_H_

