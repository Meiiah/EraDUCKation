/**
 * \file multijoueur.c
 * \brief Fonctions outils multijoueur
 * \author Maxime.T
 * \version 1.0
 * \date 20 fevrier 2018
*/



#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

typedef enum { bon, mechant }clan_t;

typedef struct joueurm_s{
    clan_t clan;
    char nom [20];
    void (*choix) (void);
}joueur_multi_t;

case_t matrice[5][5];

/*================================================*/
/** \fn joueur_multi_t joueur_gentil(void)*/
joueur_multi_t joueur_gentil(void){ /** initialise un joueur en joueur gentil*/
    joueur_multi_t mem;
    mem.clan = bon;
    mem.choix = choix_bon;
    return mem ;
}
/** \fn joueur_multi_t joueur_mechant(void)*/
joueur_multi_t joueur_mechant(void){ /**initialise un joueur en tant que mechant*/
    joueur_multi_t mem;
    mem.clan = mechant;
    mem.choix = choix_mechant;
    return mem ;
}

/*=======================================================*/


void tour_multijoueur(joueur_multi_t tab[], int tour){
    deplacer();
    //manger et reproduire
    tab[tour%2].choix();
}

/*===============================================*/
/** \fn int qui_commence(void) */
int qui_commence(void){/** demande quel joueur commence */
  	  int tampon;
       printf("Si vous voulez que ce soit le joueur gentil qui commence, tapez 0, pour le mechant,         tapez 1, et si vous voulez que ce soit aleatoire tapez 2\n");
       scanf("%i",&tampon);
       while(tampon <0 || tampon >2){
            printf(" \n entree invalide veuillez de nouveau sesir qui va commencer \n");
            scanf("%i",&tampon);
        }
        if(tampon ==2) tampon = rand()%2;
        return tampon; /** \return renvoit 0 si c est le gentil et 1 si c est le mechant*/
}

/*============================================================*/
/** \fn void init_tab_joueurs(joueur_multi_t * tab, int tampon) */
/** met le premier joueur a jouer en premiere place dans le tableau */

void init_tab_joueurs(joueur_multi_t * tab /** tableau de joueurs */,
						int tampon /** resultat du placement */){

    tab[tampon]= joueur_gentil();    //c est de la logique
    tab[tampon +1 %2] = joueur_mechant();

   //demander les noms

    demander_nom(tab[tampon].nom, tab[tampon+1 %2].nom);
}
/*============================================================*/
/** \fn void main_multijoueur(void) */
void main_multijoueur(void){ /** fait le jeu en multi sur meme pc */
    //variables :
    joueur_multi_t tab[2];
    int tampon;
    //maintenant on initialise l ordre de jeu
    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    /* Tant que les canards sont pas tous morts on fait les tours

    a chaque tour on fait deplacement, choix, on verifie les cond d arret, et on recommence */


}
