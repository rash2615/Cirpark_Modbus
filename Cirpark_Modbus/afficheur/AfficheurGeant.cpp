//---------------------------------------------------------------------------

#pragma hdrstop

#include "AfficheurGeant.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
AfficheurGeant::AfficheurGeant()
{   strcpy(IP,"172.20.21.199");
	r=100;v=100;b=255;top=50;taillePolice=20;
	strcpy(texte,"SNIR");
	strcpy(nomImage,"image0.png");
	image=new char[TAILLEIMAGEMAX];
}
AfficheurGeant::~AfficheurGeant()
{	delete [] image;
}
void AfficheurGeant::LireConfiguration()
{	ifstream fconfig;
	fconfig.open("ConfigAff.txt");
	char tmp[100];
	if(fconfig.is_open())
	{   fconfig>>tmp>>IP;
		fconfig.getline(tmp,100);
		fconfig>>tmp>>nomImage;
		fconfig>>tmp; fconfig.getline(texte,100);
		fconfig>>tmp>>taillePolice;
		fconfig>>tmp>>top;
		fconfig>>tmp>>r;
		fconfig>>tmp>>v;
		fconfig>>tmp>>b;
		fconfig.close();
	}
}
void AfficheurGeant::ModifierIP(char lIP[50])
{   strcpy(IP,lIP);
}
void AfficheurGeant::ModifierTexte(char letexte[100],int lataille,int letop,int lerouge,int levert,int lebleu)
{   strcpy(texte,letexte);
    taillePolice=lataille; top=letop; r=lerouge; v=levert; b=lebleu;
}
void AfficheurGeant::ModifierImage(char nomFichier[100])
{   strcpy(nomImage,nomFichier);
}
void AfficheurGeant::AfficheConfig()
{   cout<<"config.txt"<<endl;
	cout<<"IP\t"<<IP<<"\nIMAGE\t"<<nomImage<<endl;
	cout<<"TEXT\t"<<texte<<"\nPOLICE\t"<<taillePolice<<endl;
	cout<<"TOP\t"<<top<<"\nR\t"<<r<<"\nV\t"<<v<<"\nB\t"<<b<<endl;
}
void AfficheurGeant::EnvoyerImageEtTexte()
{	if(monClient.SeConnecterAUnServeur(IP,80))
	{   for(int i=0;i<2;i++)
		{	int lreq;
	//		if(i==-1)
	//		{	sprintf(requete,"GET /connect/?a1=admin&a2=dvs123&_=1612271776 HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\nAccept: */*\r\n\r\n",IP);
	//			lreq=strlen(requete);
	//		}
			if(i==0)
			{	ifstream f;
				int j=0;
				f.open(nomImage,ios::binary);
				if(f.is_open())
				do
				{   char c;
					c=f.get();
					image[j++]=c;
				}while(!f.eof());
				tailleImage=j;
				f.close();
				sprintf(requete,"POST /content/?upload&directory=&filename=%s HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\nContent-Length: %d\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36\r\nContent-Type: image/png\r\nAccept: */*\r\nOrigin: http://%s\r\nReferer: http://%s/gui/html/ContentWindow/ContentLookup.html\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n",nomImage,IP,tailleImage,IP,IP);
				lreq=strlen(requete);
			}
			if(i==1)
			{   sprintf(xml,"data=<message>\n<attribute+name='library'>128x128</attribute>\n\n<page+effect=\"jump\"+pause=\"10000ms\"+originalmessage=\"128x128/message\"+style=\"font-weight:+bold;+color:+rgb(%d,+%d,+%d);+text-align:+left;+background-color:+rgb(0,+0,+0);\"><img+src=\"/content/%s\"+style=\"position:+absolute;+left:+0px;+top:+0px;+width:+128px;+height:+128px;\"/><textbox+style=\"position:+absolute;+left:+0px;+top:+%dpx;+width:+128px;+height:+128px;\">\n++++++++<section>\n++++++++++<p+style=\"text-align:+center;\"><span+style=\"font-size:+%dpx;\">%s</span></p>\n++++++++</section>\n++++++</textbox>\n++++</page></message>\n",r,v,b,nomImage,top,taillePolice,texte);
				tailleXml=strlen(xml);
				sprintf(requete,"POST /device/?cmd=setActiveMessage&displays=display&overwrite=0 HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\nContent-Length: %d\r\nAccept: */*\r\nX-Requested-With: XMLHttpRequest\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36\r\nContent-Type: application/x-www-form-urlencoded; charset=UTF-8\r\nOrigin: http://%s\r\nReferer: http://%s/gui/html/MainWindow/MainWindow.html\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n",IP,tailleXml,IP,IP);
				lreq=strlen(requete);
			}
			//login : admin, psw : dvs123
			monClient.Envoyer(requete,lreq);  //lreq ou lreq+1
			if(i==0) monClient.Envoyer(image,tailleImage);
			if(i==1) monClient.Envoyer(xml,tailleXml);
			cout<<endl<<"longueur requete : "<<lreq<<endl;
			if(i==0) cout<<"longueur image : "<<tailleImage<<endl;
			if(i==1) cout<<"longueur xml : "<<tailleXml<<endl;
			cout<<"requete : "<<endl<<requete<<endl;
			int nbOctetsLus;
			nbOctetsLus=monClient.Recevoir(donnees,1500);
			cout<<donnees<<endl;
		}
		monClient.SeDeconnecter();
	}
}
