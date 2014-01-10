/*************************************************************************
                           Exemple_git  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Exemple_git> (fichier Exemple_git.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Exemple_git.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Exemple_git::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Exemple_git & Exemple_git::operator = ( const Exemple_git & unExemple_git )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Exemple_git::Exemple_git ( const Exemple_git & unExemple_git )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Exemple_git>" << endl;
#endif
} //----- Fin de Exemple_git (constructeur de copie)


Exemple_git::Exemple_git ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Exemple_git>" << endl;
#endif
} //----- Fin de Exemple_git


Exemple_git::~Exemple_git ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Exemple_git>" << endl;
#endif
} //----- Fin de ~Exemple_git


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

