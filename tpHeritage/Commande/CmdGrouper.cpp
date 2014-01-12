/*************************************************************************
                           CmdGrouper  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdGrouper> (fichier CmdGrouper.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdGrouper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdGrouper::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*CmdGrouper & CmdGrouper::operator = ( const CmdGrouper & unCmdGrouper )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdGrouper::CmdGrouper ( const CmdGrouper & unCmdGrouper )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdGrouper>" << endl;
#endif
} //----- Fin de CmdGrouper (constructeur de copie)


CmdGrouper::CmdGrouper ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdGrouper>" << endl;
#endif
} //----- Fin de CmdGrouper


CmdGrouper::~CmdGrouper ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdGrouper>" << endl;
#endif
} //----- Fin de ~CmdGrouper


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

