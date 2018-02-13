#include <stdio.h>
#include <stdlib.h>
#define N 15
case_t matrice[taille_mat][taille_mat];

void init_canard(){
	int x;
	int y;
	for(int i=0; i<N,i++){
		x=(rand() % (taille_mat + 1));
		y=(rand() % (taille_mat + 1));
		matrice[x][y].nb_occupant++;
		matrice[x][y].tab_canard[nb_occupant-1].nourriture=50;
		matrice[x][y].tab_canard[nb_occupant-1].etat=0;
	}
}