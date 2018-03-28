#include "struct.h"
#include "matrice.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
/**
* \file reproduction.c
* \brief Programme comprennant la reproduction des canards
* \author VAIDIE Camille, PHILIPPE Marion
* \version 1.0
* \date 20 Février 2018
*/ 

int ou_pondre(caract_mat_t * cmat, int * i, int * j){
	
	int cpt =1;
	//boucle pour parcourir en rond la matrice
	while(1){ 
		// Vu qu on ajoute un canard et qu on a 9 places il faut qu il y ait maximum 8 occupants
		if(cmat->matrice[*i][*j].nb_occupant>8){ 
			//si la case à coté est dans la matrice
			if(est_dans_matrice(cmat,*i-cpt,*j)){
				//et qu'elle contient moins de 9 canards
				if( cmat->matrice[*i-cpt][*j].nb_occupant<9){
					//on renvoit : pondre dans cette case là
					*i=*i-cpt;
					return 1;
				}else if(est_dans_matrice(cmat,*i-cpt,*j-cpt)){
					if(cmat->matrice[*i-cpt][*j-cpt].nb_occupant<9){
						*i=*i-cpt;
						*j=*j-cpt;
						return 1;
					}else if(est_dans_matrice(cmat,*i,*j-cpt)){
						if( cmat->matrice[*i][*j-cpt].nb_occupant<9){
							*j=*j-cpt;
							return 1;
						}else if(est_dans_matrice(cmat,*i+cpt,*j-cpt) ){
							if( cmat->matrice[*i+cpt][*j-cpt].nb_occupant<9){
								*i=*i+cpt;
								*j=*j-cpt;
								return 1;
							}else if(est_dans_matrice(cmat,*i+cpt,*j) ){
								if( cmat->matrice[*i+cpt][*j].nb_occupant<9){
									*i=*i+cpt;
									return 1;
								}else if(est_dans_matrice(cmat,*i+cpt,*j+cpt) ){
									if( cmat->matrice[*i+cpt][*j+cpt].nb_occupant<9){
										*i=*i+cpt;
										*j=*j+cpt;
										return 1;
									}else if(est_dans_matrice(cmat,*i,*j+cpt) ){
									
										if( cmat->matrice[*i][*j+cpt].nb_occupant<9){
											*j=*j+cpt;
											return 1;
										}else if(est_dans_matrice(cmat,*i-cpt,*j+cpt) ){	
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
			//Si la case de base n'est pas pleine, on pond où sont les parents
			return 1;
		}
		//Si la premiere boucle est pleine, on regarde sur la boucle suivante
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
			for(k=0;k<mat->matrice[i][j].nb_occupant;k++){
				
				if(mat->matrice[i][j].tab_canard[k].nourriture>=nourriture_accouplement && mat->matrice[i][j].tab_canard[k].etat==1 ){
					//Si un canard adulte peut se reproduire
					int rande=rand()%5; 
					
					if(rande<=1){// il a 40%de chance de le faire ( 0 ou 1)
						compteur++;
					}
				}
			}
			
			compteur/=2;// On compte le nombre de bébé canards à créer
			int x,y;
			for(l=0;l<compteur;l++){//pour chaque canard à naitre a partir de cette case
				x=i;
				y=j;
			
				ou_pondre(mat, &x, &y);//on cherche où pondre
	
				mat->matrice[x][y].tab_canard[mat->matrice[x][y].nb_occupant].etat=0;
				mat->matrice[x][y].tab_canard[mat->matrice[x][y].nb_occupant].nourriture=50;
				mat->matrice[x][y].nb_occupant++; //Ajout du nouveau canard//
				ajout_score(25,&joueur,&joueur2);
			}
		}
	}
}
