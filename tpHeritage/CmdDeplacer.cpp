/*************************************************************************
                           CmdDeplacer  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdDeplacer> (fichier CmdDeplacer.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdDeplacer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdDeplacer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CmdDeplacer & CmdDeplacer::operator = ( const CmdDeplacer & unCmdDeplacer )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdDeplacer::CmdDeplacer ( const CmdDeplacer & unCmdDeplacer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdDeplacer>" << endl;
#endif
} //----- Fin de CmdDeplacer (constructeur de copie)


CmdDeplacer::CmdDeplacer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdDeplacer>" << endl;
#endif
} //----- Fin de CmdDeplacer


CmdDeplacer::~CmdDeplacer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdDeplacer>" << endl;
#endif
} //----- Fin de ~CmdDeplacer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

