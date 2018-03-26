
#ifndef __OUTILS_RESEAU_H__
#define __OUTILS_RESEAU_H__

typedef enum {Debut_message = -1, fin message 42}protocole_t;

 void envoyer_int(int socket, int valeur);
 void recevoir_int(int socket, int * valeur);
 
 
 int demander_qui_commence(void);/* Demande si la personne veut commencer ou non */
 void saisir_role(int * role);
 void afficher_role(int role);/** affiche le role du joueur */
 
 void menu_multi_reseau(void);
 
#endif // __OUTILS_RESEAU_H__
