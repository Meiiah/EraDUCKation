#include <stdlib.h>
#include "struct.h"
#include "outils.h"

void spawn_nourriture(case_t ** matrice,int taille_mat,int nourriture_genere){
	int i,k;
		
	int random_x;
	int random_y;
	int random_nbre_apparition=rand()%5;//random pour le nombre d'appartion de nourriture
	for(i=0;i<random_nbre_apparition;i++){ 
		random_x=rand_map(taille_mat);
		random_y=rand_map(taille_mat);
		//spawn de nourriture
		
		matrice[random_x][random_y].pres_nourriture=nourriture_genere;
			
	}
}
