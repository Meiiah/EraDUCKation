#include "struct.h"
#include "joueur.h"
#include "matrice.h"
#include <stdio.h>

/**
* \file reproduction.c
* \brief Programme comprennant les piegfes dans le laby
* \author VAIDIE Camille
* \version 1.0
* \date 20 Février 2018
*/ 

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
					compteur++;
				}
			}
			
			compteur/=2;
		
		
			if(//on est trop
			//on regarde a coté (marion a loe droit de pomper sur deplacer.c)
			do{
				if(!est_dans_matrice(i+1,j+1) || matrice[i+1][j+1].nb_occupant>9)
				
			}while(!est_dans_matrice(i,j) || matrice[i][j].nb_occupant>9)
			
			for(l=0;l<compteur;l++){
				
				mat->matrice[i][j].nb_occupant++; //Ajout des nouveaux canards//
				mat->matrice[i][j].tab_canard[l].etat=1;
				mat->matrice[i][j].tab_canard[l].nourriture=100;
				ajout_score(25,joueur,joueur2);
			}
		}
	}
}
