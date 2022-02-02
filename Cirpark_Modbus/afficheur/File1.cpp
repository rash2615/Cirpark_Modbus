#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include "AfficheurGeant.h"
int _tmain(int argc, _TCHAR* argv[]) 
{
	AfficheurGeant aff;
	aff.ModifierTexte("",10,50,0,255,0);  //modier le texte pour afficher du texte
	aff.EnvoyerImageEtTexte();
}
