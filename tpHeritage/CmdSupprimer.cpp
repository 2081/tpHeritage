/*************************************************************************
                           CmdSupprimer  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdSupprimer> (fichier CmdSupprimer.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdSupprimer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSupprimer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CmdSupprimer & CmdSupprimer::operator = ( const CmdSupprimer & unCmdSupprimer )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdSupprimer::CmdSupprimer ( const CmdSupprimer & unCmdSupprimer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdSupprimer>" << endl;
#endif
} //----- Fin de CmdSupprimer (constructeur de copie)


CmdSupprimer::CmdSupprimer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSupprimer>" << endl;
#endif
} //----- Fin de CmdSupprimer


CmdSupprimer::~CmdSupprimer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSupprimer>" << endl;
#endif
} //----- Fin de ~CmdSupprimer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

