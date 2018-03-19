#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "matrice.h"

/**
* \file canard.c
* \brief Programme sur tout ce qui concerne les canards
* \author VAIDIE Camille
* \version 1.0
* \date 20 Février 2018
*/ 

/** \fn void init_canard(caract_mat_t)*/
void init_canard(caract_mat_t * cmat){
	int x;
	int y;
	for(int i=0; i<nb_max;i++){
		x=(rand()%(cmat->taille_mat_x )); //On choisi une case au hasard dans la matrice
		y=(rand()%(cmat->taille_mat_y ));
		if(est_dans_matrice(cmat,x,y)){
			cmat->matrice[x][y].nb_occupant++; //on ajoute un canard a cette case et on l'initialise
			cmat->matrice[x][y].tab_canard[cmat->matrice[x][y].nb_occupant-1].nourriture=50;
			cmat->matrice[x][y].tab_canard[cmat->matrice[x][y].nb_occupant-1].etat=1;
		}
		
	}
}

/** \fn void presence_canard(caract_mat_t)*/
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
/** \fn void nombre_canard(caract_mat_t)*/
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
