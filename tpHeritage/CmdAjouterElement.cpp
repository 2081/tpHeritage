/*************************************************************************
                           CmdAjouterElement  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdAjouterElement> (fichier CmdAjouterElement.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjouterElement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterElement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
CmdAjouterElement & CmdAjouterElement::operator = ( const CmdAjouterElement & unCmdAjouterElement )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CmdAjouterElement::CmdAjouterElement ( const CmdAjouterElement & unCmdAjouterElement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjouterElement>" << endl;
#endif
} //----- Fin de CmdAjouterElement (constructeur de copie)


CmdAjouterElement::CmdAjouterElement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterElement>" << endl;
#endif
} //----- Fin de CmdAjouterElement


CmdAjouterElement::~CmdAjouterElement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterElement>" << endl;
#endif
} //----- Fin de ~CmdAjouterElement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

