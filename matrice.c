#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

/*definition de la matrice */



void init_matrice(int taille_mat){
	case_t * GT = malloc(sizeof(case_t)*taille_mat*taille_mat);
	matrice =malloc(sizeof(case_t *)*taille_mat);
	int i;
	int taille=taille_mat;
	for(i=0;i<taille_mat;i++){
		matrice[i]=&GT[taille-1];
		taille+=taille;
	}
	
	
}
