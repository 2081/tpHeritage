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
//------------------------------------------------------ Include personnel
#include "FichierUI.h"

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
	cout << "Le nom de votre sauvegarde est : \"" << nom_fichier << "\"."<< endl ;
	return true ;
}

bool FichierUI::Charger_modele(string nom_fichier)
// Algorithme :
/*Appels successifs de Controleur::Traduire_instruction
ligne par ligne par rapport aux lignes du fichier*/
{
	cout << nom_fichier << endl ;
	ifstream fichier(nom_fichier , ios::in) ;
	if (fichier)
	{
		string commande_ligne ;
		bool ligne_ok ;
		while (getline(fichier,commande_ligne) && ligne_ok)
		{
			//C'est comme si on exécutait les instructions une par une.
			ligne_ok = controleur->Traduire_instruction(commande_ligne);
			/*si ligne_ok reste true, alors la ligne dans le fichier est une
			commande correcte.*/
		}
		return ligne_ok ;
		//La lecture s'est bien passée et les commandes ont toute été correctes.

	}
	else
	{
		cout << "Le fichier demandé \"" << nom_fichier << "\" est introuvable." << endl ;
		return false ;
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

FichierUI::FichierUI ( )
// Algorithme :
//
{
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

