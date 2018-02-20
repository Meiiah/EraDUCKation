#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#define N 15

void init_canard(){
	int x;
	int y;
	for(int i=0; i<N;i++){
		x=(rand()%(taille_mat + 1));
		y=(rand()%(taille_mat + 1));
		matrice[x][y].nb_occupant++;
		matrice[x][y].tab_canard[(*matrice)->nb_occupant-1].nourriture=50;
		matrice[x][y].tab_canard[(*matrice)->nb_occupant-1].etat=0;
	}
}


int presence_canard(){ // retourne 1 si il reste des canards
	int i,j;
	for(i=0;i<taille_mat;i++){
		for(j=0;j<taille_mat;j++){
			if(matrice[i][j].nb_occupant>0){
				return 1;	
			}
		}
	}
	return 0;
}
