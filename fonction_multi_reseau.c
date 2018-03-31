#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "outils_reseau.h"
#include "joueur.h"
#include "multijoueur.h"

/**
*\file fonction_multi_reseau.c
*\brief programme qui gere tout ce qui est en rapport avec le joueur
*\author TOUZE Maxime
*\version 0.5
*\date 31 mars 2018
*/

char * mauv_evts={"tsunami", "tempete","famine","reproduction_ralenti","predateur"};
char * bon_evts={"plus_nourriture","joker_nourriture","liberation_canard","canard_invassible","reproduction_accelere"};



void envoyer_situation(int socket ,caract_mat_t * cmat, int nourriture_genere, int nouriture_acouplement){
    envoyer_int(socket, nourriture_genere);
    envoyer_int(socket, nouriture_acouplement);
    envoyer_laby(socket, cmat);

}

void recevoir_situation(int socket ,caract_mat_t * cmat, int * nourriture_genere, int * nouriture_acouplement){
    recevoir_int(socket, nourriture_genere);
    recevoir_int(socket, nouriture_acouplement);
    recevoir_laby(socket, cmat);

}




/* ********************************************************************       MECHANT      ****************************************************************** */

/** \fn void choix_mechant_quijoue(int socket, caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation)*/
void choix_mechant_quijoue(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation){/** fonction qui permet de choisir entre 3 evenements mauvais*/
	int choix1, choix2, choix3;
	tab_event_mauvais(&choix1, &choix2, &choix3);

    envoyer_int(socket, choix1);
	envoyer_int(socket, choix2);
	envoyer_int(socket,choix3);

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
                case 4: printf("Sauvegarde d'une partie en ligne impossible");
                case 5: envoyer_int(socket, fin_transmission);
                            exit(0);

			}
		}while(result!=1 && result!=2 && result!=3);
        envoyer_int(socket, result);
        envoyer_situation(socket , cmat, *nourriture_genere, * nouriture_acouplement);
}

/** \fn void choix_mechant_quirecoit(int socket, caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation)*/
void choix_mechant_quirecoit(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation){/** fonction qui applique le choix mechant effectué par l adversaire */
	int choix1, choix2, choix3;

	recevoir_int(socket, &choix1);
	recevoir_int(socket, &choix2);
	recevoir_int(socket, &choix3);

    printf("Le joueur adverse a le choix entre : \n");
	printf("\nChoix 1 : %s\n",mauv_evts[choix1]);  // Affichage des choix si ils sont differents du premier
	if(choix1 != choix2)
		printf("Choix 2 : %s\n",mauv_evts[choix2]);
	if(choix1 != choix3 && choix2 != choix3)
		printf("Choix 3 : %s\n",mauv_evts[choix3]);

	printf("en attente du choix du joueur ..... \n");

    int result;
	recevoir_int(socket ,&result);

	if(result == fin_transmission){
        char tampon[200];
        printf("Le joueur adverse a quitté la partie, appuyez sur entrer pour quitter le jeu");
        scanf("%s", tampon);
        exit(0);
	}

    recevoir_situation(socket , cmat, nourriture_genere, nouriture_acouplement);

}



/* ********************************************************************       GENTIL      ****************************************************************** */


/** \fn void choix_gentil_quijoue(int socket, caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation)*/
void choix_gentil_quijoue(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation){/** fonction qui permet de choisir entre 3 evenements gentil*/
	int choix1, choix2, choix3;
	tab_event_bon(&choix1, &choix2, &choix3);

    envoyer_int(socket, choix1);
	envoyer_int(socket, choix2);
	envoyer_int(socket, choix3);

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
                case 4: printf("Sauvegarde d'une partie en ligne impossible");
                case 5: envoyer_int(socket, fin_transmission);
                            exit(0);

			}
		}while(result!=1 && result!=2 && result!=3);
        envoyer_int(socket, result);
        envoyer_situation(socket , cmat, *nourriture_genere, * nouriture_acouplement);
}

/** \fn void choix_gentil_quirecoit(int socket, caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation)*/
void choix_gentil_quirecoit(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation){/** fonction qui applique le choix gentil effectué par l adversaire */
	int choix1, choix2, choix3;

	recevoir_int(socket, &choix1);
	recevoir_int(socket, &choix2);
	recevoir_int(socket, &choix3);

    printf("Le joueur adverse a le choix entre : \n");
	printf("\nChoix 1 : %s\n",bon_evts[choix1]);  // Affichage des choix si ils sont differents du premier
	if(choix1 != choix2)
		printf("Choix 2 : %s\n",bon_evts[choix2]);
	if(choix1 != choix3 && choix2 != choix3)
		printf("Choix 3 : %s\n",bon_evts[choix3]);

	printf("en attente du choix du joueur ..... \n");

        int result;
	recevoir_int(socket ,&result);

	if(result == fin_transmission){
        char tampon[200];
        printf("Le joueur adverse a quitté la partie, appuyez sur entrer pour quitter le jeu");
        scanf("%s", tampon);
        exit(0);
	}

    recevoir_situation(socket , cmat, nourriture_genere, nouriture_acouplement);
}

/* *********************************** FONCTION QUI INITIALISATION DES CHOIX *********************************************** */
/** \fn joueur_reseau_t joueur_gentil_res(void) */
joueur_reseau_t joueur_gentil_res(void){ /** initialise un joueur en joueur gentil*/
    joueur_reseau_t mem;
    mem.clan = gentil;

    mem.choix_adv = choix_mechant_quirecoit;
    mem.choix = choix_gentil_quijoue;

    mem.joueur.score =0;

    return mem ;
}

/** \fn joueur_reseau_t joueur_mechant_res(void) */
joueur_reseau_t joueur_mechant_res(void){ /** initialise un joueur en joueur gentil*/
    joueur_reseau_t mem;
    mem.clan = mechant;

    mem.choix_adv = choix_gentil_quirecoit;
    mem.choix = choix_mechant_quijoue;

    mem.joueur.score =0;

    return mem ;
}








