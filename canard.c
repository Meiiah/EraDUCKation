#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "matrice.h"

void init_canard(caract_mat_t * cmat){
	int x;
	int y;
	for(int i=0; i<nb_max;i++){
		
		x=(rand()%(cmat->taille_mat_x ));
		y=(rand()%(cmat->taille_mat_y ));
		if(est_dans_matrice(cmat,x,y)){
			cmat->matrice[x][y].nb_occupant++;
			cmat->matrice[x][y].tab_canard[cmat->matrice[x][y].nb_occupant-1].nourriture=50;
			cmat->matrice[x][y].tab_canard[cmat->matrice[x][y].nb_occupant-1].etat=1;
		}
		
	}
}


int presence_canard(caract_mat_t * cmat){ // retourne 1 si il reste des canards
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

int nombre_canard(caract_mat_t * cmat){
	int cpt=0;
	int i,j;
	for(i=0;i<cmat->taille_mat_x;i++){
		for(j=0;j<cmat->taille_mat_y;j++){
			cpt += cmat->matrice[i][j].nb_occupant;
		}
	}
	return cpt;
}
