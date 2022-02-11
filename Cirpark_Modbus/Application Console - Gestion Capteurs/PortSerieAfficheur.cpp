#include "PortSerieAfficheur.h"

#ifdef __unix__
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#elif _WIN32 || _WIN64

#endif

#include <iostream>
using namespace std;

/********************************************************************************
*	SOUS-PROGRAMME PortSerieAfficheur DE LA CLASSE PortSerieAfficheur	*
*		DONNEES EN ENTREE :						*
* 		DONNEES EN SORTIE :						*
* 		DONNEES LOCALES : 						*
*********************************************************************************
* 	DESCRIPTION :								*
* 	Le constructeur fourni des valeurs par d�faut au attributs de la 	*
* 	classe. Par d�faut, le port est ferm�, le descripteur de fichier vaut 	*
* 	-1 et le nom du port est une chaine de caract�re vide.			*
*********************************************************************************
*	VALEUR DE RETOUR : 							*
********************************************************************************/
PortSerieAfficheur::PortSerieAfficheur()
{
    // Valeur par d�faut des attributs
    m_estOuvert = false;
    m_nomDuPortSerie =  "";
    m_descripteurFichier = -1;
}


/********************************************************************************
*	SOUS-PROGRAMME ~PortSerieAfficheur DE LA CLASSE PortSerieAfficheur	*
*		DONNEES EN ENTREE :						*
* 		DONNEES EN SORTIE :						*
* 		DONNEES LOCALES : 						*
*********************************************************************************
* 	DESCRIPTION :								*
* 	Le destructeur doit v�rifier que le port s�rie est bien ferm� avant que	*
* 	l'objet soit d�truit. S'il n'est pas ferm�, il le ferme.		*
*********************************************************************************
*	VALEUR DE RETOUR : 							*
********************************************************************************/
PortSerieAfficheur::~PortSerieAfficheur()
{
    if(m_estOuvert)
        this->fermer();
}

/********************************************************************************
*	SOUS-PROGRAMME ouvrir DE LA CLASSE PortSerieAfficheur			*
*		DONNEES EN ENTREE : nomDuPortSerie[] : CARACTERE		*
* 		DONNEES EN SORTIE : erreur : ENTIER				*
* 		DONNEES LOCALES : 						*
*********************************************************************************
* 	DESCRIPTION :								*
* 	Cette m�thode doit ouvrir le port s�rie dont le nom est pass� en 	*
* 	argument : 'nomDuPortSerie'. Si cet objet a d�j� ouvert un port s�rie	*
* 	ou que l'ouverture du port s�rie sp�cifi� est impossible (port ouvert	*
* 	par quelqu'un d'autre, droits insuffisants...) cette m�thode retourne	*
* 	une valeur n�gative. Sinon, elle renvoie 0.				*
*********************************************************************************
*	VALEUR DE RETOUR : 							*
*	Cette m�thode renvoie 0 en cas de succ�s, une valeur n�gative sinon.	*
********************************************************************************/
int PortSerieAfficheur::ouvrir(string nomDuPortSerie)
{
    // Copie du nom dans l'attribut m_nomDuPortSerie si le nom n'est pas trop long
    if(nomDuPortSerie.length() > 50) return -1;
    m_nomDuPortSerie = nomDuPortSerie;

    // On v�rifie qu'un port de comunication s�rie n'est pas d�j� ouvert...
    if(m_estOuvert) return -2;

	// On ouvre le port de communication s�rie demand�
	#ifdef __unix__
	//m_descripteurFichier = open(nomDuPortSerie, O_RDWR | O_NOCTTY | O_NDELAY);
	m_descripteurFichier = open(nomDuPortSerie.c_str(), O_RDWR | O_NDELAY);
	//m_descripteurFichier = open(nomDuPortSerie, O_RDWR );
	#elif _WIN32 || _WIN64

	#endif

	if (m_descripteurFichier == -1) return -3;
	m_estOuvert = true;

	#ifdef __unix__
	// D�claration d'une structure contenant les param�tres du port s�rie
    struct termios options;
    // On r�cup�re les param�tres actuels du port s�rie
    tcgetattr(m_descripteurFichier, &options);
    // On impose une vitesse � 9600 baud en lecture et en �criture
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    // On impose 8N1  : 8 bits de donn�es, pas de bit de parit�, 1 bit stop.
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    // On modifie les param�tres du port s�rie avec nos nouvelles valeurs
	tcsetattr(m_descripteurFichier, TCSANOW, &options);
	// La lecture sera bloquante
	fcntl(m_descripteurFichier, F_SETFL, 0);	// Lecture bloquante
	#elif _WIN32 || _WIN64

	#endif
    return 0;
}


/********************************************************************************
*	SOUS-PROGRAMME fermer DE LA CLASSE PortSerieAfficheur			*
*		DONNEES EN ENTREE :						*
* 		DONNEES EN SORTIE : erreur : ENTIER				*
* 		DONNEES LOCALES : 						*
*********************************************************************************
* 	DESCRIPTION :								*
* 	Cette m�thode doit fermer le port s�rie pr�c�demment ouvert. Si le port *
* 	s�rie n'�tait pas ouvert ou que la fermeture du port s�rie provoque une *
* 	erreur, cette m�thode renvoie une valeur n�gative. Sinon, elle renvoie 	*
* 	0.									*
*********************************************************************************
*	VALEUR DE RETOUR : 							*
* 	Cette m�thode renvoie 0 en cas de succ�s, une valeur n�gative sinon.	*
********************************************************************************/
int PortSerieAfficheur::fermer()
{
    // Si le port s�rie n'a pas �t� ouvert, on renvoie -1
    if(m_descripteurFichier == -1)
        return -1;
    // Si la fermeture du port s�rie �choue, on renvoie -2
    #ifdef __unix__
    if(close(m_descripteurFichier) == -1)
        return -2;
    #elif _WIN32 || _WIN64

	#endif
    // Sinon, on indique que la fermeture s'est bien pass� en mettant le bool�en m_estouvert � false et en renvoyant la valeur 0
    m_estOuvert = false;
    return 0;
}


/********************************************************************************
*	SOUS-PROGRAMME envoyerCaractere DE LA CLASSE PortSerieAfficheur		*
*		DONNEES EN ENTREE : c : CARACTERE       			*
* 		DONNEES EN SORTIE : resultat : BOOLEEN				*
* 		DONNEES LOCALES : 						*
*********************************************************************************
* 	DESCRIPTION :								*
* 	Cette m�thode doit envoyer sur le port s�rie le caract�re 'c' pass� en  *
*       argument. Le port s�rie doit �tre pr�alalement ouvert, sinon 'resultat' *
*       vaut 'FAUX'.                                                            *
* 	Si le nombre d'octet r�ellement envoy� est diff�rent de 1, 'resultat'   *
*       vaut 'FAUX'.                						*
*********************************************************************************
*	VALEUR DE RETOUR : 							*
* 	Cette m�thode renvoie FAUX en cas d'erreur, VRAI sinon.                 *
********************************************************************************/
bool PortSerieAfficheur::envoyerCaractere(const char c) const
{
    // Si le port s�rie n'est pas ouvert, renvoie de 'FAUX'
    if (!m_estOuvert)
        return false;
    // �criture du caract�re 'c' sur le port s�rie. On r�cup�re le nombre d'octet vraiment �crit dans nbOctet.
    int nbOctet;
    #ifdef __unix__
    nbOctet = write(m_descripteurFichier, &c, 1);
    #elif _WIN32 || _WIN64

	#endif
    // Si nombre d'octet vraiment �crit est diff�rent de 1, renvoie de la valeur 'FAUX', 'VRAI sinon.
    if(nbOctet != 1)
        return false;
    return true;
}


/********************************************************************************
*	SOUS-PROGRAMME envoyerTrame DE LA CLASSE PortSerieAfficheur		*
*		DONNEES EN ENTREE : trame[] : CARACTERE       			*
* 		DONNEES EN SORTIE : resultat : BOOLEEN				*
* 		DONNEES LOCALES : 						*
*********************************************************************************
* 	DESCRIPTION :								*
* 	Cette m�thode doit envoyer sur le port s�rie la cha�ne de caract�res    *
*       'trame' pass� en argument. Le port s�rie doit �tre pr�alalement ouvert  *
*       sinon 'resultat' vaut 'FAUX'.                                           *
* 	Si le nombre d'octet r�ellement envoy� est diff�rent de la longueur de  *
*       la trame � envoyer, 'resultat' vaut 'FAUX'.                             *                						*
*********************************************************************************
*	VALEUR DE RETOUR : 							*
* 	Cette m�thode renvoie FAUX en cas d'erreur, VRAI sinon.                 *
********************************************************************************/
bool PortSerieAfficheur::envoyerTrame(const char trame[]) const
{
	int tailleDeLaTrame = strlen(trame);
	int nbOctet;

	if (!m_estOuvert)
		return false;
	#ifdef __unix__
	nbOctet = write(m_descripteurFichier, trame, tailleDeLaTrame);
	usleep(100000);
	#elif _WIN32 || _WIN64

	#endif

	if(nbOctet != tailleDeLaTrame)
		return false;

	return true;
}


// Surcharge de la m�thode pr�c�dente
bool PortSerieAfficheur::envoyerTrame(string trame) const
{
	int tailleDeLaTrame = trame.length();
	int nbOctet;

	if (!m_estOuvert)
		return false;
	#ifdef __unix__
	nbOctet = write(m_descripteurFichier, trame.c_str(), tailleDeLaTrame);
	usleep(100000);
	#elif _WIN32 || _WIN64

	#endif

	if(nbOctet != tailleDeLaTrame)
		return false;

	return true;}

int PortSerieAfficheur::lireMessage(char message[], int tailleMaximaleDuMessage) const
{
	int nbOctet=0;
	cout << "Attente d'un message" << endl;
	#ifdef __unix__
	nbOctet = read(m_descripteurFichier, message, tailleMaximaleDuMessage-1);
	#elif _WIN32 || _WIN64

	#endif

	cout << "Message lu" << endl;
	// Rajout du caract�re \0 si n�cessaire
	if(message[nbOctet-1] != '\0')
		message[nbOctet] = '\0';
	return nbOctet;
}

string PortSerieAfficheur::lireMessage() const
{
	char msg[1024];
	int nbOctet=0;
	cout << "Attente d'un message" << endl;
	#ifdef __unix__
	nbOctet = read(m_descripteurFichier, msg, 1023);
	#elif _WIN32 || _WIN64

	#endif

	cout << "Message lu" << endl;
	// Rajout du caract�re \0 si n�cessaire
	if(msg[nbOctet-1] != '\0')
		msg[nbOctet] = '\0';
	//return nbOctet;
	return string(msg);
}

/*int PortSerieAfficheur::lireMessageMieux(char message[], int tailleMaximaleDuMessage) const
{
    int nbOctetsLus=0;
    int res;
    int tmp = 0;
    do{
      res = read(m_descripteurFichier, message+nbOctetsLus, 1);
      //cout << "Lire - res : " << res << " - nbOctetsLus : " << nbOctetsLus << endl;
      if(res > 0 ) nbOctetsLus += res;
      tmp ++;
      usleep(10);
    } while(tmp<8000);
    // Rajout du caract�re \0 si n�cessaire
    if(message[nbOctetsLus-1] != '\0')
        message[nbOctetsLus] = '\0';
    return nbOctetsLus;
}


int PortSerieAfficheur::lireMessageACK(char message[], int tailleMaximaleDuMessage) const
{
    int nbOctetsLus=0;
    int nbOctetsALire = 3;
    do
    {
      nbOctetsLus += read(m_descripteurFichier, message + nbOctetsLus, 1);
      if((nbOctetsLus == 1) && (message[0] == 'N'))
      {
	nbOctetsALire = 4;
      }
    }while (nbOctetsLus < nbOctetsALire );
    // Rajout du caract�re \0 si n�cessaire
    if(message[nbOctetsLus-1] != '\0')
        message[nbOctetsLus] = '\0';
    return nbOctetsLus;
}*/

