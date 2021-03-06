/*************************************************************************
                           PolyLigne  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <PolyLigne> (fichier PolyLigne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "PolyLigne.h"
#include "Point.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PolyLigne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string PolyLigne::Obtenir_descripteur()
{
	string a_retourner ;
	ostringstream flux(ostringstream::ate);
	flux << "PL " << nom << " " ;
	//coord[0]->x << " " << coord[0]->y << " " << coord[1]->x << " " << coord[1]->y ;
	for(vector<Point>::iterator it = coord.begin() ; it != coord.end() ; it++)
	{
		flux << it->x << " " << it->y << " " ;
	}
	a_retourner = flux.str();
	return a_retourner ;
}

bool PolyLigne::Deplacer(long int dx, long int dy, int id )
{
	if(!ElementGeo::Deplacer(dx,dy,id))return true; // déjà déplacé
	if(!coord[0].Deplacer(dx,dy))return false;
	for(unsigned int i = 1; i < coord.size(); i++){
		if(!coord[i].Deplacer(dx,dy)){
			for(unsigned int j = i-1; j > 0; j--){
				coord[j].Deplacer(-dx,-dy);
			}
			coord[0].Deplacer(-dx,-dy);
			return false;
		}
	}
	return true ;
}

//------------------------------------------------- Surcharge d'opérateurs
/*PolyLigne & PolyLigne::operator = ( const PolyLigne & unPolyLigne )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*PolyLigne::PolyLigne ( const PolyLigne & unPolyLigne ) : ElementGeo(fnom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PolyLigne>" << endl;
#endif
} //----- Fin de PolyLigne (constructeur de copie)
*/

PolyLigne::PolyLigne ( string & fnom, vector<Point> & fp ) : ElementGeo(fnom)
// Algorithme :
//
{
	coord = fp ;
#ifdef MAP
    cout << "Appel au constructeur de <PolyLigne>" << endl;
#endif
} //----- Fin de PolyLigne


PolyLigne::~PolyLigne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PolyLigne>" << endl;
#endif
} //----- Fin de ~PolyLigne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

