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


//------------------------------------------------- Surcharge d'opérateurs
/*Groupe & Groupe::operator = ( const Groupe & unGroupe )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Groupe::Groupe ( const Groupe & unGroupe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Groupe>" << endl;
#endif
} //----- Fin de Groupe (constructeur de copie)


Groupe::Groupe ( )
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

