/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Modele.h"
#include "ElementGeo.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Modele::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Modele::Ajouter_element( ElementGeo * element)
{


	for(Elements::iterator it = elements.begin() ; it != elements.end() ; it++)
	{
		//cout << "element pointé par for : " << it->first << endl ;
		if(it->first == element->nom)
		{
			cout << "\"" << it->first << "\" est déjà présent dans le dessin." << endl ;
			return false ;
		}
	}
	elements.insert( pair<string,ElementGeo *>(element->nom,element) ) ;

	return true ;
}

bool Modele::Enlever_element( ElementGeo * element)
{
	for(map<string,ElementGeo *>::iterator it = elements.begin() ; it != elements.end() ; it++)
	{
		if(it->first == element->nom)
		{
			elements.erase(it) ;
			return true ;
		}
	}
	return false ;

}

ElementGeo * Modele::Element_par_nom( string nom)
{
	Elements::iterator it = elements.find(nom) ;
	if(it!=elements.end())
	{
		return it->second ;
	}
	return 0 ;
}


//------------------------------------------------- Surcharge d'opérateurs
/*Modele & Modele::operator = ( const Modele & unModele )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Modele::Modele ( const Modele & unModele )
// Algorithme :
//
{
	//elements = new Elements();
#ifdef MAP
    cout << "Appel au constructeur de copie de <Modele>" << endl;
#endif
} //----- Fin de Modele (constructeur de copie)


Modele::Modele ( )
// Algorithme :
//
{
	//delete elements ;
#ifdef MAP
    cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

