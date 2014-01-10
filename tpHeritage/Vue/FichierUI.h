/*************************************************************************
                           FichierUI  -  description
                             -------------------
    début                : 10 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <FichierUI> (fichier FichierUI.h) ------
#if ! defined ( FICHIERUI_H_ )
#define FICHIERUI_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <FichierUI>
//
//
//------------------------------------------------------------------------ 

class FichierUI : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    FichierUI & operator = ( const FichierUI & unFichierUI );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    FichierUI ( const FichierUI & unFichierUI );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FichierUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FichierUI ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <FichierUI>

#endif // FICHIERUI_H_

