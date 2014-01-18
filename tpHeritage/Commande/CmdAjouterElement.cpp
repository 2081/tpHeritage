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
#include "../Modele/Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdAjouterElement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool CmdAjouterElement::Faire()
// Algorithme :
{
	return modele->Ajouter_element(element);
}

bool CmdAjouterElement::Defaire()
// Algorithme :
{
	return modele->Enlever_element(element);
}


// Constructeur PL ?
bool CmdAjouterElement::Initialisation( string instruction)
// Algorithme :
{
	vector<string> mots;
	Commande::Decouper(instruction,mots);
	int taille = mots.size();

	//Initialisation( string instruction);
	if(taille < 2){
		cout << Commande::message[0] << endl;
		return false;
	}
	if(modele->Element_par_nom(mots[1]) != 0) {
		cout << Commande::message[1] << endl;
		return false;
	}
	if(mots[0].compare("C")){
		if(taille != 5)return false;
		int nombre[3];
		for(int i = 0; i < 3; i++){
			if(!Est_un_nombre(mots[i+2],nombre[i]))return false;
		}
		element = new Cercle(mots[1], Point(nombre[0],nombre[1]),nombre[2]);
		return true;
	} else if(mots[0].compare("R")){
		if(taille != 6)return false;
		int nombre[4];
		for(int i = 0; i < 4; i++){
			if(!Est_un_nombre(mots[i+2],nombre[i]))return false;
		}
		element = new Rectangle(mots[1],Point(nombre[2],nombre[3]),Point(nombre[4], nombre[5]));
		return true;
	} else if(mots[0].compare("L")){
		if(taille != 6)return false;
		int nombre[4];
		for(int i = 0; i < 4; i++){
			if(!Est_un_nombre(mots[i+2],nombre[i]))return false;
		}
		element = new Ligne(mots[1],Point(nombre[2],nombre[3]),Point(nombre[4], nombre[5]));
		return true;
	} else if(mots[0].compare("PL")){
		if(taille >= 6 && taille%2 == 0)return false;
		vector<Point> nombre;
		for(int i = 0; i < taille-2; i += 2){
			int a,b;
			if(!Est_un_nombre(mots[i+2],a))return false;
			if(!Est_un_nombre(mots[i+2+1],b))return false;
			nombre.push_back(Point(a,b));
		}
		element = new PolyLigne(mots[1],&nombre);

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

