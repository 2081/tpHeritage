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
#include "Modele.h"
#include "../Commande/Commande.h"


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

bool Cercle::Deplacer(long int dx, long int dy, int id )
{
	cout << "BORD_GAUCHE : > -1 : " << BORD_GAUCHE << endl ;
	cout << "Ajout pour bord gauche : " << centre->x << endl ;
	cout << "BORD_GAUCHE : > -1 : " << BORD_GAUCHE + abs(centre->x - rayon + dx) << endl ;
	cout << "BORD_BAS : > -1 : " << BORD_BAS + abs(centre->y - rayon + dy) << endl ;
	cout << "BORD_DROIT : < -1 : " << BORD_DROIT - abs(centre->x + rayon + dx) << endl ;
	cout << "BORD_HAUT : < -1 : " <<  BORD_HAUT - abs(centre->y + rayon + dy) << endl ;

	/*cout << "BORD_GAUCHE : > -1 : " << BORD_GAUCHE + centre->x + rayon + dx << endl ;
	cout << "BORD_BAS : > -1 : " << BORD_BAS + centre->y + rayon + dy << endl ;
	cout << "BORD_DROIT : < -1 : " << BORD_DROIT + centre->x - rayon + dx << endl ;
	cout << "BORD_HAUT : < -1 : " <<  BORD_HAUT + centre->y - rayon + dy << endl ;*/

	if(!ElementGeo::Deplacer(dx,dy,id))return true; // déjà déplacé
	if((dx <= 0 && BORD_GAUCHE + abs(centre->x - rayon + dx) > 0)
			||(dy <= 0 && BORD_BAS + abs(centre->y - rayon + dy) > 0)
			||(dx >= 0 && BORD_DROIT - abs(centre->x + rayon + dx) < 0)
			||(dy >= 0 && BORD_HAUT - abs(centre->y + rayon + dy) < 0)){
		cout << Commande::message[9] << endl;
		return false;
	}
	centre->x += dx;
	centre->y += dy;
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

Cercle::Cercle (string & fnom, Point* c, long int r) : ElementGeo(fnom)
// Algorithme :
//
{
	centre = c ;
	rayon = abs(r) ;
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

