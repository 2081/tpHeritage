/*************************************************************************
                           Groupe  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Groupe> (fichier Groupe.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <iterator>

//------------------------------------------------------ Include personnel
#include "Groupe.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Groupe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Groupe::Obtenir_descripteur()
{
	string a_retourner ;
	ostringstream flux(ostringstream::ate);
	flux << "OA " << nom << " " ;
	for (deque<ElementGeo *>::iterator it = membres.begin() ; it != membres.end() ; it++)
	{
		//flux << it->nom << " " ;
	}
	a_retourner = flux.str();
	return a_retourner ;
}

bool Groupe::Deplacer(int dx, int dy, int id)
{
	return true ;
}

bool Groupe::Ajouter_membre(ElementGeo * elt)
{
	membres.push_back(elt) ;
	return true ;
}

bool Groupe::Enlever_membre(ElementGeo * elt)
{
	//chercher l'element et l'enlever
	deque<ElementGeo*>::iterator it ;
	for(it = membres.begin() ; it != membres.end() ; it++)
	{
		if(*it == elt)
		{
			membres.erase(it) ;
			return true ;
		}
	}
	return false ;

}

//------------------------------------------------- Surcharge d'opérateurs
/*Groupe & Groupe::operator = ( const Groupe & unGroupe )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Groupe::Groupe ( const Groupe & unGroupe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Groupe>" << endl;
#endif
} //----- Fin de Groupe (constructeur de copie)
*/

Groupe::Groupe (string & fnom) : ElementGeo(fnom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Groupe>" << endl;
#endif
} //----- Fin de Groupe


Groupe::~Groupe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Groupe>" << endl;
#endif
} //----- Fin de ~Groupe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

