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
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>

//------------------------------------------------------------- Constantes
const unsigned int NB_MESSAGE = 9;
const string Commande::message[] = {
		"# Instruction incorrecte. ",									// 0
		"# Ce nom est déjà utilisé. ",									// 1
		"# Opération échouée. ", 										// 2
		"# Poursuite de l'opération malgré une ou plusieur erreurs. ",	// 3
		"# Opération réussie. ",										// 4
		"# Opération annulée. ", 										// 5
		"# Echec de l'annulation. ",									// 6
		"# Nombre d'arguments incorrect.",								// 7
		"# Les coordonnées doivent être des nombres entiers."			// 8
};


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Commande::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Commande::Message(unsigned int num)
{
	if(num < NB_MESSAGE){
		cout << message[num] << endl;
	} else {
		cout << "# ("<<num<<") Code message inconnu."<<endl;
	}
}

bool Commande::Est_un_nombre(string & str, long int & l){
	char * pEnd;
	l = (long int)strtol(str.c_str(),&pEnd,10);
	return *pEnd == '\0';
}

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
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

