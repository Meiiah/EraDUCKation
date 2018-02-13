#include "struct.h"
#include <stdio.h>
#define taille_mat 20 //taille de la matrice//
case_t matrice[taille_mat][taille_mat];

void piege(){ //fonction piege
	int i;
	int j;
	int x=(rand() % (taille_mat)); //place en random un piege dans la matrice
	int y=(rand() % (taille_mat));
	matrice[x][y].pres_piege=1; // 1: presence piege , 0: pas de piege
}

void presence_piege(){ // fonction presence de piege
	for(i=0;i<taille_mat;i++){ //parcour de la matrice
		for(j=0;j<taille_mat;j++){
			if(matrice[i][j].pres_piege==1 && matrice[i][j].nb_occupant>0){ // 1: piege present)
				for(int k=0; k<matrice[i][j].nb_occupant;k++){
					matrice[i][j].tab_canard[k].nourriture=0;
					matrice[i][j].tab_canard[k].etat=-1;
				}
				matrice[i][j].pres_piege=0;
				matrice[i][j].nb_occupant=0; // Mort des canards sur cette case
			}
		}
	}
}