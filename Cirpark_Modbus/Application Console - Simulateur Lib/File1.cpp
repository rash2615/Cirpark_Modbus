#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include "SNClientTCP.h"
#include <iostream>
using namespace std;

 int _tmain(int argc, _TCHAR* argv[]) 
{
SNClientTCP session1;

	if(session1.SeConnecterAUnServeur("172.20.21.221",3306)== 1)
		cout << "Le serveur est connecte";
	else
		cout << "Le serveur n'est pas connecte";
		cin.get();
session1.SeDeconnecter();


}

