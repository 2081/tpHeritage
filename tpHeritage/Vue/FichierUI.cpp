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
			cout << "rang supérieur" << endl ;
			}
			nb_rangs = it->second->dependance;
		}
		cout << "ajout " << it->second->dependance << endl ;
		situation_modele[it->second->dependance].push_back(it->second->Obtenir_descripteur()) ;
	}

	//Ecriture dans le fichier.
	cout << "ecriture" << endl ;
	ofstream fichier(nom_fichier, ios::out | ios::trunc);
	for (Situation_modele::iterator it_listes = situation_modele.begin() ; it_listes != situation_modele.end() ; it_listes++)
	{
		for(vector<string>::iterator it_descripteurs = it_listes->begin() ; it_descripteurs != it_listes->end() ; it_descripteurs++)
		{
			fichier << *it_descripteurs << endl;
		}
	}

	cout << "# Le nom de votre sauvegarde est : \"" << nom_fichier << "\"."<< endl ;
	return true ;
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
		/* Je me permet de modifier ça - Robin
		string commande_ligne ;
		bool ligne_ok ;
		while (getline(fichier,commande_ligne) && ligne_ok)
		{
			//C'est comme si on exécutait les instructions une par une.
			ligne_ok = controleur->Traduire_instruction(commande_ligne);
			//si ligne_ok reste true, alors la ligne dans le fichier est une
			//commande correcte.
		}
		return ligne_ok ;
		//La lecture s'est bien passée et les commandes ont toute été correctes.
		*/
		CmdSequence * sequence = new CmdSequence(modele);
		string commande_ligne ;
		while (getline(fichier,commande_ligne))
		{
			// Si la ligne n'est pas un commentaire
			if(commande_ligne[0] != '#')
			{
				// On remplie la sequence
				Commande * cmd = controleur->Traduire_instruction(commande_ligne);
				if(cmd == 0) return 0;
				sequence->Ajouter_cmd(cmd);
			}
		}
		// Une fois remplie, on retourne la sequence ( NEW ! )
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

