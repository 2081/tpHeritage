/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>      // std::istringstream

//------------------------------------------------------ Include personnel
#include "Controleur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Controleur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Controleur::Executer_instruction(string instruction)
// Algorithme :
//
{
	istringstream flux_commande (instruction) ;
	getline(flux_commande , premier_argument , ' ');
	for( pt = liste_commandes ; pt != liste_commandes+14; pt++)
	{
		if(*pt == premier_argument && premier_argument=="pas_trouve")
		{
			premier_argument = *pt ;
		}
	}

	//Analyse du résultat et appel des procédures de commandes.
	if(premier_argument=="pas_trouve")
	{
		cout << "\"" << instruction << "\"" << "n\' est pas une commande valide" << endl ;
		return;
	}
	//liste des elsif
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Controleur & Controleur::operator = ( const Controleur & unControleur )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur ( const Controleur & unControleur )
// Algorithme :
//
{
	pt = liste_commandes ;	//Réinitialisé à chaque fois dans
	//Executer_instruction
#ifdef MAP
    cout << "Appel au constructeur de copie de <Controleur>" << endl;
#endif
} //----- Fin de Controleur (constructeur de copie)


Controleur::Controleur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

