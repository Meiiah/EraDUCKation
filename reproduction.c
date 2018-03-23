#include "struct.h"
#include "matrice.h"
#include "joueur.h"
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
		if(cmat->matrice[*i][*j].nb_occupant>8){ // Vu qu on ajoute un canard et qu on a 9 places il faut qu il y ait maximum 8 occupants
			fprintf(stderr,"\n x %i y %i\n",*i,*j);
			
			if(est_dans_matrice(cmat,*i-cpt,*j)){
				fprintf(stderr,"\n1\n");
				if( cmat->matrice[*i-cpt][*j].nb_occupant<9){
					*i=*i-cpt;
					return 1;
				}else if(est_dans_matrice(cmat,*i-cpt,*j-cpt)){
					fprintf(stderr,"\n2\n");
					if(cmat->matrice[*i-cpt][*j-cpt].nb_occupant<9){
						*i=*i-cpt;
						*j=*j-cpt;
						return 1;
					}else if(est_dans_matrice(cmat,*i,*j-cpt)){
						fprintf(stderr,"\n3\n");
						if( cmat->matrice[*i][*j-cpt].nb_occupant<9){
							*j=*j-cpt;
							return 1;
						}else if(est_dans_matrice(cmat,*i+cpt,*j-cpt) ){
							fprintf(stderr,"\n4\n");
							if( cmat->matrice[*i+cpt][*j-cpt].nb_occupant<9){
								*i=*i+cpt;
								*j=*j-cpt;
								return 1;
							}else if(est_dans_matrice(cmat,*i+cpt,*j) ){
								fprintf(stderr,"\n5\n");
								if( cmat->matrice[*i+cpt][*j].nb_occupant<9){
									*i=*i+cpt;
									return 1;
								}else if(est_dans_matrice(cmat,*i+cpt,*j+cpt) ){
									fprintf(stderr,"\n6\n");
									if( cmat->matrice[*i+cpt][*j+cpt].nb_occupant<9){
										*i=*i+cpt;
										*j=*j+cpt;
										return 1;
									}else if(est_dans_matrice(cmat,*i,*j+cpt) ){
										fprintf(stderr,"\n7\n");
										if( cmat->matrice[*i][*j+cpt].nb_occupant<9){
											*j=*j+cpt;
											return 1;
										}else if(est_dans_matrice(cmat,*i-cpt,*j+cpt) ){
											fprintf(stderr,"\n8\n");
											if( cmat->matrice[*i-cpt][*j+cpt].nb_occupant<9){
												*i=*i-cpt;
												*j=*j+cpt;
												return 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else{
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
			fprintf(stderr,"\nDEB case x: %i   y : %i\n",i, j);

			//Parcours du nombre de canard//
			compteur=0;//compteur du nombre de canard favorable a la reproduction//
			for(k=0;k<nb_max;k++){
				if(mat->matrice[i][j].tab_canard[k].nourriture>=nourriture_accouplement && mat->matrice[i][j].tab_canard[k].etat==1 ){
					//Si un canard adulte peut se reproduire
					int rande=rand()%5; 
					if(rande<=1){// il a 20%de chance de le faire ( 0 ou 1)
						compteur++;
					}
				}
			}
			
			compteur/=2;// On compte le nombre de bébé canards à créer
			int x,y;
			for(l=0;l<compteur;l++){//pour chaque canard à naitre a partir de cette case
				x=i;
				y=j;
				fprintf(stderr,"\nDEB ou pondre x: %i   y : %i\n",i, j);
				ou_pondre(mat, &x, &y);//on cherche où pondre
				fprintf(stderr,"\nFIN ou pondre");

				
				mat->matrice[x][y].tab_canard[mat->matrice[x][y].nb_occupant].etat=0;
				mat->matrice[x][y].tab_canard[mat->matrice[x][y].nb_occupant].nourriture=50;
				mat->matrice[x][y].nb_occupant++; //Ajout du nouveau canard//
				ajout_score(25,&joueur,&joueur2);
			}
		}fprintf(stderr,"\nFIN case x: %i   y : %i\n",i, j);
	}
}
