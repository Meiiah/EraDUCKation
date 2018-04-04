/**
 * \file main_reseau.c
 * \brief fonctions des main serveur et client pour le jeu en r�seau
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/


#include <stdio.h>
#include "struct.h"
#include "piege.h"
#include "joueur.h"
#include "canard.h"
#include "multijoueur_reseau.h"
#include "client_reseau.h"
#include "connection.h"
#include "deplacer.h"
#include "deplacer_multi.h"
#include "outils_reseau.h"
#include "fonction_multi_reseau.h"
#include "nourriture.h"
#include "matrice.h"
#include "labyrinthe.h"
#include "outils.h"

/* ************************************    CLIENT     ****************************************** */
/**\fn  void jeu_client(int socket, caract_mat_t * cmat, joueur_reseau_t tab[], int nourriture_accouplement, int nourriture_generee)*/
void jeu_client(int socket, caract_mat_t * cmat, joueur_reseau_t tab[], int nourriture_accouplement, int nourriture_generee){/** Deroulement du jeu pour le client*/
    int nb_gen =0 ;
    affichage_laby(cmat);

    while ( nb_gen<100 && presence_canard(cmat)==1){ // fin du jeu

        recevoir_laby(socket, cmat); // le client d�place et envoie le labyrinthe

        affichage_laby(cmat);

        printf("C est le tour de %s", tab[nb_gen%2].joueur.nom_joueur);

        tab[nb_gen %2].choix(socket, cmat,&(tab[0].joueur), &(tab[1].joueur), &nourriture_generee, &nourriture_accouplement, nb_gen);

		nb_gen++;

		printf("Nourriture accouplement: %i\n",nourriture_accouplement);
		printf("Nourriture generee: %i\n",nourriture_generee);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));

	}
	return ;

}

/**\fn void main_client(void) */
void main_client(void){/** main pour le client */
    int socket;
    joueur_reseau_t tab_joueurs[2];
    caract_mat_t * cmat;

    socket = menu_client(); // socket client
    fprintf(stderr, "Connection réussie!");
    cmat = recev_init_laby(socket); //la cmat envoy�e par le client

    quel_role_client(socket, tab_joueurs); //initialise les roles dans ordre de jeu serveur -> client

    init_joueurs_client(tab_joueurs); // initialise les fonctions et ce qui se rapporte aux joueurs

    demander_nom_client(tab_joueurs); // Prise et envoi des noms

    int nourriture_accouplement = 50;
    int nourriture_generee = 10;


    jeu_client(socket, cmat, tab_joueurs, nourriture_accouplement, nourriture_generee );

}

/* ************************************    SEVEUR     ****************************************** */

/**\fn void jeu_serv(int socket, caract_mat_t * cmat, joueur_reseau_t tab[],  int nourriture_accouplement, int nourriture_generee) */
void jeu_serv(int socket, caract_mat_t * cmat, joueur_reseau_t tab[],  int nourriture_accouplement, int nourriture_generee){/** Deroulement du jeu pour le serveur*/
    int nb_gen =0;
    affichage_laby(cmat);

    while ( nb_gen<100 && presence_canard(cmat)==1){ // fin du jeu
        spawn_nourriture(cmat, nourriture_generee);
        piege(cmat);
        deplacer(cmat, nourriture_accouplement, nourriture_generee, tab[0].joueur, tab[1].joueur);
        envoyer_laby(socket, cmat); // le client d�place et envoie le labyrinthe

        affichage_laby(cmat);

        printf("C est le tour de %s", tab[nb_gen%2].joueur.nom_joueur);

        tab[nb_gen %2].choix(socket, cmat, &(tab[0].joueur), &(tab[1].joueur), &nourriture_generee, &nourriture_accouplement, nb_gen);

		nb_gen++;

		printf("Nourriture accouplement: %i\n",nourriture_accouplement);
		printf("Nourriture generee: %i\n",nourriture_generee);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));

	}
	return ;

}

/**\fn void main_serveur(void) */
void main_serveur(void){ /** foncion main pour le serveur en mode r�seau*/
    int socket;
    joueur_reseau_t tab_joueurs[2];
    caract_mat_t * cmat;
    int tx=10;
    int ty = 10;

    socket = menu_serveur(); // socket client
    fprintf(stderr ,"\nConnection réussie!");
    cmat = creation_matrice(tx, ty);

    init_matrice(cmat); 

    main_laby(cmat); // generation laby

    init_canard(cmat);
	
	envoyer_cmat(socket, cmat);
	
    quel_role_serveur(socket, tab_joueurs); //initialise les roles dans ordre de jeu serveur -> client

    init_joueurs_serv(tab_joueurs); // initialise les fonctions et ce qui se rapporte aux joueurs

    demander_nom_serv(tab_joueurs, socket); // Prise et envoi des noms

    int nourriture_accouplement = 50;
    int nourriture_generee = 10;


    jeu_serv(socket, cmat, tab_joueurs, nourriture_accouplement, nourriture_generee  );

}

/* **************************************** GENERAL ************************************************* */

/**\fn void main_reseau(void)  */
void main_reseau(void){/** Le main en multijoueur qui permet de choisir si on est serveur ou client, et de lancer le main assici� */
    int choix;
    do{
        //system("CLEAR");
        printf("Bienvenue dans la partie multijoueur d' EraDUCKation, souhaitez vous etre hote ou rejoindre un ami pret a vous recevoir ? \n");
        printf("        Si vous voulez etre l'hote de la partie tapez 1 ;\n");
        printf("        Si vous voulez rejoindre un ami  tapez 2 ;\n");
        scanf("%i", &choix);
    }while(choix != 1 && choix != 2);

    switch(choix){

        case 1 : //traitement hote
            main_serveur();
            break;
        case 2 : //traitement client
            main_client();
            break;
    }
}
