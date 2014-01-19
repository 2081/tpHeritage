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

bool Faire()
{
	return true ;
}


bool Defaire()
{
	return true ;
}


bool Initialisation( string instruction )
{
	return true ;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
CmdVider::CmdVider ( Modele * fmodele ) : Commande(fmodele)
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

