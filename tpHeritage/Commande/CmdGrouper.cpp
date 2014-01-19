/*************************************************************************
                           CmdGrouper  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <CmdGrouper> (fichier CmdGrouper.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdGrouper.h"
#include "../Modele/ElementGeo.h"
#include "../Modele/Groupe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CmdGrouper::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool CmdGrouper::Faire()
{
	modele->Ajouter_element(groupe);
	for(unsigned int i = 0; i < membres.size(); i++){
		if(!membres[i]->Ajouter_au_groupe(groupe)){
			cout << Commande::message[2] << "( Ajout du groupe dans "<<membres[i]->nom<<")"<<endl;
		}
	}
	return true;
}

bool CmdGrouper::Defaire()
{
	modele->Enlever_element(groupe);
	for(unsigned int i = 0; i < membres.size(); i++){
			if(!membres[i]->Enlever_du_groupe(groupe)){
				cout << Commande::message[2] << "( Suppression du groupe dans "<<membres[i]->nom<<")"<<endl;
			}
		}
	return true;
}

bool CmdGrouper::Initialisation(string instruction)
{
	vector<string> mots;
	Commande::Decouper(instruction,mots);
	int taille = mots.size();

	if(taille < 2){
		cout << Commande::message[0] <<endl;
		return false;
	}
	if(modele->Element_par_nom(mots[1]) != 0){
		cout << Commande::message[1] << endl;
		return false;
	}
	groupe = new Groupe(mots[1]);

	bool rep = true;
	int nb_erreur = 0;
	for(int i = 2; i < taille;i++){
		ElementGeo * elt = modele->Element_par_nom(mots[i]);
		if(elt != 0){
			membres.push_back(elt);
			if(!groupe->Ajouter_membre(elt)){
				rep = false;
				nb_erreur++;
				cout << Commande::message[2]<< "( Ajout de "<< mots[i]<<" au groupe)"<<endl;
			}
		} else {
			cout << Commande::message[2] <<  "L'élément \""<< mots[i]<<"\" n'existe pas."<<endl;
		}
	}
	if(!rep) cout << Commande::message[3]<< "("<<nb_erreur<<" erreur"<< (nb_erreur > 1 ? "s" : "")<<".)"<<endl;
	return true;
}

//------------------------------------------------- Surcharge d'opérateurs
/*CmdGrouper & CmdGrouper::operator = ( const CmdGrouper & unCmdGrouper )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
CmdGrouper::CmdGrouper ( const CmdGrouper & unCmdGrouper ) : Commande(unCmdGrouper.modele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CmdGrouper>" << endl;
#endif
} //----- Fin de CmdGrouper (constructeur de copie)


CmdGrouper::CmdGrouper ( Modele * fmodele ) : Commande(fmodele)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdGrouper>" << endl;
#endif
} //----- Fin de CmdGrouper


CmdGrouper::~CmdGrouper ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdGrouper>" << endl;
#endif
} //----- Fin de ~CmdGrouper


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

