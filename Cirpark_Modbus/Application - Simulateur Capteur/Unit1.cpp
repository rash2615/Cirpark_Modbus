//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include "SNClientUDP.h"
#include <iostream>
using namespace std;
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
SNClientUDP session1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	session1.ModifierAdresseIPServeur("172.20.21.250");
	session1.ModifierPortServeur(2001);
	//session1.EnvoyerMessage("etat",10);
	 //cout << "Etat de la place : " << session1.Etat();
}
//---------------------------------------------------------------------------

bool EtatPlace(){
	bool etat = session1.Etat();
		if(etat==0) cout << "Libre/n";

	else cout << "Occupée/n";
	return etat;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   if (session1.Etat()==0)
		Shape2 -> Brush -> Color = clGreen;
   else if (session1.Etat()==1)
		Shape2 -> Brush -> Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 if (Shape2 -> Brush -> Color == clGreen)
		Shape2 -> Brush -> Color = clWhite;
   else if (Shape2 -> Brush -> Color == clRed)
		Shape2 -> Brush -> Color = clWhite;
}
//---------------------------------------------------------------------------


