#include <stdlib.h>
#include "struct.h"
#include "matrice.h"
#include "joueur.h"
#include "outils.h"
#include <stdio.h>
#define M 10


/**
 * \file jeu_solo.c
 * \brief programme des evenements possible sur le laby
 * \author PHILLIPE Marion
 * \version 1.0
 * \date 19 Mars 2018
*/



int (*mauvais[M])(caract_mat_t *, joueur_t*,joueur_t*,int*,int*); /*tableau de pointeur sur les fonctions mauvaises*/
int (*bon[M])(caract_mat_t *, joueur_t*,joueur_t*,int*,int*); /*tableau de pointeur sur les fonctions bonnes*/

/*Evenement mauvais */
/** \fn int tsunami(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int tsunami(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	int i,j,k;
	int random_min=rand_map(cmat->taille_mat_x);
	int random_max=rand_map(cmat->taille_mat_y);
	// choisit un random_min plus petit que random_max
	while(random_min>random_max){
		random_min=rand_map(cmat->taille_mat_x);
		random_max=rand_map(cmat->taille_mat_y);
	}
	int align=rand()%1;// 0 pour horizontal 1 pour vertical

	//choix horizontal
	if(align==0){
		// prend toute la taille en horizontal
		for(i=0;i<cmat->taille_mat_x;i++){
			//et prend une tranche aléatoire de la matrice verticalement
			for(j=random_min;j<random_max;j++){
				//Destruction des canards
				for(k=0;k<cmat->matrice[i][j].nb_occupant;k++){
					cmat->matrice[i][j].tab_canard[k].nourriture=0;
					cmat->matrice[i][j].tab_canard[k].etat=-1;
					ajout_score(-50,joueur,joueur2);	
				}
				cmat->matrice[i][j].nb_occupant=0;
			}
		}
	}
	//choix vertical
	if(align==1){
		//prend une tranche aléatoire de la matrice horitonzal
		for(i=random_min;i<random_max;i++){
			for(j=0;j<cmat->taille_mat_y;j++){
				//Destruction des canards
				for(k=0;k<cmat->matrice[i][j].nb_occupant;k++){
					cmat->matrice[i][j].tab_canard[k].nourriture=0;
					cmat->matrice[i][j].tab_canard[k].etat=-1;	
					ajout_score(-50,joueur,joueur2);
				}
				cmat->matrice[i][j].nb_occupant=0;
			}
		}
	}
	return 1;
}

/** \fn int tempete(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int tempete(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){

	int i,j,k;
	int random_min=rand_map(cmat->taille_mat_x);
	int random_max=rand_map(cmat->taille_mat_y);
	// choisit un random_min plus petit que random_max
	while(random_min>random_max){
		random_min=rand_map(cmat->taille_mat_x);
		random_max=rand_map(cmat->taille_mat_y);
	}
	// parcourt une partie de la matrice
	for(i=random_min;i<random_max;i++){
		for(j=random_min;j<random_max;j++){
			for(k=0;k<cmat->matrice[i][j].nb_occupant;k++){
				//Destruction des canards
				cmat->matrice[i][j].tab_canard[k].nourriture=0;
				cmat->matrice[i][j].tab_canard[k].etat=-1;	
				ajout_score(-50,joueur,joueur2);
			}
			cmat->matrice[i][j].nb_occupant=0;
		}
	}
	return 1;
}

/** \fn int famine(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int famine(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	ajout_score(-100,joueur,joueur2);
	//Réduit par deux la nourriture générée dans les tats de nourriture
	if(((*nourriture_genere)/2)>=0){
		*nourriture_genere/=2;
	}
	return 1;
	
}
/** \fn int reproduction(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int reproduction_ralentie(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	ajout_score(-100,joueur,joueur2);
	//Multiplie par deux le besoin de nourriture pour pouvoir s'accoupler
	if(((*nourriture_accouplement)*2)<=100){
		*nourriture_accouplement*=2; //variable de deplacer.c 
	}
	return 1;
}

/** \fn int apparition_predateur(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int apparition_predateur(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){

	int i,k;	
	int random_x;
	int random_y;
	//random pour le nombre de prédateur
	int random_nbre_predateur=rand()%5;
	//boucle pour tuer des canards en fonction du nombre de prédateur
	for(i=0;i<random_nbre_predateur;i++){ 
	
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);
		//destruction des canards
		for(k=0;k<cmat->matrice[random_x][random_y].nb_occupant;k++){
			cmat->matrice[random_x][random_y].tab_canard[k].nourriture=0;
			cmat->matrice[random_x][random_y].tab_canard[k].etat=-1;	
			ajout_score(-50,joueur,joueur2);
		}
		cmat->matrice[random_x][random_y].nb_occupant=0;	
	}
	return 1;
}

/* Evenement bon */
/** \fn int reproduction_acceleree(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int reproduction_acceleree(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	ajout_score(100,joueur,joueur2);
	//Réduit par deux le besoin de nourriture pour s'accoupler
	if(((*nourriture_accouplement)/2)>=0){
		*nourriture_accouplement/=2;
	}
	return 1;
}

/** \fn int plus_nourriture(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int plus_nourriture(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	ajout_score(100,joueur,joueur2);
	
	//Multiplie par deux la nourriture générée dans les tats de nourriture
	if(((*nourriture_genere)*2)<=100){
		*nourriture_genere*=2;
	}
	return 1;
}

/** \fn int rien_faire(caract_mat_t,joueur_t,joueur_t,int*,int*)*/
int rien_faire(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	ajout_score(1,joueur,joueur2);
	return 1;
}
//ajout au score
/** \fn int liberation_canard(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int liberation_canard(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	int i,k;	
	int random_x;
	int random_y;
	//random pour le nombre de canard
	int random_nbre_de_canard_liberer=rand()%5;
	//boucle pour tuer des canards en fonction du nombre de prédateur
	for(i=0;i<random_nbre_de_canard_liberer;i++){ 
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);
		//sortie des canards
		for(k=0;k<cmat->matrice[random_x][random_y].nb_occupant;k++){
			cmat->matrice[random_x][random_y].tab_canard[k].nourriture=0;
			cmat->matrice[random_x][random_y].tab_canard[k].etat=-1;	
			ajout_score(100,joueur,joueur2); //ajout de 500 points par libération
		}
		cmat->matrice[random_x][random_y].nb_occupant=0;	
	}
	return 1;
}
/** \fn int canard_invincible(caract_mat_t,joueur_t*,joueur_t*,int*,int*)*/
int canard_invincible(caract_mat_t * cmat, joueur_t * joueur,joueur_t * joueur2,int* nourriture_genere,int* nourriture_accouplement){
	ajout_score(104,joueur,joueur2);
	int random_x;
	int random_y;
	//choisit une case ou il y a des canards
	do{
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);
	}while(cmat->matrice[random_x][random_y].nb_occupant==0);
	
	//Rempli les poches du canards et change son état pour qu'il ne soit plus affecter par des événements
	cmat->matrice[random_x][random_y].tab_canard[0].nourriture=100;
	cmat->matrice[random_x][random_y].tab_canard[0].etat=2;	//etat invincible
	return 1;
}
//Tableau contenant les fonctions mauvaises
 int init_tab_event_mauvais(){
 	mauvais[0] = tsunami;
 	mauvais[1] = tempete;
 	mauvais[2] = famine;
 	mauvais[3] = reproduction_ralentie;
 	mauvais[4] = apparition_predateur;
 	return 1;
 }
 //Tableau contenant les fonctions bonnes
 int init_tab_event_bon(){
 	bon[0] = reproduction_acceleree;
 	bon[1] = plus_nourriture;
 	bon[2] = rien_faire;
 	bon[3] = liberation_canard;
 	bon[4] = canard_invincible;
 	return 1;
 }

