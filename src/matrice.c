#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "matrice.h"

/**
 * \file matrice.c
 * \brief Initialisation matrice
 * \author PHILLIPE Marion
 * \version 1.1
 * \date 19 Mars 2018
*/


void detruire_Cmatrice(caract_mat_t * cmat){
	if(cmat){
		if( cmat->matrice!=NULL){
			
			free(cmat->matrice[0]);
			
			free(cmat->matrice);
		}
	
		
		free(cmat);
		cmat = NULL;
	}
}

/** \fn int est_dans_matrice(caract_mat_t,int,int)*/
int est_dans_matrice(caract_mat_t * cmat,int x, int y){
	return(x>=0 && x<cmat->taille_mat_x && y>=0 && y<cmat->taille_mat_y);
}

/** \fn void creation_matrice(caract_mat_t)*/
caract_mat_t *  creation_matrice(int x, int y){/*definition de la matrice */
	caract_mat_t *cmat = malloc(sizeof(caract_mat_t));
	cmat->taille_mat_x=x;
	cmat->taille_mat_y=y;
	
	case_t * GT = malloc(sizeof(case_t)*cmat->taille_mat_x*cmat->taille_mat_y);
	cmat->matrice =malloc(sizeof(case_t *)*cmat->taille_mat_y);
	int i;
	int taille=cmat->taille_mat_x;
	
	for(i=0;i<cmat->taille_mat_y;i++){
		cmat->matrice[i]=&GT[taille*i]; 
	}
	return cmat;	
}

/** \fn void init_matrice(caract_mat_t)*/
void init_matrice(caract_mat_t * cmat){
	int i;
	int j;
	int k;	
	
	for(i=0;i<cmat->taille_mat_x;i++){
		for(j=0;j<cmat->taille_mat_y;j++){
			if(est_dans_matrice(cmat,i,j)){
				                             
				//Initialisation des Canards a l'état -1 //
				for(k=0;k<nb_max;k++){
					cmat->matrice[i][j].tab_canard[k].nourriture=0;
					cmat->matrice[i][j].tab_canard[k].etat=-1;
				}
			
				//Initilisation nombre de canard//
				cmat->matrice[i][j].nb_occupant=0;
				//Initialisation de nourriture//
				cmat->matrice[i][j].pres_nourriture=0;
				cmat->matrice[i][j].pres_piege=0;
			}else{
				
				exit(0);
			}
		}
	}
} 	

