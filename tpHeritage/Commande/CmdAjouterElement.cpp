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
#include "../Modele/ElementGeo.h"
#include "../Modele/Cercle.h"
#include "../Modele/Ligne.h"
#include "../Modele/PolyLigne.h"
#include "../Modele/Rectangle.h"

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
	if(modele->Ajouter_element(element)){
		cout << Commande::message[4]<< "Ajout de l'element : \""<<element->nom<<"\" ."<<endl;
		return true;
	}
	cout << Commande::message[2]<< "Ajout de l'element : \""<<element->nom<<"\" ."<<endl;
	return false;
}

bool CmdAjouterElement::Defaire()
// Algorithme :
{
	if(modele->Enlever_element(element)){
			cout << Commande::message[5]<< "Ajout de l'element : \""<<element->nom<<"\" ."<<endl;
			return true;
		}
		cout << Commande::message[6]<< "Ajout de l'element : \""<<element->nom<<"\" ."<<endl;
		return false;
}


// Constructeur PL ?
bool CmdAjouterElement::Initialisation( string instruction)
// Algorithme :
{
	//cout << "# Instruction : " << instruction << endl;
	vector<string> mots;
	Commande::Decouper(instruction,mots);
	int taille = mots.size();

	//Initialisation( string instruction);
	if(taille < 2){
		Commande::Message(0);
		return false;
	}
	if(modele->Element_par_nom(mots[1]) != 0) {
		Commande::Message(1);
		return false;
	}
	bool rep = false;
	//cout << mots[0] << endl;

	if(!mots[0].compare("C")){ // CERCLE
		if(taille != 5){
			Commande::Message(7);
			return false;
		}
		int nombre[3];
		for(int i = 0; i < 3; i++){
			if(!Est_un_nombre(mots[i+2],nombre[i])){
				Commande::Message(8);
				return false;
			}
		}
		Point* point = new Point(nombre[0],nombre[1]) ;
		element = new Cercle(mots[1] , point , nombre[2]);

		rep = true;
	} else if(!mots[0].compare("R")){
		if(taille != 6){
			Commande::Message(7);
			return false;
		}
		int nombre[4];
		for(int i = 0; i < 4; i++){
			if(!Est_un_nombre(mots[i+2],nombre[i])){
				Commande::Message(8);
				return false;
			}
		}
		//
		Point* point1 = new Point(nombre[2],nombre[3]) ;
		Point* point2 = new Point(nombre[4],nombre[5]) ;
		element = new Rectangle(mots[1],point1,point2);

		rep = true;
	} else if(!mots[0].compare("L")){
		if(taille != 6){
			Commande::Message(7);
			return false;
		}
		int nombre[4];
		for(int i = 0; i < 4; i++){
			if(!Est_un_nombre(mots[i+2],nombre[i])){
				Commande::Message(5);
				return false;
			}
		}
		//
		Point* point1 = new Point(nombre[2],nombre[3]) ;
		Point* point2 = new Point(nombre[4],nombre[5]) ;
		element = new Ligne(mots[1],point1,point2);

		rep = true;
	} else if(!mots[0].compare("PL")){
		if(taille >= 6 && taille%2 == 0){
			Commande::Message(7);
			return false;
		}
		vector<Point> nombre;
		for(int i = 0; i < taille-2; i += 2){
			int a,b;
			if(!Est_un_nombre(mots[i+2],a) || !Est_un_nombre(mots[i+2+1],b)){
				Commande::Message(8);
				return false;
			}
			nombre.push_back(Point(a,b));
		}
		//nombre au lieu de &nombre
		element = new PolyLigne(mots[1],nombre);

		rep = true;
	}
	if(rep && element->Deplacer(0,0))return true; // Vérifier si l'élément n'est pas hors limite.
	delete element;
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

