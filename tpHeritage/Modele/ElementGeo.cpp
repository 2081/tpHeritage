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


//------------------------------------------------- Surcharge d'opérateurs
ElementGeo & ElementGeo::operator = ( const ElementGeo & unElementGeo )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ElementGeo::ElementGeo ( const ElementGeo & unElementGeo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ElementGeo>" << endl;
#endif
} //----- Fin de ElementGeo (constructeur de copie)


ElementGeo::ElementGeo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ElementGeo>" << endl;
#endif
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
