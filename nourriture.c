#include <stdlib.h>
#include "struct.h"
#include "matrice.h"
#include "outils.h"

void spawn_nourriture(caract_mat_t * cmat,int nourriture_genere){
	int i,k;
		
	int random_x;
	int random_y;
	int random_nbre_apparition=rand()%5;//random pour le nombre d'appartion de nourriture
	for(i=0;i<random_nbre_apparition;i++){ 
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);
		
		//spawn de nourriture
		cmat->matrice[random_x][random_y].pres_nourriture=nourriture_genere;
	}
}
