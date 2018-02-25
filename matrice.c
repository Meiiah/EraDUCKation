#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

/*definition de la matrice */

void creation_matrice(case_t ** matrice,int taille_mat){
	case_t * GT = malloc(sizeof(case_t)*taille_mat*taille_mat);
	matrice =malloc(sizeof(case_t *)*taille_mat);
	int i;
	int taille=taille_mat;
	for(i=0;i<taille_mat;i++){
		matrice[i]=&GT[taille-1];
		taille+=taille;
	}	
}
