#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "matrice.h"

void piege(caract_mat_t * cmat){ //fonction piege
	int x=(rand() % (cmat->taille_mat_x)); //place en random un piege dans la matrice
	int y=(rand() % (cmat->taille_mat_y));
	if(est_dans_matrice(cmat,x,y)){
		cmat->matrice[x][y].pres_piege=1; // 1: presence piege , 0: pas de piege
	}else{
		printf("ERREUR - sortie de matrice : fonction piege dans piege.c");
	}
}

void presence_piege(caract_mat_t * cmat){ // fonction presence de piege
	int i,j;
	for(i=0;i<cmat->taille_mat_x;i++){ //parcour de la matrice
		for(j=0;j<cmat->taille_mat_y;j++){
			if(est_dans_matrice(cmat,i,j)){
				if(cmat->matrice[i][j].pres_piege==1 && cmat->matrice[i][j].nb_occupant>0){ // 1: piege present)
					for(int k=0; k<cmat->matrice[i][j].nb_occupant;k++){
						cmat->matrice[i][j].tab_canard[k].nourriture=0;
						cmat->matrice[i][j].tab_canard[k].etat=-1;
					}
					cmat->matrice[i][j].pres_piege=0;
					cmat->matrice[i][j].nb_occupant=0; // Mort des canards sur cette case
				}
			}else{
				printf("ERREUR - sortie de matrice : fonction presence_piege dans piege.c");
			}
		}
	}
}
