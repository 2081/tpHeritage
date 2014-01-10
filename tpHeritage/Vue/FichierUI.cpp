/*************************************************************************
                           FichierUI  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <FichierUI> (fichier FichierUI.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "FichierUI.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FichierUI::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
FichierUI & FichierUI::operator = ( const FichierUI & unFichierUI )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FichierUI::FichierUI ( const FichierUI & unFichierUI )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FichierUI>" << endl;
#endif
} //----- Fin de FichierUI (constructeur de copie)


FichierUI::FichierUI ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FichierUI>" << endl;
#endif
} //----- Fin de FichierUI


FichierUI::~FichierUI ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FichierUI>" << endl;
#endif
} //----- Fin de ~FichierUI


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

