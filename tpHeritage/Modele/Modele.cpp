/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Modele.h"
#include "ElementGeo.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Modele::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Ajouter_element( ElementGeo * element)
{
	return true ;
}

bool Enlever_element( ElementGeo * element)
{
	return true ;
}

ElementGeo * Element_par_nom( string nom)
{

}


//------------------------------------------------- Surcharge d'opérateurs
/*Modele & Modele::operator = ( const Modele & unModele )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Modele::Modele ( const Modele & unModele )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Modele>" << endl;
#endif
} //----- Fin de Modele (constructeur de copie)


Modele::Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

