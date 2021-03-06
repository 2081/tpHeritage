/*************************************************************************
                           ConsoleUI  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <ConsoleUI> (fichier ConsoleUI.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ConsoleUI.h"
#include "../Controleur/Controleur.h"
#include "../Modele/Modele.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ConsoleUI::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void ConsoleUI::Attendre_instruction()
// Algorithme :
//
{
	string commande_tapee ;
	bool continuer_programme = true ;
	while (continuer_programme && getline(cin , commande_tapee))
	{
		continuer_programme = pt_controleur->Executer_instruction(commande_tapee);
	}
} //----- Fin de Attendre_instruction

void ConsoleUI::Lister_modele()
// Algorithme :
//
{
	if(!pt_modele->elements.empty())
	{
		Elements::iterator it = pt_modele->elements.begin();
		while(it != pt_modele->elements.end()){
			cout << it->second->Obtenir_descripteur() << endl;
			it++ ;
		}
	}

} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/*ConsoleUI & ConsoleUI::operator = ( const ConsoleUI & unConsoleUI )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur



ConsoleUI::ConsoleUI ( Modele* m , Controleur* c )
// Algorithme :
//
{
	pt_modele = m;
	pt_controleur = c;

#ifdef MAP
    cout << "Appel au constructeur de <ConsoleUI>" << endl;
#endif
} //----- Fin de ConsoleUI


ConsoleUI::~ConsoleUI ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ConsoleUI>" << endl;
#endif
} //----- Fin de ~ConsoleUI


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

