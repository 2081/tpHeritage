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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ElementGeo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool ElementGeo::Deplacer(int dx, int dy, int id = 0)
{
	if(id == 0 || id != dernier_deplacement){
		dernier_deplacement = id;
		return true;
	}
	return false;
}

//------------------------------------------------- Surcharge d'opérateurs
/*ElementGeo & ElementGeo::operator = ( const ElementGeo & unElementGeo )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
ElementGeo::ElementGeo ( const ElementGeo & unElementGeo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ElementGeo>" << endl;
#endif
} //----- Fin de ElementGeo (constructeur de copie)


ElementGeo::ElementGeo ( string fnom) : nom(fnom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ElementGeo>" << endl;
#endif
    this->dependance = 0;
    this->dernier_deplacement = 0;
} //----- Fin de ElementGeo


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

