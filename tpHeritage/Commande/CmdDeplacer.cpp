/*************************************************************************
                           CmdDeplacer  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdDeplacer> (fichier CmdDeplacer.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "CmdDeplacer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdDeplacer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool CmdDeplacer::Faire()
// Algorithme :
{
	return element->Deplacer(dx,dy);
}

bool CmdDeplacer::Defaire()
// Algorithme :
{
	return element->Deplacer(-dx,-dy);
}

bool CmdDeplacer::Initialisation( string instruction)
// Algorithme :
{
	vector<string> donnees;
	Commande::Decouper(instruction,donnees);
	if(donnees.size()!= 4)return false;
	element = modele->Element_par_nom(donnees[1]);
	if(element == 0){
		cout <<Commande::message[2]<< "L'element n'existe pas.";
		return false;
	}
	return Est_un_nombre(donnees[2],dx) && Est_un_nombre(donnees[3],dy);
}

//------------------------------------------------- Surcharge d'opérateurs
/*CmdDeplacer & CmdDeplacer::operator = ( const CmdDeplacer & unCmdDeplacer )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdDeplacer::CmdDeplacer ( const CmdDeplacer & unCmdDeplacer ) : Commande(unCmdDeplacer.modele)
// Algorithme :
////
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdDeplacer>" << endl;
#endif
    element = 0;
    dx = dy = 0;
} //----- Fin de CmdDeplacer (constructeur de copie)


CmdDeplacer::CmdDeplacer ( Modele * fmodele ) : Commande(fmodele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdDeplacer>" << endl;
#endif
    element = 0;
    dx = dy = 0;
} //----- Fin de CmdDeplacer


CmdDeplacer::~CmdDeplacer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdDeplacer>" << endl;
#endif
} //----- Fin de ~CmdDeplacer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

