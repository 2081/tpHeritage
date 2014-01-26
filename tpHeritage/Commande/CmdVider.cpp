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
	for(unsigned int i = 0; i < elements_enleves.size(); i++){
		if(!modele->Enlever_element(elements_enleves[i])){
			for(unsigned int j = i; j > 0; j--){
				modele->Ajouter_element(elements_enleves[j-1]);
			}
			return false;
		}
	}
	return true ;
}


bool CmdVider::Defaire()
{
	for(unsigned int i = 0; i < elements_enleves.size(); i++){
		if(!modele->Ajouter_element(elements_enleves[i])){
			for(unsigned int j = i; j > 0; j--){
				modele->Enlever_element(elements_enleves[j-1]);
			}
			return false;
		}
	}
	return true ;
}


bool CmdVider::Initialisation( string instruction )
{
	map<string,ElementGeo * >::iterator it = modele->elements.begin();
	while(it != modele->elements.end()){
		elements_enleves.push_back(it->second);
		it++;
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

