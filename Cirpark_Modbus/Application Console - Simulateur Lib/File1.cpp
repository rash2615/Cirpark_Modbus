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

 int _tmain(int argc, _TCHAR* argv[]) 
{
   SNClientUDP session1;

   session1.ModifierAdresseIPServeur("172.20.21.250");
   session1.ModifierPortServeur(2001);
   session1.EnvoyerMessage("etat",10);
   session1.RecevoirMessage("etat",10);
   session1.Etat();




	cin.get();



}

