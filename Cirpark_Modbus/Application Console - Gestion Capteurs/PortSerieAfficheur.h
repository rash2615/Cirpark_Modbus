#ifndef PORTSERIEAFFICHEUR_H
#define PORTSERIEAFFICHEUR_H



#include <string.h>
#include <string>
using namespace std;


//!  Classe de communication avec l'afficheur
/*!
  Elle permet la communication par le port s�rie avec l'afficheur.
  Le nom du port s�rie utilis� pour la communication doit �tre indiqu� par la m�thode ouvrir().
  Ensuite, les m�thodes envoyerCaractere() et envoyerTrame() permettent l'envoi de donn�es vers l'afficheur.
  La m�thode lireMessage() permet de lire les messages provenant de l'afficheur. Il n'y a que 2 messages possibles : ACK ou NACK.
  Pour terminer correctement la communication, la m�thode fermer() doit �tre utilis�e.
*/

class PortSerieAfficheur
{
public:

    //! Le constructeur.
    /*!
      Le constructeur fourni des valeurs par d�faut aux attributs de la classe. Par d�faut, le port est ferm�, le descripteur de fichier vaut -1 et le nom du port est une chaine de caract�re vide.
      \sa ouvrir(), ~PortSerieAfficheur()
    */
    PortSerieAfficheur();

    //! Le destructeur.
    /*!
      Le destructeur ferme le port s�rie s'il est encore ouvert.
      \sa fermer(), PortSerieAfficheur()
    */
    ~PortSerieAfficheur();

    //! Ouverture du port s�rie.
    /*!
      Cette m�thode ouvre la communication sur le port s�rie dont le nom est pass� en argument. Les param�tres de la communication avec l'afficheur sont : 9600 baud - 8N1 (8 bits de donn�es, pas de parit� et 1 bit stop).
      Si l'ouverture du port s�rie sp�cifi� est impossible (la m�thode ouvrir() a d�j� �t� appel�e avec succ�s et la m�thode fermer() n'a pas �t� appel�e, le port s�rie a �t� ouvert par quelqu'un d'autre, les droits de l'utilisateur sont insuffisants...) cette m�thode renvoie	une valeur n�gative. Sinon, elle renvoie 0.
      \param nomDuPortSerie une cha�ne de caract�res contenant le nom du port s�rie � ouvrir.
      \return Cette m�thode renvoie 0 en cas de succ�s, une valeur n�gative sinon.
      \sa fermer()
    */
    int ouvrir(string nomDuPortSerie);

    //! Fermeture du port s�rie.
    /*!
      Cette m�thode ferme le port s�rie pr�c�demment ouvert. Si le port s�rie n'�tait pas ouvert ou que la fermeture du port s�rie provoque une erreur, cette m�thode renvoie une valeur n�gative. Sinon, elle renvoie 0.
      \return Cette m�thode renvoie 0 en cas de succ�s, une valeur n�gative sinon.
      \sa ouvrir()
    */
    int fermer();

    //! Emmission d'un caract�re sur le port s�rie.
    /*!
      Cette m�thode envoie le caract�re 'c' pass� en argument sur le port s�rie. Le port s�rie doit �tre pr�alablement ouvert, sinon la m�thode renvoie false. De plus, si le nombre d'octets r�ellement envoy� est diff�rent de 1, cette m�thode renvoie false.
      \param c le caract�re � �mettre.
      \return Cette m�thode renvoie true en cas de succ�s, false sinon.
      \sa envoyerTrame(), lireMessage()
    */
    bool envoyerCaractere(const char c) const;

	//! Emmission d'une cha�ne de caract�res sur le port s�rie.
	/*!
	  Cette m�thode envoie la cha�ne de caract�res 'trame' pass� en argument sur le port s�rie. Le port s�rie doit �tre pr�alablement ouvert, sinon la m�thode renvoie false. De plus, si le nombre d'octets r�ellement envoy� est diff�rent de la taille de la cha�ne de caract�res 'trame', cette m�thode renvoie false.
	  \param trame la cha�ne de caract�re � �mettre.
	  \return Cette m�thode renvoie true en cas de succ�s, false sinon.
	  \sa envoyerCaractere(), lireMessage()
	*/
	bool envoyerTrame(const char trame[]) const;

	//! Emmission d'une cha�ne de caract�res sur le port s�rie.
	/*!
	  Cette m�thode envoie la cha�ne de caract�res 'trame' pass� en argument sur le port s�rie. Le port s�rie doit �tre pr�alablement ouvert, sinon la m�thode renvoie false. De plus, si le nombre d'octets r�ellement envoy� est diff�rent de la taille de la cha�ne de caract�res 'trame', cette m�thode renvoie false.
	  \param trame la cha�ne de caract�re � �mettre.
	  \return Cette m�thode renvoie true en cas de succ�s, false sinon.
	  \sa envoyerCaractere(), lireMessage()
	*/
	bool envoyerTrame(string trame) const;

	//! Lecture d'un message sur le port s�rie.
	/*!
	  Cette m�thode lit un message sur le port s�rie et le stocke dans la cha�ne de caract�re 'message'. Le port s�rie doit �tre pr�alablement ouvert, sinon la m�thode renvoie une valeur n�gative.
	  \param message la cha�ne de caract�re qui contiendra le message � lire.
	  \param tailleMaximaleDuMessage la taille maximale du message � recevoir (correspond g�n�ralement au nombre de caract�res de la cha�ne de caract�res de recevant ce message)
	  \return Cette m�thode renvoie le nombre de caract�res lus en cas de succ�s, une valeur n�gative sinon.
	  \sa envoyerTrame(), lireMessage()
	*/
	int lireMessage(char message[], int tailleMaximaleDuMessage) const;

    //! Lecture d'un message sur le port s�rie.
    /*!
      Cette m�thode lit un message sur le port s�rie et le renvoie.
caract�res de recevant ce message)
      \return Cette m�thode renvoie le message lu, une cha�ne vide sinon.
      \sa envoyerTrame(), lireMessage()
    */
	string lireMessage() const;

    // Tests d'am�lioration de la m�thode lireMessage().
    //int lireMessageMieux(char message[], int tailleMaximaleDuMessage) const;
    //int lireMessageACK(char message[], int tailleMaximaleDuMessage) const;

private:
    //! Le nom du port s�rie.
    /*! Cette cha�ne de caract�res contient le nom du port s�rie. Le constructeur initialise cette cha�ne � "". Le port s�rie virtuel utilis� se nommera souvent "/dev/ttyUSB0". C'est l'utilisateur qui fixe le nom de ce port par la m�thode ouvrir().*/
    string m_nomDuPortSerie;
    //! Le descripteur de fichier.
    /*! Le port s�rie �tant vu comme un fichier, ouvrir la communication sur le port s�rie revient � ouvrir un fichier. Si l'ouverture est r�ussie, l'OS nous fournit le descripteur de ce fichier (une valeur enti�re) qui doit �tre utilis�e par la suite pour toutes les op�rations d'�criture, de lecture ou m�me de fermeture de ce fichier.*/
    int m_descripteurFichier;
    //! Bool�en indiquant si le port s�rie est ouvert.
    /*! Lors de la construction, ce bool�en est plac� � false. Si l'ouverture du fichier est r�ussie, il passe alors � true. Il vaudra � nouveau false apr�s la fermeture.*/
    bool m_estOuvert;

};
#endif
