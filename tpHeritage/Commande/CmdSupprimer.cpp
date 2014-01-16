/*************************************************************************
                           CmdSupprimer  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdSupprimer> (fichier CmdSupprimer.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdSupprimer.h"
#include "../Modele/ElementGeo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSupprimer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdSupprimer::Initialisation(string instruction){
	vector<string> donnees;
	Commande::Decouper(instruction,donnees);
	vector<ElementGeo *> vect;
	for(uint i = 1; i< donnees.size(); i++){
		ElementGeo * el = modele->Element_par_nom(donnees[i]);
		if(el == 0)return false;
		vect.push_back(el);
	}
	for(uint i = 0; i<vect.size(); i++){
		modele->Enlever_element(vect[i]);
	}
	return true;
}

//------------------------------------------------- Surcharge d'opérateurs
/*mdSupprimer & CmdSupprimer::operator = ( const CmdSupprimer & unCmdSupprimer )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdSupprimer::CmdSupprimer ( const CmdSupprimer & unCmdSupprimer ) : Commande(unCmdSupprimer.modele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdSupprimer>" << endl;
#endif
} //----- Fin de CmdSupprimer (constructeur de copie)


CmdSupprimer::CmdSupprimer ( Modele * fmodele ) : Commande(fmodele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSupprimer>" << endl;
#endif
} //----- Fin de CmdSupprimer


CmdSupprimer::~CmdSupprimer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSupprimer>" << endl;
#endif
} //----- Fin de ~CmdSupprimer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

