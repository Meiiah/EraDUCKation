/**
 * \file multi_joueur_reseau.c
 * \brief fonctions propres au serveur
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include "include_connection.h"
#include "multijoueur.h"
#include "deplacer_multi.h"
#include "outils.h"
#include "outils_reseau.h"
#include "connection.h"
#include "joueur.h"
#include "matrice.h"
#include "struct.h"
#include "fonction_multi_reseau.h"


////////////////////////////////////////////////////////////////////////////////////////////////
/**  \fn void envoyer_laby(int socket, caract_mat_t * cmat)*/
void envoyer_laby(int socket, caract_mat_t * cmat){/** Fonction qui envoit le laby */

    send(socket, cmat->matrice[0]  ,sizeof(case_t) * cmat->taille_mat_x * cmat->taille_mat_y ,0);
}

/**  \fn void envoyer_cmat(int socket, caract_mat_t * cmat)*/
void envoyer_cmat(int socket, caract_mat_t * cmat){/** Fonction qui envoit la cmat pour l initialisation */
    envoyer_int(socket, cmat->taille_mat_x);
    envoyer_int(socket, cmat->taille_mat_y);

    envoyer_laby(socket, cmat);
}



/* *********************************************		INITIALISATION TOUR DE JEU		*******************************************/

/** \fn void commence_serveur(int socket, int role, joueur_reseau_t tab[])*/
void commence_serveur(int socket, int role, joueur_reseau_t tab_joueurs[]){ /** Demande au serveur si il veut commencer, et renvoit qui commencera */
	int qui_s, qui_c;

	qui_s = demander_qui_commence();
	printf("En attente de votre adversaire ...");
	recevoir_int(socket, &qui_c);

	if(qui_s == qui_c)
		qui_s = rand()%2;

	envoyer_int(socket, qui_s);

	init_joueurs_serv(tab_joueurs);

}


/* *********************************************		ROLE		*****************************************/
/** \fn void quel_role_serveur(int socket, joueur_reseau_t tab[]) */
void quel_role_serveur(int socket, joueur_reseau_t tab[]){ /** demande au serveur quel role il veut jouer */
	int role, role2;

	//le serveur envoit son role au client puis recupere celui du client, si ils sont egaux, c est rand, et il envoit son role definitif (du serveur) au client

	saisir_role(&role);
	envoyer_int(socket, role);
	printf("en attente de l autre joueur....");
	recevoir_int(socket, &role2);

	if(role == role2)
		role=rand()%2;

	envoyer_int(socket, role);
	role2 = role+1%2 ;

	afficher_role(role);

	//commence_serveur( socket, role, tab);
}

/** void demander_nom_serv(joueur_reseau_t tab[]) */
void demander_nom_serv(joueur_reseau_t tab_joueurs[], int socket){ /** Demande le nom du serveur et recupere celui du client puis met les deux dans le tableau joueur */
    printf("\nQuel sera votre nom ?\n");
    scanf("%s", tab_joueurs[0].joueur.nom_joueur);
    printf("En attente de la réponse de votre adversaire ... \n");
    send(socket, &(tab_joueurs[0].joueur.nom_joueur), 26, 0 );
    recv(socket, &(tab_joueurs[1].joueur.nom_joueur), 26, 0);
}








