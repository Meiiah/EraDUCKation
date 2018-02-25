#include <stdlib.h>
#include "struct.h"
#include "joueur.h"
#include "outils.h"


/*Evenement mauvais */

void tsunami(case_t ** matrice,int taille_mat, joueur_t joueur,joueur_t joueur2){
	int i,j,k;
	int random_min=rand_map(taille_mat);
	int random_max=rand_map(taille_mat);
	while(random_min>random_max){
		random_min=rand_map(taille_mat);
		random_max=rand_map(taille_mat);
	}
	int align=rand()%1;// 0 pour horizontal 1 pour vertical

	if(align==0){
		for(i=0;i<taille_mat;i++){
			for(j=random_min;j<random_max;j++){
				for(k=0;k<matrice[i][j].nb_occupant;k++){
					matrice[i][j].tab_canard[k].nourriture=0;
					matrice[i][j].tab_canard[k].etat=-1;
					ajout_score(-50,joueur,joueur2);	
				}
				matrice[i][j].nb_occupant=0;
			}
		}
	}
	if(align==1){
		for(i=random_min;i<random_max;i++){
			for(j=0;j<taille_mat;j++){
				for(k=0;k<matrice[i][j].nb_occupant;k++){
					matrice[i][j].tab_canard[k].nourriture=0;
					matrice[i][j].tab_canard[k].etat=-1;	
					ajout_score(-50,joueur,joueur2);
				}
				matrice[i][j].nb_occupant=0;
			}
		}
	}	
}

void tempete(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2){
	int i,j,k;
	int random_min=rand_map(taille_mat);
	int random_max=rand_map(taille_mat);
	while(random_min>random_max){
		random_min=rand_map(taille_mat);
		random_max=rand_map(taille_mat);
	}

	for(i=random_min;i<random_max;i++){
		for(j=random_min;j<random_max;j++){
			for(k=0;k<matrice[i][j].nb_occupant;k++){
				matrice[i][j].tab_canard[k].nourriture=0;
				matrice[i][j].tab_canard[k].etat=-1;	
				ajout_score(-50,joueur,joueur2);
			}
			matrice[i][j].nb_occupant=0;
		}
	}
}

int famine(int nourriture_genere){
	return nourriture_genere/=1.5;
	
}

int reproduction_ralentie(int nourriture_accouplement){
	return nourriture_accouplement*=1.5; //variable de deplacer.c 
}

void apparition_predateur(case_t ** matrice,int taille_mat, joueur_t joueur, joueur_t joueur2){
	int i,k;	
	int random_x;
	int random_y;
	int random_nbre_predateur=rand()%5;//random pour le nombre de prédateur
	for(i=0;i<random_nbre_predateur;i++){ //boucle pour tuer des canards en fonction du nombre de prédateur
		random_x=rand_map(taille_mat);
		random_y=rand_map(taille_mat);
		//destruction des canards
		for(k=0;k<matrice[random_x][random_y].nb_occupant;k++){
			matrice[random_x][random_y].tab_canard[k].nourriture=0;
			matrice[random_x][random_y].tab_canard[k].etat=-1;	
			ajout_score(-100,joueur,joueur2);
		}
		matrice[random_x][random_y].nb_occupant=0;	
	}
}

/* Evenement bon */

int reproduction_acceleree(int nourriture_accouplement){
	return nourriture_accouplement/=1.5;//variable de deplacer.c 
}

int plus_nourriture(int nourriture_genere){
	return nourriture_genere*=1.5;//generation de nourriture plus élevée
}

void joker_nourriture(case_t ** matrice,int taille_mat){
	int i,j,k;
	for(i=0;i<taille_mat;i++){//balayage de toute la matrice
		for(j=0;j<taille_mat;j++){
			for(k=0;k<taille_mat;k++){
				matrice[i][j].tab_canard[k].nourriture=100;
			}
		}
	}
}
//ajout au score
void liberation_canard(case_t ** matrice,int taille_mat, joueur_t joueur, joueur_t joueur2){
	int i,k;	
	int random_x;
	int random_y;
	int random_nbre_de_canard_liberer=rand()%5;//random pour le nombre de canard
	for(i=0;i<random_nbre_de_canard_liberer;i++){ //boucle pour tuer des canards en fonction du nombre de prédateur
		random_x=rand_map(taille_mat);
		random_y=rand_map(taille_mat);
		//sortie des canards
		for(k=0;k<matrice[random_x][random_y].nb_occupant;k++){
			matrice[random_x][random_y].tab_canard[k].nourriture=0;
			matrice[random_x][random_y].tab_canard[k].etat=-1;	
			ajout_score(500,joueur,joueur2); //ajout de 500 points par libération
		}
		matrice[random_x][random_y].nb_occupant=0;	
	}
}

void canard_invincible(){
	/*prend un canard qui ne peut pas mourir*/
}


