#include "struct.h"
#define taille_mat 20 //taille de la matrice//
#define pourc_nourriture 50 //pourcentage de nourriture pour reproduction//
case_t matrice[taille_mat][taille_mat];

void init_matrice(){
	int i;
	int j;
	int k;	
	for(i=0;i<taille_mat;i++){
		for(j=0;j<taille_mat;j++){
			//Initialisation des murs a 0 (inexistant)//
			matrice[i][j].mur.murN=0;
			matrice[i][j].mur.murS=0;
			matrice[i][j].mur.murE=0;
			matrice[i][j].mur.murO=0;
			
			//Initialisation des Canards a 0 //
			for(k=0;k<nb_max;k++){
				matrice[i][j].tab_canard[k].nourriture=0;
				matrice[i][j].tab_canard[k].etat=-1;
			}
			
			//Initilisation nombre de canard//
			matrice[i][j].nb_occupant=0;
			//Initialisation de nourriture//
			matrice[i][j]pres_nourriture=0;
		}
	}
}

void reproduction(){
	int i;
	int j;
	int k;
	int l;
	int compteur;
	for(i=0;i<taille_mat;i++){
		for(j=0;j<taille_mat;j++){
			//Parcours du nombre de canard//
			compteur=0;//compteur du nombre de canard favorable a la reproduction//
			for(k=0;k<nb_max;k++){
				if(matrice[i][j].tab_canard[k].nourriture>=50){
					compteur++;
				}
			}
			for(l=0;l<compteur/2;l++){
				matrice[i][j].nb_occupant++; //Ajout des nouveaux canards//
				matrice[i][j].tab_canard[l].etat=0;
				matrice[i][j].tab_canard[k].nourriture=100;
			}
		}
	}
}


void pseudo_joueur(char joueur[25]){
	printf("Saisir le pseudo du joueur");
	scanf("%s",joueur);
}
