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
 int mult=2;
 	char capteur[16][2];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	tabShape[0]=Shape4;
	tabShape[1]=Shape5;
	tabShape[2]=Shape6;
	tabShape[3]=Shape7;
	tabShape[4]=Shape8;
	tabShape[5]=Shape9;
	tabShape[6]=Shape10;
	tabShape[7]=Shape11;
	tabShape[8]=Shape13;
	tabShape[9]=Shape14;
	tabShape[10]=Shape15;
	tabShape[11]=Shape16;
	tabShape[12]=Shape17;
	tabShape[13]=Shape18;
	tabShape[14]=Shape19;
	tabShape[15]=Shape20;

	client1.ModifierAdresseIPServeur("172.20.21.250");
	client1.ModifierPortServeur(2001);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

	for (int i=0; i<= 16 ; i++){
	  /*	if (i==0){
			capteur[i][0]=0x1c;
			capteur[i][1]=0x27;
		}
		if (i==1){
			capteur[1][0]=0x15;
			capteur[1][1]=0x7b;
		}  */

	}
	char messageCapt1[10];
	int k=0;
		capteur[0][0]=0x1c;
		capteur[0][1]=0x27;
		capteur[1][0]=0x15;
		capteur[1][1]=0x7b;
	for(int i=0;i<16;i++){
	  k=i%mult;
	messageCapt1[0]=0x41;
	messageCapt1[1]=0x00;
	messageCapt1[2]=0x01;
	messageCapt1[3]=capteur[k][0];
	messageCapt1[4]=capteur[k][1];
	messageCapt1[5]=0x10;
	messageCapt1[6]=0x00;


	client1.EnvoyerMessage(messageCapt1,7);
	client1.RecevoirMessage(messageCapt1,10);

	/*char messageCapt2[10];
	messageCapt2[0]=0x41;
	messageCapt2[1]=0x00;
	messageCapt2[2]=0x01;
	messageCapt2[3]=capteur[1][0];
	messageCapt2[4]=capteur[1][1];
	messageCapt2[5]=0x10;
	messageCapt2[6]=0x00;


	client1.EnvoyerMessage(messageCapt2,7);
	client1.RecevoirMessage(messageCapt2,10);  */


		if(messageCapt1[7]== 0x01)
			tabShape[i] -> Brush -> Color = clRed;
		if (messageCapt1[7]== 0x00)
			tabShape[i] -> Brush -> Color = clGreen;
	}
	/*for (int j=1; j<16; j=j+2){
		if (messageCapt2[7]== 0x01 )
			tabShape[j] -> Brush -> Color = clRed;
		if (messageCapt2[7]== 0x00 )
			tabShape[j] -> Brush -> Color = clGreen;
	}  */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
		// Rendre visible la fenetre lors du click sur le bouton ajouter
	  GroupBox1 ->Visible = true;
	  Edit1 -> Visible = true;
	  Edit2 -> Visible = true;

		// Récuperer les données saisies dans les champs
	  char  valeur1[10],valeur2[10];
	  strcpy(valeur1, AnsiString( Edit1 -> Text).c_str());
	  strcpy(valeur2, AnsiString( Edit2 -> Text).c_str());

}
//---------------------------------------------------------------------------


