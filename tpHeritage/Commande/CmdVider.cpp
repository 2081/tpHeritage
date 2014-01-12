/*************************************************************************
                           CmdVider  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdVider> (fichier CmdVider.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdVider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdVider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*CmdVider & CmdVider::operator = ( const CmdVider & unCmdVider )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdVider::CmdVider ( const CmdVider & unCmdVider )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdVider>" << endl;
#endif
} //----- Fin de CmdVider (constructeur de copie)


CmdVider::CmdVider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdVider>" << endl;
#endif
} //----- Fin de CmdVider


CmdVider::~CmdVider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdVider>" << endl;
#endif
} //----- Fin de ~CmdVider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

