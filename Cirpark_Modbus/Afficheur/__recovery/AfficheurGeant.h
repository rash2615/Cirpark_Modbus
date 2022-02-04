//---------------------------------------------------------------------------

#ifndef AfficheurGeantH
#define AfficheurGeantH
//---------------------------------------------------------------------------
#include <fstream>
#include <iostream>
using namespace std;
#include "SNClientTCP.h"
#define TAILLEIMAGEMAX 100000

//IP	172.20.21.199
//IMAGE	image0.png
//TEXT	ceci est une fleur
//POLICE 20
//TOP	20
//R	255
//V	0
//B	200

//https://www.urldecoder.org/

class AfficheurGeant
{   private :
		SNClientTCP monClient;
		char requete[20000],xml[20000],*image,donnees[20000],IP[50];
		int tailleImage,tailleXml,r,v,b,top,taillePolice;
		char texte[100],nomImage[100];
	public :
		AfficheurGeant();
        ~AfficheurGeant();
		void LireConfiguration();
		inline char* Texte(){return texte;};
		inline char* NomImage(){return nomImage;};
		inline char* LireIP(){return IP;};
        void ModifierIP(char lIP[50]);
		void ModifierTexte(char letexte[100],int lataille,int letop,int lerouge,int levert,int lebleu);
		void ModifierImage(char nomFichier[100]);
		void AfficheConfig();
		void EnvoyerImageEtTexte();
};




#endif
