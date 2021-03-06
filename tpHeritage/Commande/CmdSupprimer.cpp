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
#include <list>
typedef unsigned int uint;

//------------------------------------------------------ Include personnel
#include "CmdSupprimer.h"
#include "../Modele/Groupe.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSupprimer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdSupprimer::Faire()
// Algorithme :
{
	for(uint i = 0; i<elements_suppr.size(); i++){
		Groupes::iterator it;
		for( it = elements_suppr[i]->groupes.begin(); it != elements_suppr[i]->groupes.end() ; it++ ){
			(*it)->Enlever_membre(elements_suppr[i]);
		}
		if(!modele->Enlever_element(elements_suppr[i]))return false;
	}
	cout << Commande::message[4] << "Suppression de "<<elements_suppr.size()<<" element(s)."<<endl;
	return true;
}

bool CmdSupprimer::Defaire()
// Algorithme :
{
	//cout << "undo defaire"<<endl;
	for(uint i = 0; i<elements_suppr.size(); i++){
		Groupes::iterator it;
		//cout << elements_suppr[i] <<" -  "<<elements_suppr[i]->groupes.size()<<endl;
		for( it = elements_suppr[i]->groupes.begin(); it != elements_suppr[i]->groupes.end() ; it++ ){
			//cout <<elements_suppr[i]->groupes.size()<< " - entree dans la boucle"<<endl;
			(*it)->Ajouter_membre(elements_suppr[i]);
		}
		if(!modele->Ajouter_element(elements_suppr[i]))return false;
		//cout << "Ajouté : "<<elements_suppr[i]->nom<<endl;
	}
	cout << Commande::message[5] << "Suppression de "<<elements_suppr.size()<<" element(s)."<<endl;
	return true;
}

bool CmdSupprimer::Initialisation(string instruction)
// Algorithme :
{
	vector<string> donnees;
	Commande::Decouper(instruction,donnees);
	for(uint i = 1; i< donnees.size(); i++){
		ElementGeo * el = modele->Element_par_nom(donnees[i]);
		if(el == 0)return false;
		elements_suppr.push_back(el);
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

