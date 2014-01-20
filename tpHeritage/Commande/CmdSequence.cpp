/*************************************************************************
                           CmdSequence  -  description
                             -------------------
    début                : 17 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdSequence> (fichier CmdSequence.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdSequence.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdSequence::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool CmdSequence::Faire()
{
	Commandes::iterator it;
	for(it = cmds.begin(); it < cmds.end(); it++){
		if(!(*it)->Faire()){
			for(it--;it >= cmds.begin(); it--){
				(*it)->Defaire();
			}
			return false;
		}
	}
	return true ;
}

bool CmdSequence::Defaire()
{
	Commandes::iterator it;
	for(it = cmds.begin(); it < cmds.end(); it++){
		(*it)->Defaire(); // Attention ! Renvoie tjs vrai
	}
	return true;
}

bool CmdSequence::Initialisation(string instruction)
{
	// No instruction for a sequence
	return true ;
}

bool CmdSequence::Ajouter_cmd(Commande * cmd)
{
	if(cmd == 0)return false;
	this->cmds.push_back(cmd);
	return true;
}


//------------------------------------------------- Surcharge d'opérateurs
/*CmdSequence & CmdSequence::operator = ( const CmdSequence & unCmdSequence )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdSequence::CmdSequence ( Modele* modele):Commande(modele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSequence>" << endl;
#endif
} //----- Fin de CmdSequence


CmdSequence::~CmdSequence ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSequence>" << endl;
#endif
    Commandes::iterator it;
	for(it = cmds.begin(); it < cmds.end(); it++){
		delete (*it);
	}

} //----- Fin de ~CmdSequence


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

