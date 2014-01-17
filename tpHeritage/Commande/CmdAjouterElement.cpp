/*************************************************************************
                           CmdAjouterElement  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdAjouterElement> (fichier CmdAjouterElement.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <string>

//------------------------------------------------------ Include personnel
#include "CmdAjouterElement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterElement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void CmdAjouterElement::Faire()
// Algorithme :
{
	//modele->Ajouter_element(element);
}

void CmdAjouterElement::Defaire()
// Algorithme :
{
	//modele->Enlever_element(element);
}


bool CmdAjouterElement::Initialisation( string instruction)
// Algorithme :
{
	vector<string> mots;
	Commande::Decouper(instruction,mots);

	int taille = mots.size();
	//Initialisation( string instruction);
	if(taille == 0)return false;
	if(mots[0].compare("C")){
		if(taille != 5)return false;
		// element = new Cercle(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()));
		return true;
	} else if(mots[0].compare("R")){
		if(taille != 6)return false;
		// element = new Rectangle(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()), atoi(mots[4].c_str()));
		return true;
	} else if(mots[0].compare("L")){
		if(taille != 6)return false;
		// element = new Ligne(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()), atoi(mots[4].c_str()));
		return true;
	} else if(mots[0].compare("PL")){
		if(taille >= 6 && taille%2 == 0)return false;
		// Constructeur PL ?

		return true;
	}
	return false;
}

//------------------------------------------------- Surcharge d'opérateurs
/*CmdAjouterElement & CmdAjouterElement::operator = ( const CmdAjouterElement & unCmdAjouterElement )
// Algorithme :
//
{
    delete modele;
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdAjouterElement::CmdAjouterElement ( const CmdAjouterElement & unCmdAjouterElement ) : Commande(unCmdAjouterElement.modele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjouterElement>" << endl;
#endif
    element = 0;
} //----- Fin de CmdAjouterElement (constructeur de copie)


CmdAjouterElement::CmdAjouterElement ( Modele * fmodele) : Commande(fmodele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterElement>" << endl;
#endif
    element = 0;
} //----- Fin de CmdAjouterElement


CmdAjouterElement::~CmdAjouterElement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterElement>" << endl;
#endif
    delete element;
} //----- Fin de ~CmdAjouterElement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

