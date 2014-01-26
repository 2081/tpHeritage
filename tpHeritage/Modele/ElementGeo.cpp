/*************************************************************************
                           ElementGeo  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <ElementGeo> (fichier ElementGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ElementGeo.h"
#include "Groupe.h"

//------------------------------------------------------------- Constantes
int ElementGeo::prochain_id_deplacement = 0;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ElementGeo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool ElementGeo::Ajouter_au_groupe( Groupe * groupe)
{
	for(Groupes::iterator it = groupes.begin(); it != groupes.end(); it++){
			if( *it == groupe){
				return false;
			}
		}
	groupes.push_back(groupe);
	return true ;
}

bool ElementGeo::Enlever_du_groupe( Groupe * groupe)
{
	for(Groupes::iterator it = groupes.begin(); it != groupes.end(); it++){
		if( *it == groupe){
			groupes.erase(it);
			return true;
		}
	}
	return false ;
}

bool ElementGeo::Deplacer(long int dx, long int dy, int id)
{
	if(id != -1 && id == this->dernier_deplacement){
		return false;
	} else {
		this->dernier_deplacement = id;
		return true;
	}
}


//------------------------------------------------- Surcharge d'opérateurs
/*ElementGeo & ElementGeo::operator = ( const ElementGeo & unElementGeo )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*ElementGeo::ElementGeo ( const ElementGeo & unElementGeo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ElementGeo>" << endl;
#endif
} //----- Fin de ElementGeo (constructeur de copie)
*/

ElementGeo::ElementGeo ( string fnom )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ElementGeo>" << endl;
#endif
	nom = fnom ;
	dependance = 0 ;
	dernier_deplacement = -1;
} //----- Fin de ElementGeo (constructeur de copie)


ElementGeo::~ElementGeo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ElementGeo>" << endl;
#endif
} //----- Fin de ~ElementGeo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

