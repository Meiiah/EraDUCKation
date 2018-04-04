/**
 * \file client_reseau.c
 * \brief Fonctions propres au client
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include "include_connection.h"
#include "multijoueur.h"
#include "deplacer_multi.h"
#include "outils.h"
#include "outils_reseau.h"
#include "connection.h"
#include "joueur.h"
#include "struct.h"
#include "fonction_multi_reseau.h"



/** \fn void recevoir_laby(int socket, caract_mat_t * cmat) */
void recevoir_laby(int socket, caract_mat_t * cmat){ /** Fonction qui met a jour le labyrinthe en fonction de celui de l adversaire */

    recv(socket, &(cmat->matrice[0]) ,sizeof(case_t) * cmat->taille_mat_x * cmat->taille_mat_y ,0);

}

/** caract_mat_t * recev_init_laby(int socket) */
caract_mat_t * recev_init_laby(int socket){/** fonction qui recoit le laby en faisant l allocation et return la cmat */
    caract_mat_t * cmat;
    int tx, ty;
    recevoir_int(socket , &tx);
    recevoir_int(socket , &ty);
    cmat = creation_matrice(tx, ty);
    recevoir_laby(socket,   cmat);
    return cmat;

}


/** \fn void commence_client(int socket, int role, joueur_reseau_t tab[]) */
void commence_client(int socket, int role, joueur_reseau_t tab_joueurs[]){ /** Demande au client si il veut commencer et initialise le tableau avec l ordre de jeu */
	int qui_s, qui_c;

	printf("En attente de votre adversaire ...");
	qui_c = demander_qui_commence();
	envoyer_int(socket, qui_c);

	recevoir_int(socket, &qui_s);

	init_joueurs_client(tab_joueurs);
}


/** \fn void quel_role_client(int socket, joueur_reseau_t tab[]) */
void quel_role_client(int socket, joueur_reseau_t tab[]){/** demande au client quel role il veut jouer  et initialise les roles dans le tableau*/
	int role, role2;

	// le client commence par attendre la reponse du serveur pour son role, puis lui transmet le sien, et récupere le role definitif du serveur

	printf("en attente de l autre joueur....");
	recevoir_int(socket, &role);
	saisir_role(&role2);
	envoyer_int(socket, role2);

	recevoir_int(socket, &role);
	role2 = (role+1)%2 ;

	afficher_role(role2);

    tab[0].clan = role;
	tab[1].clan = role2;

}


/** void demander_nom_client(joueur_reseau_t tab[]) */
void demander_nom_client(int socket, joueur_reseau_t tab_joueurs[]){ /** Demande le nom du client et recupere celui du serveur puis met les deux dans le tableau joueur */
    printf("\nQuel sera votre nom ?\n");
    scanf("%s", tab_joueurs[1].joueur.nom_joueur);
    printf("En attente de la réponse de votre adversaire ... \n");
    recv(socket, &(tab_joueurs[0].joueur.nom_joueur), 25, 0 );
    send(socket, &(tab_joueurs[1].joueur.nom_joueur), 25, 0);
}






