/*************************************************************************
                           CmdSequence  -  description
                             -------------------
    début                : 17 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdSequence> (fichier CmdSequence.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdSequence.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSequence::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CmdSequence & CmdSequence::operator = ( const CmdSequence & unCmdSequence )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdSequence::CmdSequence ( const CmdSequence & unCmdSequence )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdSequence>" << endl;
#endif
} //----- Fin de CmdSequence (constructeur de copie)


CmdSequence::CmdSequence ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSequence>" << endl;
#endif
} //----- Fin de CmdSequence


CmdSequence::~CmdSequence ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSequence>" << endl;
#endif
} //----- Fin de ~CmdSequence


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

