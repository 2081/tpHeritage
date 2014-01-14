/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Commande> (fichier Commande.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Commande.h"
#include <istream>
#include <sstream>
#include <iterator>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Commande::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Commande::Decouper(string & str, vector<string> & vect){
	istringstream ss(str);
	istream_iterator<string> begin(ss), end;
	vect = vector<string>(begin, end);
}

//------------------------------------------------- Surcharge d'opérateurs
/*Commande & Commande::operator = ( const Commande & unCommande )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Commande::Commande ( const Commande & unCommande )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Commande>" << endl;
#endif
} //----- Fin de Commande (constructeur de copie)


Commande::Commande ( Modele * fmodele ) : modele(fmodele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Commande>" << endl;
#endif
} //----- Fin de Commande


Commande::~Commande ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Commande>" << endl;
#endif
    delete modele;
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

