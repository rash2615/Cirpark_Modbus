//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Simulateur.h"
#include "SNClientUDP.h"
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

SNClientUDP client1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	client1.ModifierAdresseIPServeur("172.20.21.250");
	client1.ModifierPortServeur(2001);


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	char message[4]={0x1C,0x27,0x10,0x53};
	int reponse;
    client1.EnvoyerMessage(message);
	reponse=client1.RecevoirMessage(message,4);
	cout<<"taille de la réponse : "<<reponse<<endl;
}
//---------------------------------------------------------------------------

