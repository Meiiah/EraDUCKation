/**
 * \file canard.c
 * \brief Fonctions a propos du canard
 * \author Camille VAIDIE
 * \version 1.1
 * \date 20 fevrier 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "matrice.h"

/**\fn canard_t canard_vide(void) */
canard_t canard_vide(void){/**	renvoit un canard inexistant*/
    canard_t canard;
    canard.nourriture =0;
    canard.etat = -1;
    return canard;
}


/** \fn void init_canard(caract_mat_t * cmat) */
void init_canard(caract_mat_t * cmat){/** met des canards dans des cases aléatoire */
	int x;
	int y;
	int i;
	for(i=0; i<nb_max;i++){

		x=(rand()%(cmat->taille_mat_x ));
		y=(rand()%(cmat->taille_mat_y ));
		if(est_dans_matrice(cmat,x,y)){
			cmat->matrice[x][y].nb_occupant++;
			cmat->matrice[x][y].tab_canard[cmat->matrice[x][y].nb_occupant-1].nourriture=20;
			cmat->matrice[x][y].tab_canard[cmat->matrice[x][y].nb_occupant-1].etat=1;
		}

	}
}

/** int presence_canard(caract_mat_t * cmat) */
int presence_canard(caract_mat_t * cmat){ /** retourne 1 si il reste des canards */
	int i,j;
	for(i=0;i<cmat->taille_mat_x;i++){
		for(j=0;j<cmat->taille_mat_y;j++){
			if(cmat->matrice[i][j].nb_occupant>0){
				if(est_dans_matrice(cmat,i,j)){
					return 1;
				}
			}
		}
	}
	return 0;
}

/** \fn int nombre_canard(caract_mat_t * cmat) */
int nombre_canard(caract_mat_t * cmat){/** compte les canards présents dans la matrice */
	int cpt=0;
	int i,j;
	for(i=0;i<cmat->taille_mat_x;i++){
		for(j=0;j<cmat->taille_mat_y;j++){
			cpt += cmat->matrice[i][j].nb_occupant;
		}
	}
	return cpt;
}

/** \fn int oeuf_to_adulte(caract_mat_t * cmat) */
int oeuf_to_adulte(caract_mat_t * cmat){/** change les canards à l'état d'oeuf en canards à l'état adulte */
	int i,j, k;
	for(i=0;i<cmat->taille_mat_x;i++){
		for(j=0;j<cmat->taille_mat_y;j++){
			for(k=0; k< cmat->matrice[i][j].nb_occupant; k++){
				if(cmat->matrice[i][j].tab_canard[k].etat == 0) //si c est un oeuf
					cmat->matrice[i][j].tab_canard[k].etat = 1;// il devient adulte
			}
		}
	}return 1;
}
