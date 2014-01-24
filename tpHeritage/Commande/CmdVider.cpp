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

bool CmdVider::Faire()
{
	modele->elements.clear();
	return true ;
}


bool CmdVider::Defaire()
{
	//Réajout des éléments anciennement supprimés au modèle.
	for (Elements_cleared::iterator it=elements_cleared.begin() ; it != elements_cleared.end() ; it++)
	{
		modele->elements.insert(pair<string,ElementGeo *>((*it)->nom , *it));
	}
	return true ;
}


bool CmdVider::Initialisation( string instruction )
{
	for (Elements::iterator it = modele->elements.begin() ; it != modele->elements.end() ; it++)
	{
		elements_cleared.push_back(it->second);
	}
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

