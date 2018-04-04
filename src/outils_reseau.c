
/**
 * \file multi_joueur_reseau.c
 * \brief Fonctions communes au serveur et au client 
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "multijoueur.h"
#include "main_reseau.h"
#include "fonction_multi_reseau.h"
#include "include_connection.h"
#include "connection.h"

/** \fn void envoyer_int(int socket, int valeur)*/
 void envoyer_int(int socket, int valeur){ /** Fonction qui envoie un int a la socket donnee en parametre */
    fprintf(stderr, "DEBUT envoyer_int\n");
 	 send(socket, &valeur, sizeof(int), 0);
 	 fprintf(stderr, "FIN envoyer_int\n");
 }

 /** \fn void recevoir_int(int socket, int * valeur) */
void recevoir_int(int socket, int * valeur){/** fonction qui recoit un int de la socket passee en parametre*/
    fprintf(stderr, "DEBUT recevoir_int\n");
    memset(valeur, 0, sizeof(int));
	recv(socket, valeur, sizeof(int), 0);
	fprintf(stderr, "FIN recevoir_int\n");
 }

/**\fn  int demander_qui_commence(void)*/
int demander_qui_commence(){/** Demande si la personne veut commencer ou non */
	int qui;
	printf("Voulez-vous commencer? si oui tapez 1 si non tapez 0 : ");
	scanf("%i", &qui);

	return qui;
}

/**\fn void saisir_role(int * role) */
void saisir_role(int * role){ /** Demande quel role le joueur veut jouer */
	printf("quel role voulez vous endosser ? \n");
	printf("	Le mechant tapez 0\n");
	printf("	Le gentil tapez 1\n");
	scanf("%i",role);
}

/**  \fn void afficher_role(int role)*/
void afficher_role(int role){/** affiche le role du joueur */
	system("cls");
	if(role == 0)
		printf("\n				VOUS ETES LE MECHANT		\n");
	else
		printf("\n				VOUS ETES LE GENTIL			\n");
}

























