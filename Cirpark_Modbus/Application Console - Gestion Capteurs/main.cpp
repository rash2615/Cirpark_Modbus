#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
using namespace std;
#include "PortSerieAfficheur.h"

int _tmain(int argc, _TCHAR* argv[]) 
{
	PortSerieAfficheur capt1;
	capt1.ouvrir("capt1");
	cout << "Test" ;
    cin.get();
    capt1.fermer();
	return 0;
}
