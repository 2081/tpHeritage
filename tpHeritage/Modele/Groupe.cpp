/*************************************************************************
                           Groupe  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Groupe> (fichier Groupe.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <iterator>

//------------------------------------------------------ Include personnel
#include "Groupe.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Groupe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Groupe::Calculer_dependance()
{
	/*Fonction appelée si on supprime un element d'un objet agrégé.
	 * Si cet élément était responsable de la dépendance de l'OA,
	 *  alors celui-ci a peut-être maintenant une dépendance diminuée, */
	int max_dep_membres = 0 ;
	for(Elements_groupe::iterator it = membres.begin() ; it!=membres.end() ; it++)
	{
		if((*it)->dependance > max_dep_membres) max_dep_membres = (*it)->dependance ;
	}
	if(max_dep_membres<dependance)
	{
		dependance = max_dep_membres;
		return true;
	}
	return false;
}

string Groupe::Obtenir_descripteur()
{
	string a_retourner ;
	ostringstream flux(ostringstream::ate);
	flux << "OA " << nom << " " ;
	for (deque<ElementGeo *>::iterator it = membres.begin() ; it != membres.end() ; it++)
	{
		flux << (*it)->nom << " " ;
	}
	a_retourner = flux.str();
	return a_retourner ;
}

bool Groupe::Deplacer(int dx, int dy, int id)
{
	return true ;
}

bool Groupe::Ajouter_membre(ElementGeo * elt)
{
	if(elt != this){
		if(elt->dependance >= dependance) dependance = elt->dependance +1 ;
		membres.push_back(elt) ;
		elt->groupes.push_back(this) ;
		return true ;
	}
	else return false;
}

bool Groupe::Enlever_membre(ElementGeo * elt)
{
	//chercher l'element et l'enlever
	deque<ElementGeo*>::iterator it ;
	for(it = membres.begin() ; it != membres.end() ; it++)
	{
		if(*it == elt)
		{
			membres.erase(it) ;
			if (Calculer_dependance()){
				//Appel récursif si cet objet agrégé est lui même membre d'un autre.
				for(Groupes::iterator it = groupes.begin() ; it != groupes.end() ; it++)
				{
					(*it)->Calculer_dependance() ;
				}
			}
			return true ;
		}
	}
	return false ;

}

//------------------------------------------------- Surcharge d'opérateurs
/*Groupe & Groupe::operator = ( const Groupe & unGroupe )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Groupe::Groupe ( const Groupe & unGroupe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Groupe>" << endl;
#endif
} //----- Fin de Groupe (constructeur de copie)
*/

Groupe::Groupe (string & fnom) : ElementGeo(fnom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Groupe>" << endl;
#endif
} //----- Fin de Groupe


Groupe::~Groupe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Groupe>" << endl;
#endif
} //----- Fin de ~Groupe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

