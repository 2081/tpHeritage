/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"
#include "ElementGeo.h"
#include "Modele.h"
#include "../Commande/Commande.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Point::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Point::Deplacer(long int dx, long int dy )
{
	if((( Meme_signe(x,dx) && !Meme_signe(x,x+dx) )|| (Meme_signe(y,dy) && !Meme_signe(y,y+dy)))
			||(x+dx < BORD_GAUCHE || x+dx > BORD_DROIT || y+dy < BORD_BAS || y+dy > BORD_HAUT)){//Si lim long long du compil > lim long
			cout << Commande::message[9] << endl;
			return false;
	}
	this->x += dx;
	this->y += dy;
	return true ;
}

bool Point::Meme_signe(long int x1, long int x2){
	if(x1 == 0 || x2 == 0)return true;
	//cout << x1 << "," << x2 << "," << (((0 < x1) - (x1 < 0)) == ((0 < x2) - (x2 < 0))) << endl;
	return ((0 < x1) - (x1 < 0)) == ((0 < x2) - (x2 < 0));
}


//------------------------------------------------- Surcharge d'opérateurs
/*Point & Point::operator = ( const Point & unPoint )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Point::Point ( const Point & unPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)
*/

Point::Point ( long int fx, long int fy)
// Algorithme :
//
{
	x = fx ;
	y = fy ;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

