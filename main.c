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
//#include "main_reseau.h"

/**
* \file main.c
* \brief Main du jeu
* \author PHILIPPE Marion
* \version 1.0
* \date 4 avril 2018
*/ 

typedef enum{facile=1,moyen=2,difficile=3}diff_t;
typedef enum{solo=1,multi=2}nb_joueur_t;
typedef enum{jouer=1,charger_partie=2,reseau=3, quitter=4}menu_t;

//fonction qui permet de choisir la difficulté
/** \fn int choix_difficultee(int)*/
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

int main(void){
	//definition matrice
	caract_mat_t * cmat = NULL;

	//definition joueur
	joueur_t * joueur=malloc(sizeof(joueur_t));
	joueur_t * joueur2=malloc(sizeof(joueur_t));
	
	//Initialisation des joueurs
	joueur->score = 0;
	joueur2->score = 0;
	
	//Permet de savoir si le joueur 2 existe ou pas
	joueur2->nom_joueur[0]='n';
	joueur2->nom_joueur[1]='u';
	joueur2->nom_joueur[2]='l';
	joueur2->nom_joueur[3]='l';

	//definition nourriture
	int nourriture_accouplement = 25;//Nourriture qu'on a besoin pour se reproduire
	int nourriture_genere = 50;//Nourriture qui apparait

	int choix; // Choix du joueur
	int choix_niv; // Choix du niveau
	int choix_j; // Choix du nb joueur
	int nbr_joueur;

	int nb_gen=0; //Nombre de génération

	init_tab_event_mauvais();//Initialisation du tableau des événements mauvais
	init_tab_event_bon(); // Initialisation du tableau des événements bons

	printf("EraDUCKation\n\n");

	printf("1 : Jouer à EraDUCKation sur ce PC\n");
	printf("2 : Jouer une partie chargée\n");
	printf("3 : Jouer à EraDUCKation en réseau(non disponible)\n");
	printf("4 : Quitter\n");

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
				
				if(choix_j == 1){
						caract_joueur(joueur);
						joueur->score=0;
						joueur2->score=0;
						return nbr_joueur=1;
				}

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
				
				//lance une partie solo ou multijoueur
				if(nbr_joueur==1){
					jeu_solo(cmat,nourriture_genere,nourriture_accouplement,joueur,joueur2,nb_gen);

				}else{
					main_multijoueur(cmat, nourriture_genere, nourriture_accouplement, nb_gen);
				}
				//détruit la matrice
				detruire_Cmatrice(cmat);
				break;

			case charger_partie :
				//Permet de charger une partie
				charger(cmat,&nourriture_genere, &nourriture_accouplement, joueur, joueur2, &nb_gen);
                detruire_Cmatrice(cmat);
				break;

            case reseau : //main_reseau();
            	//Permet de faire une partie en réseau
                break;
			case quitter :
				//Permet de quitter le jeu
				return 0;
				break;

		}
		//Affichage du score final
	}while(choix!=1 && choix!=2 && choix!=3);
	printf("Le score total du joueur 1 est : %i\n",joueur->score);
	if(strcmp(joueur2->nom_joueur,"null")){
		printf("Le score total du joueur 2 est : %i\n",joueur2->score);
	}
	//Libération des joueurs
	free(joueur);
	free(joueur2);
	return 1;
}
