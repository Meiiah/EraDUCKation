#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "matrice.h"

int est_dans_matrice(caract_mat_t * cmat,int x, int y){
	return(x>0 || x<cmat->taille_mat_x || y>0 || y<cmat->taille_mat_y);
}

/*definition de la matrice */
void  creation_matrice(caract_mat_t * cmat){
	case_t * GT = malloc(sizeof(case_t)*cmat->taille_mat_x*cmat->taille_mat_y);
	cmat->matrice =malloc(sizeof(case_t *)*cmat->taille_mat_y);
	int i;
	int taille=cmat->taille_mat_x;
	
	for(i=0;i<cmat->taille_mat_y;i++){
		cmat->matrice[i]=&GT[taille*i]; 
	}	
}

void init_matrice(caract_mat_t * cmat){
	int i;
	int j;
	int k;	
	int nb_max_de_canard=5;
	for(i=0;i<cmat->taille_mat_x;i++){
		for(j=0;j<cmat->taille_mat_y;j++){
			if(est_dans_matrice(cmat,i,j)){
				                             
				//Initialisation des Canards a 0 //
				for(k=0;k<nb_max_de_canard;k++){
					cmat->matrice[i][j].tab_canard[k].nourriture=0;
					cmat->matrice[i][j].tab_canard[k].etat=-1;
				}
			
				//Initilisation nombre de canard//
				cmat->matrice[i][j].nb_occupant=0;
				//Initialisation de nourriture//
				cmat->matrice[i][j].pres_nourriture=0;
				cmat->matrice[i][j].pres_piege=0;
			}else{
				printf("ERREUR - sortie de matrice : fonction init_matrice dans matrice.c");
			}
		}
	}
}

