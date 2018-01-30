#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define MAX 0
#define MIN 1

void affichage(case_t mat[N][N]){
	
}

void init_mur(case_t mat[N][N]){ /*initialisation des bordures de la map*/
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
}

void gener_tab(case_t mat[N][N]){ /*generation de l'interieur de la map*/
	
	mur_t mur;
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
					
	
			mat[i][j].mur.murN= (srand() % (MAX - MIN + 1)) + MIN;  //random pour definir si mur ou non
			mat[i][j].mur.murN= (srand() % (MAX - MIN + 1)) + MIN;
			mat[i][j].mur.murN= (srand() % (MAX - MIN + 1)) + MIN;
			mat[i][j].mur.murN= (srand() % (MAX - MIN + 1)) + MIN;
		}
	}
	
	
}
