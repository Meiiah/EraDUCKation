#include "struct.h"
#include "joueur.h"
#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>
/**
* \file reproduction.c
* \brief Programme comprennant la reproduction des canards
* \author VAIDIE Camille
* \version 1.0
* \date 20 Février 2018
*/ 

int ou_pondre(caract_mat_t * cmat, int * i, int * j){
	int cpt =1;
	while(1){
		if(cmat->matrice[*i][*j].nb_occupant>10){
			if(est_dans_matrice(cmat,*i-cpt,*j) && cmat->matrice[*i-cpt][*j].nb_occupant<10){
				*i=*i-cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i-cpt,*j-cpt) && cmat->matrice[*i-cpt][*j-cpt].nb_occupant<10){
				*i=*i-cpt;
				*j=*j-cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i,*j-cpt) && cmat->matrice[*i][*j-cpt].nb_occupant<10){
				*j=*j-cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i+cpt,*j-cpt) && cmat->matrice[*i+cpt][*j-cpt].nb_occupant<10){
				*i=*i+cpt;
				*j=*j-cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i+cpt,*j) && cmat->matrice[*i+cpt][*j].nb_occupant<10){
				*i=*i+cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i+cpt,*j+cpt) && cmat->matrice[*i+cpt][*j+cpt].nb_occupant<10){
				*i=*i+cpt;
				*j=*j+cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i,*j+cpt) && cmat->matrice[*i][*j+cpt].nb_occupant<10){
				*j=*j+cpt;
				return 1;
			}else if(est_dans_matrice(cmat,*i-cpt,*j+cpt) && cmat->matrice[*i-cpt][*j+cpt].nb_occupant<10){
				*i=*i-cpt;
				*j=*j+cpt;
				return 1;
			}
		
		}else{
			return 1;
		}
		cpt++;
	}
}

/** \fn void reproduction(caract_mat_t,int,joueur_t,joueur_t)*/
void reproduction(caract_mat_t * mat, int nourriture_accouplement,joueur_t joueur,joueur_t joueur2){
	int i;
	int j;
	int k;
	int l;
	int compteur;
	for(i=0;i<mat->taille_mat_x;i++){
		for(j=0;j<mat->taille_mat_y;j++){
			//Parcours du nombre de canard//
			compteur=0;//compteur du nombre de canard favorable a la reproduction//
			for(k=0;k<nb_max;k++){
				if(mat->matrice[i][j].tab_canard[k].nourriture>=nourriture_accouplement && mat->matrice[i][j].tab_canard[k].etat==1 ){
					if
					compteur++;
				}
			}
			
			compteur/=2;
			int x=i, y=j;
			for(l=0;l<compteur;l++){
				//ou_pondre(mat, &x, &y);
				fprintf(stderr,"x %i y %i",x,y);
				mat->matrice[x][y].nb_occupant++; //Ajout des nouveaux canards//
				mat->matrice[x][y].tab_canard[l].etat=1;
				mat->matrice[x][y].tab_canard[l].nourriture=100;
				ajout_score(25,joueur,joueur2);
			}
		}
	}
}
