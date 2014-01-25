/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Ligne.h"
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Ligne::Obtenir_descripteur()
{
	string a_retourner ;
	ostringstream flux(ostringstream::ate);
	flux << "L " << nom << " " << coord[0]->x << " " << coord[0]->y << " " << coord[1]->x << " " << coord[1]->y ;
	a_retourner = flux.str();
	return a_retourner ;
}

bool Ligne::Deplacer(long int dx, long int dy, int id )
{
	if(!ElementGeo::Deplacer(dx,dy,id))return false; // déjà déplacé
	if(!coord[0]->Deplacer(dx,dy))return false;
	if(!coord[1]->Deplacer(dx,dy)){
		coord[0]->Deplacer(-dx,-dy);
		return false;
	}
	return true ;
}

//------------------------------------------------- Surcharge d'opérateurs
/*Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Ligne::Ligne ( const Ligne & unLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)
*/

Ligne::Ligne (string & fnom, Point * fp1, Point * fp2) : ElementGeo(fnom)
// Algorithme :
//
{
	coord[0] = fp1 ;
	coord[1] = fp2 ;
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

