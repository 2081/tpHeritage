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
#include <istream>
#include <sstream>
#include <iterator>

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

bool Initialisation( string instruction)
// Algorithme :
{
	istringstream ss(instruction);
	istream_iterator<string> begin(ss), end;
	vector<std::string> mots(begin, end);
	int taille = mots.size();
	if(taille == 0)return false;
	if(mots[0].compare("C")){
		if(taille != 5)return false;
		// element = new Cercle(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()));
	} else if(mots[0].compare("R")){
		if(taille != 6)return false;
		// element = new Rectangle(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()), atoi(mots[4].c_str()));
	} else if(mots[0].compare("L")){
		if(taille != 6)return false;
		// element = new Cercle(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()), atoi(mots[4].c_str()));
	} else if(mots[0].compare("PL")){
		if(taille >= 6 && taille%2 == 0)return false;
		// element = new Cercle(mots[1],atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()));
	}
	return true;
}

//------------------------------------------------- Surcharge d'opérateurs
/*CmdAjouterElement & CmdAjouterElement::operator = ( const CmdAjouterElement & unCmdAjouterElement )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdAjouterElement::CmdAjouterElement ( const CmdAjouterElement & unCmdAjouterElement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdAjouterElement>" << endl;
#endif
} //----- Fin de CmdAjouterElement (constructeur de copie)


CmdAjouterElement::CmdAjouterElement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjouterElement>" << endl;
#endif
} //----- Fin de CmdAjouterElement


CmdAjouterElement::~CmdAjouterElement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjouterElement>" << endl;
#endif
} //----- Fin de ~CmdAjouterElement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

