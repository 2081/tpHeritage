/*************************************************************************
                           FichierUI  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <FichierUI> (fichier FichierUI.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <iterator>
//------------------------------------------------------ Include personnel
#include "FichierUI.h"
#include "../Controleur/Controleur.h"
#include "../Modele/Modele.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FichierUI::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



bool FichierUI::Sauvegarder_modele(string nom_fichier)
// Algorithme :
//
{
	//Constitution du vector de vector.
	situation_modele.clear() ;
	Commandes_objet Cn ;
	situation_modele.push_back(Cn) ;
	int nb_rangs = 0 ;
	for(Elements::iterator it =  modele->elements.begin() ; it!=modele->elements.end() ; it++)
	{
		cout << it->second->dependance << endl ;
		if(it->second->dependance > nb_rangs)	//Un nouveau vector pour le rang supérieur.
		{
			for (int i = nb_rangs ; i!=it->second->dependance ; i++){
			Commandes_objet Cn ;	//liste de string
			situation_modele.push_back(Cn) ;
			}
			nb_rangs = it->second->dependance;
		}
		situation_modele[it->second->dependance].push_back(it->second->Obtenir_descripteur()) ;
	}

	//Ecriture dans le fichier.
	ofstream fichier(nom_fichier, ios::out | ios::trunc);
	if(fichier != 0 && fichier.is_open()){
		for (Situation_modele::iterator it_listes = situation_modele.begin() ; it_listes != situation_modele.end() ; it_listes++)
		{
			for(vector<string>::iterator it_descripteurs = it_listes->begin() ; it_descripteurs != it_listes->end() ; it_descripteurs++)
			{
				if(!(fichier << *it_descripteurs << endl))return false;
			}
		}
		cout << "# Le modèle courant est sauvegardé en : \"" << nom_fichier << "\"."<< endl ;
		return true ;
	} else {
		cout << "# Création du fichier impossible." << endl;
		return false;
	}
}

// bool FichierUI::Charger_modele(string nom_fichier)
// ( NEW !)
CmdSequence * FichierUI::Charger_modele(string nom_fichier)
// Algorithme :
/*Appels successifs de Controleur::Traduire_instruction
ligne par ligne par rapport aux lignes du fichier*/
{
	cout <<"# Nom du fichier à charger : " << nom_fichier << endl ;
	ifstream fichier(nom_fichier , ios::in) ;
	if (fichier)
	{
		cout << "# Fichier trouvé, début du chargement."<<endl;
		CmdSequence * sequence = new CmdSequence(modele);

		string commande_ligne ;
		while (getline(fichier,commande_ligne))
		{
			// Si la ligne n'est pas un commentaire
			if(commande_ligne[0] != '#')
			{
				// On remplie la sequence
				Commande * cmd = controleur->Traduire_instruction(commande_ligne);
				//cerr << commande_ligne <<endl;
				if(cmd == 0){
					cout << "# Une commande est erronee, annulation du chargement."<<endl;
					sequence->Defaire();
					cout << "# Fin de l'annulation du chargement."<< endl;
					return 0;
				}
				cmd->Faire();
				sequence->Ajouter_cmd(cmd);
			}
		}
		// Une fois remplie, on retourne la sequence ( NEW ! )
		cout << "# Fin du chargement de "<<nom_fichier<<endl;
		return sequence;
	}
	else
	{
		cout << "# Le fichier demandé \"" << nom_fichier << "\" est introuvable ou impossible à lire." << endl ;
		return 0 ;
	}
}
//------------------------------------------------- Surcharge d'opérateurs
/*FichierUI & FichierUI::operator = ( const FichierUI & unFichierUI )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*FichierUI::FichierUI ( const FichierUI & unFichierUI )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FichierUI>" << endl;
#endif
} //----- Fin de FichierUI (constructeur de copie)
*/

FichierUI::FichierUI (Controleur* fcontroleur , Modele* fmodele )
// Algorithme :
//
{
	 controleur = fcontroleur;
	 modele = fmodele;
#ifdef MAP
    cout << "Appel au constructeur de <FichierUI>" << endl;
#endif
} //----- Fin de FichierUI


FichierUI::~FichierUI ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FichierUI>" << endl;
#endif
} //----- Fin de ~FichierUI


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

