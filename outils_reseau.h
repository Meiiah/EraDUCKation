
#ifndef __OUTILS_RESEAU_H__
#define __OUTILS_RESEAU_H__
#include "multijoueur.h"

typedef enum {Debut_message = -1 , fin_message = 42 , fin_transmission = 666}protocole_t;

typedef struct joueur_res_s{

    joueur_t joueur;
    clan_t clan;
    void (*choix) (int, caract_mat_t *,joueur_t *, joueur_t * , int* , int*,int );
}joueur_reseau_t;

 void envoyer_int(int socket, int valeur);
 void recevoir_int(int socket, int * valeur);


 int demander_qui_commence(void);/* Demande si la personne veut commencer ou non */
 void saisir_role(int * role);
 void afficher_role(int role);/** affiche le role du joueur */

 void menu_multi_reseau(void);

#endif // __OUTILS_RESEAU_H__
