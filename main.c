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



int choix_difficultee(int choix){

	switch(choix){
		case 1 :
			return 6;
		break;	
		case 2:
			return 10;
		break;
		case 3:
			return 17;
		break;		
	}
	return 1;
}
int choix_nbr_joueur(int choix,joueur_t joueur,joueur_t joueur2){
	int nbr_joueur;
	switch(choix){
		case 1 :
			caract_joueur(joueur);
			joueur2.score=0;
			return nbr_joueur=1;
		break;	
		case 2:
			caract_joueur(joueur);
			caract_joueur(joueur2);
			return nbr_joueur=2;
		break;	
	}
	return 1;
}


int main(void){

	//definition matrice
	caract_mat_t * cmat = malloc(sizeof(caract_mat_t));

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
	int nourriture_genere = 10;//Nourriture qui apparait
	
	int choix; // Choix du joueur
	int nbr_joueur;
	
	init_tab_event_mauvais();
	init_tab_event_bon();
	
	printf("EraDUCKation\n\n");

	printf("1 : Jouer à EraDUCKation\n");
	printf("2 : Option (non opérationel)\n");
	printf("3 : Quitter\n");
	
	printf("Choix: ");
	scanf(" %i",&choix);
		
	switch(choix){
		case 1 :
			
			/* Nombre de Joueur */
			printf("1 : 1 joueur\n");
			printf("2 : 2 joueurs\n");
			printf("Choix: ");
			scanf(" %i",&choix);
		
			nbr_joueur=choix_nbr_joueur(choix,joueur,joueur2);
			
			/* Difficulté*/
			printf("1 : Facile\n");
			printf("2 : Intermédiaire\n");
			printf("3 : Difficile\n");
			printf("Choix: ");
			scanf(" %i",&choix);
			
			cmat->taille_mat_x=choix_difficultee(choix);	
			cmat->taille_mat_y=cmat->taille_mat_x;

			/*Mise en place de la matrice adaptée*/
			creation_matrice(cmat);
			init_matrice(cmat);
	
			/*Creation du Labyrinthe*/
			main_laby(cmat);
		
			//Apparition de canard
			init_canard(cmat); 
			
			if(nbr_joueur==1){
				jeu_solo(cmat,nourriture_genere,nourriture_accouplement,joueur,joueur2);
				
			}else{
				//jeu_multi();
			}
			
		break;

		case 2 : 
			printf("2 : Option (non opérationel)");
		break;

		case 3 :
			return 0;
		break;
	
	}
	printf("Le score total du joueur 1 est : %i\n",joueur.score);
	if(strcmp(joueur2.nom_joueur,"null")){
		printf("Le score total du joueur 2 est : %i\n",joueur2.score);
	}
	return 1;
}
