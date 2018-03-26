/**
 * \file multi_joueur_reseau.c
 * \brief Fonctions propres au client
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/

#include "include_connection.h"
#include "multijoueur.c"
#include "deplacer_multi.h"
#include "outils.h"
#include "outils_reseau.h"
#include "connection.h"
#include "joueur.h"

/** \fn void commence_client(int socket, int role, joueur_multi_t tab[]) */
void commence_client(int socket, int role, joueur_multi_t tab[]){ /** Demande au client si il veut commencer et initialise le tableau avec l ordre de jeu */
	int qui_s, qui_c;

	printf("En attente de votre adversaire ...");
	qui_c = demander_qui_commence();
	envoyer_int(socket, qui_c);

	recevoir_int(socket, qui_s);


	if(role == 0){
		tab_joueurs[qui_s+1%2]= joueur_mechant();
		tab_joueurs[qui_s]= joueur_gentil();
	}
	else{
		tab_joueurs[qui_s+1%2]= joueur_gentil();
		tab_joueurs[qui_s]= joueur_mechant();
	}

}


/** \fn void quel_role_client(int socket, joueur_multi_t tab[]) */
void quel_role_client(int socket, joueur_multi_t tab[]){/** demande au client quel role il veut jouer */
	int role, role2;

	// le client commence par attendre la reponse du serveur pour son role, puis lui transmet le sien, et récupere le role definitif du serveur

	printf("en attente de l autre joueur....");
	recevoir_int(socket, &role);
	saisir_role(&role);
	envoyer_int(socket, role2);

	recevoir_int(socket, role);
	role2 = (role+1)%2 ;

	afficher_role(role2);

	commence_client( socket, role, tab);

}


/** \fn main_multijoueur_reseau_client(int SocketServeur)*/
void main_multijoueur_reseau_client(int SocketServeur){/**  ce sera le "main" du jeu en multi coté client*/
    //variables :
    joueur_multi_t tab[2];

    init_tab_joueurs(tab, tampon);

    //maintenant on initialise l ordre de jeu

}



























