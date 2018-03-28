#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "string.h"
#include "sauvegarde.h"
#include "joueur.h"

/**
*\file joueur.c
*\brief programme qui gere tout ce qui est en rapport avec le joueur
*\author VAIDIE Camille
*\version 1.0
*\date 20 fevrier 2018
*/



#define nb_event 5
char *mauv_evts[nb_event]={
	"Lance un tsunami sur le labyrinthe",
	"Lance une tempete sur le labyrinthe",
	"Famine : Réduit la nourriture générée",
	"Réduit la reproduction des canards",
	"Appartion de 0 à 5 prédateurs de canards"
};
char *bon_evts[nb_event]={
	"Accelère la reproduction des canards",
	"Génération de nourriture augmentée",
	"Rien changer",
	"Libère entre 0 et 5 canards",
	"Rend un canard invincible"
};

/** \fn void ajout_score(int,joueur_t,joueur_t)*/
void ajout_score(int point,joueur_t * joueur, joueur_t * joueur2){/**fonction d'ajour de score des deux joueurs*/
	joueur->score+=point; // ajout des points en fonction de l'action faite
	if(!strcmp(joueur2->nom_joueur,"null")){
		joueur2->score-=point;
	}
}

/**\fn void caract_joueur(joueur_t)*/
void caract_joueur(joueur_t * joueur){/** saisi du pseudo du joueur */
	printf("Saisir le pseudo du joueur : ");
	scanf("%s",joueur->nom_joueur);
	joueur->score=0;
}




/** \fn void tab_event_mauvais(void) */
/** choisit 3 mauvais evenements random */
void tab_event_mauvais(int * choix1,int * choix2, int * choix3){
	*choix1=(rand() % (nb_event )); // Random du choix des evenement parmis 5 possibilités//
	*choix2=(rand() % (nb_event ));
	*choix3=(rand() % (nb_event ));


	printf("\nChoix 1 : %s\n",mauv_evts[*choix1]);  // Affichage des choix si ils sont differents du premier
	if(*choix1!=*choix2)
		printf("Choix 2 : %s\n",mauv_evts[*choix2]);
	if(*choix1!=*choix3 && *choix2!=*choix3)
		printf("Choix 3 : %s\n",mauv_evts[*choix3]);
	printf("Choix 4 : Sauvegarder \n");
	printf("Choix 5 : Quitter \n");
}

/** \fn void tab_event_bon(void) */
/** choisit 3 bons evenements random */
void tab_event_bon(int * choix1,int * choix2, int * choix3){

	*choix1=(rand() % (nb_event )); // Random du choix des evenement parmis 5 possibilités//
	*choix2=(rand() % (nb_event ));
	*choix3=(rand() % (nb_event ));

	printf("\nChoix 1 : %s\n",bon_evts[*choix1]);  // Affichage des choix si ils sont differents du premier
	if(*choix1!=*choix2)
		printf("Choix 2 : %s\n",bon_evts[*choix2]);
	if(*choix1!=*choix3 && *choix2!=*choix3)
		printf("Choix 3 : %s\n",bon_evts[*choix3]);
	printf("Choix 4 : Sauvegarder \n");
	printf("Choix 5 : Quitter \n");
}


/** \fn void choix_mauvais(void)*/
/** choix random parmis les evenements mauvais */
void choix_mechant(caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation){
	int choix1, choix2, choix3;
	tab_event_mauvais(&choix1, &choix2, &choix3);
	int result;
		do{
			printf("Choisir le numéro de l'évènement choisit : ");
			scanf("%i",&result);// Saisit du choix du joueur//
			switch(result){
				case premier_choix: mauvais[choix1](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
					break;
				case deuxieme_choix: mauvais[choix2](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
					break;
				case troisieme_choix: mauvais[choix3](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
					break;
				case sauvegarder: sauvegarde(cmat,*nourriture_genere, *nourriture_accouplement, *joueur,*joueur2,generation);
					printf("Sauvegarde effectée\n");
					break;
				case quitter_jeu: exit(EXIT_SUCCESS);
					break;
				default:
					break;
			}
		}while(result!=1 && result!=2 && result!=3 && result!=5);
}

/** \fn void choix_bon(void)*/
/** choix random parmis les evenements bon */

void choix_bon(caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int* nourriture_genere, int* nourriture_accouplement,int generation){
	int choix1, choix2, choix3;

	tab_event_bon(&choix1, &choix2, &choix3);
	int result;
	do{
		printf("Choisir le numéro de l'évènement choisit : ");
		scanf("%i",&result);// Saisit du choix du joueur//
		switch(result){
			case 1: bon[choix1](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
				break;
			case 2: bon[choix2](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
				break;
			case 3: bon[choix3](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
				break;
			case 4: sauvegarde(cmat,*nourriture_genere, *nourriture_accouplement, *joueur,*joueur2,generation);
				printf("Sauvegarde effectée\n");
				break;
			case 5: exit(EXIT_SUCCESS);
				break;
			default:
				break;
		}
	}while(result!=1 && result!=2 && result!=3 && result!=5);
}
/** \fn void choix_joueur(void)*/
/** choix du joueur parmis les evenements */
void choix_joueur(caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int* nourriture_genere, int* nourriture_accouplement,int generation){
	int nature_event= ( rand() % 2); // Choix randome d'un evenement positif ou negatif//
	if (nature_event%2==0){ // Si pair : Evenement negatif //
		choix_mechant(cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement,generation);
	}else { // Si impaire: Evenement positif//
		choix_bon(cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement,generation);
	}
}
