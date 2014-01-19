/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Cercle> (fichier Cercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream> //ostringstream

//------------------------------------------------------ Include personnel
#include "Cercle.h"
#include "Point.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cercle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Cercle::Obtenir_descripteur()
{
	string a_retourner ;
	ostringstream flux(ostringstream::ate);
	flux << "C " << nom << " " << centre->x << " " << centre->y << " " << rayon ;
	a_retourner = flux.str();
	return a_retourner ;
}

bool Cercle::Deplacer(int dx, int dy, int id )
{
	return true ;
}


//------------------------------------------------- Surcharge d'opérateurs
/*Cercle & Cercle::operator = ( const Cercle & unCercle )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Cercle::Cercle ( const Cercle & unCercle )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cercle>" << endl;
#endif
} //----- Fin de Cercle (constructeur de copie)
*/

Cercle::Cercle (string & fnom, Point* c, int r) : ElementGeo(fnom)
// Algorithme :
//
{
	centre = c ;
	rayon = r ;
#ifdef MAP
    cout << "Appel au constructeur de <Cercle>" << endl;
#endif
} //----- Fin de Cercle


Cercle::~Cercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cercle>" << endl;
#endif
} //----- Fin de ~Cercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

