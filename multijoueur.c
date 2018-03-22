/**
 * \file multijoueur.c
 * \brief Fonctions outils multijoueur
 * \author Maxime.T
 * \version 1.1
 * \date 20 fevrier 2018
*/



#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "matrice.h"
#include "piege.h"
#include "nourriture.h"
#include "joueur.h"
#include "canard.h"
#include "deplacer.h"
#include "deplacer_multi.h"
#include "labyrinthe.h"

typedef enum { bon, mechant }clan_t;

typedef struct joueurm_s{

    joueur_t joueur;
    clan_t clan;
    char nom [20];
    void (*choix) (caract_mat_t *,joueur_t , joueur_t , int* , int* );
}joueur_multi_t;


/*================================================*/
/** \fn joueur_multi_t joueur_gentil(void)*/
joueur_multi_t joueur_gentil(){ /** initialise un joueur en joueur gentil*/
    joueur_multi_t mem;
    mem.clan = bon;
    mem.choix = choix_bon;
    return mem ;
}
/** \fn joueur_multi_t joueur_mechant(void)*/
joueur_multi_t joueur_mechant(){ /**initialise un joueur en tant que mechant*/
    joueur_multi_t mem;
    mem.clan = mechant;
    mem.choix = choix_mechant;
    return mem ;
}

/*=======================================================*/


void tour_multijoueur(caract_mat_t * cmat, int * nourriture_genere,int * nourriture_accouplement, joueur_multi_t tab[], int tour, int tampon){
    spawn_nourriture(cmat, rand()%5+1);
	piege(cmat);
	affichage_laby(cmat);
    deplacer(cmat,*nourriture_accouplement, *nourriture_genere, tab[tampon].joueur,tab[(tampon +1)%2].joueur);
    printf("C est le tour de %s", tab[tour%2].joueur.nom_joueur);
    tab[tour%2].choix(cmat,tab[tampon].joueur,tab[(tampon +1)%2].joueur, nourriture_genere, nourriture_accouplement);
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

    caract_joueur(tab[0].joueur);
	caract_joueur(tab[1].joueur);
}
/*============================================================*/
/** \fn void main_multijoueur(void) */
int main_multijoueur(caract_mat_t * cmat, int nourriture_genere, int nourriture_accouplement){ /** fait le jeu en multi sur meme pc */
    //variables :
    joueur_multi_t tab[2];
    int tampon;
    //maintenant on initialise l ordre de jeu
    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    /* Tant que les canards sont pas tous morts on fait les tours
	 a chaque tour on fait deplacement, choix, on verifie les cond d arret, et on recommence */
	
	int nb_gen=0; // Compteur de génération
	
	while ( nb_gen<100 && presence_canard(cmat)==1){ // fin du jeu
		
		tour_multijoueur(cmat,&nourriture_genere,&nourriture_accouplement, tab, nb_gen, tampon);
		
		ajout_score(100,tab[tampon].joueur,tab[(tampon +1)%2].joueur);
	
		nb_gen++;
		printf("Score %s : %i\n",tab[0].joueur.nom_joueur,tab[0].joueur.score);
		printf("Score %s : %i\n",tab[1].joueur.nom_joueur,tab[0].joueur.score);
		printf("Nourriture accouplement: %i\n",nourriture_accouplement);
		printf("Nourriture générée: %i\n",nourriture_genere);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));
		
	}
	return 1;

}
