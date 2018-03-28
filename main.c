#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "joueur.h"
#include "canard.h"
#include "labyrinthe.h"
#include "deplacer_multi.h"
#include "jeu_solo.h"
#include "multijoueur.h"
#include "sauvegarde.h"


typedef enum{facile=1,moyen=2,difficile=3}diff_t;
typedef enum{solo=1,multi=2}nb_joueur_t;
typedef enum{jouer=1,charger_partie=2,quitter=3}menu_t;

int choix_difficultee(int choix){

	switch(choix){
		case facile :
			return 6;
		break;	
		case moyen:
			return 10;
		break;
		case difficile:
			return 17;
		break;		
	}
	return 1;
}
int choix_nbr_joueur(int choix,joueur_t * joueur,joueur_t * joueur2){
	int nbr_joueur;
	switch(choix){
		case solo :
			caract_joueur(joueur);
			joueur->score=0;
			joueur2->score=0;
			return nbr_joueur=1;
		break;	
		case multi:
			caract_joueur(joueur);
			caract_joueur(joueur2);
			joueur->score=0;
			joueur2->score=0;
			return nbr_joueur=2;
		break;	
	}
	return 1;
}


int main(void){

	//definition matrice
	caract_mat_t * cmat = NULL;
	//malloc(sizeof(caract_mat_t));
	
	

	//definition joueur
	joueur_t joueur;
	joueur_t joueur2;

	joueur.score = 0;
	joueur2.score = 0;

	joueur2.nom_joueur[0]='n';
	joueur2.nom_joueur[1]='u';
	joueur2.nom_joueur[2]='l';
	joueur2.nom_joueur[3]='l';

	//definition nourriture
	int nourriture_accouplement = 25;//Nourriture qu'on a besoin pour se reproduire
	int nourriture_genere = 50;//Nourriture qui apparait
	
	int choix; // Choix du joueur
	int choix_niv; // Choix du niveau
	int choix_j; // Choix du nb joueur
	int nbr_joueur;
	
	int nb_gen=0;
	
	init_tab_event_mauvais();
	init_tab_event_bon();
	
	printf("EraDUCKation\n\n");

	printf("1 : Jouer à EraDUCKation\n");
	printf("2 : Jouer une partie chargée\n");
	printf("3 : Quitter\n");
	
	do{
		printf("Saisir un choix: ");
		scanf(" %i",&choix);
		switch(choix){
			case jouer :
			
				/* Nombre de Joueur */
				printf("1 : 1 joueur\n");
				printf("2 : 2 joueurs\n");
				do{
					printf("Saisir un choix: ");
					scanf(" %i",&choix_j);
					
				}while(choix_j!=1 && choix_j!=2);
				if(choix_j == 1)
						nbr_joueur=choix_nbr_joueur(choix_j,&joueur,&joueur2);
			
				/* Difficulté*/
				printf("1 : Facile\n");
				printf("2 : Intermédiaire\n");
				printf("3 : Difficile\n");
				do{
					printf("Saisir un choix: ");
					scanf(" %i",&choix_niv);
				}while(choix_niv!=1 && choix_niv!=2 && choix_niv!=3);
				
				int taille=choix_difficultee(choix_niv);	
				//cmat->taille_mat_y=cmat->taille_mat_x;

				/*Mise en place de la matrice adaptée*/
				cmat = creation_matrice(taille, taille);
				init_matrice(cmat);
	
				/*Creation du Labyrinthe*/
			
			
				main_laby(cmat);
			
			
		
				//Apparition de canard
				init_canard(cmat); 
			
				if(nbr_joueur==1){
					jeu_solo(cmat,nourriture_genere,nourriture_accouplement,joueur,joueur2,nb_gen);
				
				}else{
					main_multijoueur(cmat, nourriture_genere, nourriture_accouplement, nb_gen);
				}
			
				break;

			case charger_partie : 
				charger(cmat,&nourriture_genere, &nourriture_accouplement, &joueur, &joueur2, &nb_gen);
				if(strcmp(joueur2.nom_joueur, "null")){
					jeu_solo(cmat,nourriture_genere,nourriture_accouplement,joueur,joueur2,nb_gen);
				}else{
					main_multijoueur(cmat, nourriture_genere, nourriture_accouplement, nb_gen);			
				}break;
 
			case quitter :
				return 0;
				break;
		
		}
	}while(choix!=1 && choix!=2 && choix!=3);
	printf("Le score total du joueur 1 est : %i\n",joueur.score);
	if(strcmp(joueur2.nom_joueur,"null")){
		printf("Le score total du joueur 2 est : %i\n",joueur2.score);
	}
	return 1;
}
