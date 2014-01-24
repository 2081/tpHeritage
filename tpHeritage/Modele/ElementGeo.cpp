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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ElementGeo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool ElementGeo::Ajouter_au_groupe( Groupe * groupe)
{
	return true ;
}

bool ElementGeo::Enlever_du_groupe( Groupe * groupe)
{
	return true ;
}

bool ElementGeo::Deplacer(int dx, int dy, int id)
{
	if(id == this->dernier_deplacement){
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
	nom = fnom ;
	dependance = 0 ;
#ifdef MAP
    cout << "Appel au constructeur de <ElementGeo>" << endl;
#endif
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

