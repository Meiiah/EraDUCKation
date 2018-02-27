#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "string.h"
/**
*\file joueur.c
*\brief programme qui gere tout ce qui est en rapport avec le joueur
*\author VAIDIE Camille
*\version 1.0
*\date 20 fevrier 2018
*/

#define nb_event 4
/** \fn void ajout_score(int,joueur_t,joueur_t)*/
/**fonction d'ajour de score des deux joueurs*/

void ajout_score(int point,joueur_t joueur, joueur_t joueur2){
	joueur.score+=point; // ajout des points en fonction de l'action faite
	if(!strcmp(joueur2.nom_joueur,"null")){
		joueur2.score-=point;
	}
}

/**\fn void caract_joueur(joueur_t)*/
/** saisi du pseudo du joueur */
void caract_joueur(joueur_t joueur){
	printf("Saisir le pseudo du joueur");
	scanf("%s",joueur.nom_joueur);
	joueur.score=0;
}

char *mauv_evts[nb_event+1]={"tsunami", "tempete","famine","reproduction_ralenti","predateur"};
char *bon_evts[nb_event+1]={"plus_nourriture","joker_nourriture","liberation_canard","canard_invassible","reproduction_accelere"};


/** \fn void tab_event_mauvais(void) */
/** choisit 3 mauvais evenements random */
void tab_event_mauvais(int * choix1,int * choix2, int * choix3){
	*choix1=(rand() % (nb_event + 1)); // Random du choix des evenement parmis 5 possibilités//
	*choix2=(rand() % (nb_event + 1));
	*choix3=(rand() % (nb_event + 1));
	
	
	printf("%s",mauv_evts[*choix1]);  // Affichage des choix si ils sont differents du premier
	if(choix1!=choix2)
		printf("%s",mauv_evts[*choix2]);
	if(choix1!=choix3 && choix2!=choix3)
		printf("%s",mauv_evts[*choix3]);
}

/** \fn void tab_event_bon(void) */
/** choisit 3 bons evenements random */
void tab_event_bon(int * choix1,int * choix2, int * choix3){

	*choix1=(rand() % (nb_event + 1)); // Random du choix des evenement parmis 5 possibilités//
	*choix2=(rand() % (nb_event + 1));
	*choix3=(rand() % (nb_event + 1));

	printf("%s",bon_evts[*choix1]);  // Affichage des choix si ils sont differents du premier
	if(choix1!=choix2)
		printf("%s",bon_evts[*choix2]);
	if(choix1!=choix3 && choix2!=choix3)
		printf("%s",bon_evts[*choix3]);
}


/** \fn void choix_mauvais(void)*/
/** choix random parmis les evenements mauvais */
void choix_mechant(caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int nourriture_genere, int nourriture_accouplement){
	int choix1, choix2, choix3;
	
	tab_event_mauvais(&choix1, &choix2, &choix3);
	int result;
	printf("Choisir le numero de l'evenement choisit");
	scanf("%i",&result);// Saisit du choix du joueur//
	
	switch(result){
		case 1: mauvais[choix1](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
			break;
		case 2: mauvais[choix2](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
			break;
		case 3: mauvais[choix3](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
			break;
		default: printf("saisir un choix possible");
			break;
	}
}

/** \fn void choix_bon(void)*/
/** choix random parmis les evenements bon */

void choix_bon(caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int nourriture_genere, int nourriture_accouplement){
	int choix1, choix2, choix3;
	
	tab_event_bon(&choix1, &choix2, &choix3);
	int result;
	printf("Choisir le numero de l'evenement choisit");
	scanf("%i",&result); // Saisit du choix du joueur//
		
	switch(result){
		case 1: bon[choix1](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
			break;
		case 2: bon[choix2](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
			break;
		case 3: bon[choix3](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
			break;
		default: printf("saisir un choix possible");
			break;
	}
}

/** \fn void choix_joueur(void)*/
/** choix du joueur parmis les evenements */
void choix_joueur(caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int nourriture_genere, int nourriture_accouplement){
	int nature_event= ( rand() % 2); // Choix randome d'un evenement positif ou negatif//
	if (nature_event%2==0){ // Si pair : Evenement negatif //
		choix_mechant(cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
	}else { // Si impaire: Evenement positif//
		choix_bon(cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
	}
}