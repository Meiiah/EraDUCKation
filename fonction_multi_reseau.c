#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "outils_reseau.h"
#include "joueur.h"

/**
*\file joueur.c
*\brief programme qui gere tout ce qui est en rapport avec le joueur
*\author VAIDIE Camille
*\version 1.0
*\date 20 fevrier 2018
*/
void ajout_score(int point,joueur_t joueur, joueur_t joueur2){
	joueur.score+=point; // ajout des points en fonction de l'action faite
	if(joueur2.nom_joueur!=NULL){
		joueur2.score-=point;
	}
}

char *mauv_evts[nb_event+1]={"tsunami", "tempete","famine","reproduction_ralenti","predateur"};
char *bon_evts[nb_event+1]={"plus_nourriture","joker_nourriture","liberation_canard","canard_invassible","reproduction_accelere"};

void tab_event_mauvais_joueur(int socket,int * choix1,int * choix2, int * choix3){
	*choix1=(rand() % (nb_event)); // Random du choix des evenement parmis 5 possibilités//
	*choix2=(rand() % (nb_event));
	*choix3=(rand() % (nb_event));

	envoyer_int(socket,*choix1);
	envoyer_int(socket,*choix2);
	envoyer_int(socket,*choix3);

	printf("%s",mauv_evts[*choix1]); // Affichage des choix si ils sont differents du premier
	if(choix1!=choix2)
		printf("%s",mauv_evts[*choix2]);
	if(choix1!=choix3 && choix2!=choix3)
		printf("%s",mauv_evts[*choix3]);
}

/** \fn void tab_event_bon_reseau(void) */
/** choisit 3 bons evenements random */
void tab_event_bon_joueur(int socket,int * choix1,int * choix2, int * choix3){

	*choix1=(rand() % (nb_event + 1)); // Random du choix des evenement parmis 5 possibilités//
	*choix2=(rand() % (nb_event + 1));
	*choix3=(rand() % (nb_event + 1));

	envoyer_int(socket,*choix1);
	envoyer_int(socket,*choix2);
	envoyer_int(socket,*choix3);

	printf("%s",bon_evts[*choix1]);  // Affichage des choix si ils sont differents du premier
	if(choix1!=choix2)
		printf("%s",bon_evts[*choix2]);
	if(choix1!=choix3 && choix2!=choix3)
		printf("%s",bon_evts[*choix3]);
}


/** \fn void choix_mauvais_reseau(void)*/
/** choix random parmis les evenements mauvais */

void choix_mechant(caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation){
	int choix1, choix2, choix3;
	tab_event_mauvais(&choix1, &choix2, &choix3);
	int result;
		do{
			printf("Choisir le numéro de l'évènement choisit : ");
			scanf("%i",&result);// Saisit du choix du joueur//
			switch(result){
				case 1: mauvais[choix1](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
					break;
				case 2: mauvais[choix2](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
					break;
				case 3: mauvais[choix3](cmat,joueur, joueur2, nourriture_genere, nourriture_accouplement);
					break;

			}
		}while(result!=1 && result!=2 && result!=3);
}
