/**
 * \file multi_joueur_reseau.c
 * \brief fonctions propres au serveur
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



/*
    TO DO LIST

    - reprendre la struct multi joueur, l initialisé avec en plus la fonction choix_reception
    - reprendre déplacer et adapter client serveur  // adapter les fonctions qui vont avec + piege
    - mettre en place les main()
    - PENSER A ENVOYER LE LABY
*/


////////////////////////////////////////////////////////////////////////////////////////////////
/**  \fn void envoyer_laby(int socket, caract_mat_t * cmat)*/
void envoyer_laby(int socket, caract_mat_t * cmat){/** Fonction qui envoit le laby */
    envoyer_int(socket , cmat->taille_mat_x);
    envoyer_int(socket , cmat->taille_mat_y);

    send(socket, *(cmat->matrice[0]) ,sizeof(t_case) * cmat->taille_mat_x * cmat->taille_mat_y ,0);
}



/* *********************************************		INITIALISATION TOUR DE JEU		*******************************************/

/** \fn void commence_serveur(int socket, int role, joueur_multi_t tab[])*/
void commence_serveur(int socket, int role, joueur_multi_t tab[]){ /** Demande au serveur si il veut commencer, et renvoit qui commencera */
	int qui_s, qui_c;

	qui_s = demander_qui_commence();
	printf("En attente de votre adversaire ...");
	recevoir_int(socket, &qui_c);

	if(qui_s == qui_c)
		qui_s = rand%2;

	envoyer_int(socket, qui_s);

	if(role == 0){
		tab_joueurs[qui_s+1%2]= joueur_mechant();
		tab_joueurs[qui_s]= joueur_gentil();
	}
	else{
		tab_joueurs[qui_s+1%2]= joueur_gentil();
		tab_joueurs[qui_s]= joueur_mechant();
	}

}


/**********************************************		ROLE		*****************************************/
/** \fn void quel_role_serveur(int socket, joueur_multi_t tab[]) */
void quel_role_serveur(int socket, joueur_multi_t tab[]){ /** demande au serveur quel role il veut jouer */
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

	commence_serveur( socket, role, tab);
}


/**********************************************		JEU			*****************************************/



void main_multijoueur_reseau_serveur(int SocketServeur){
    joueur_multi_t tab[2];

    init_tab_joueurs(tab, tampon);
}

/*************************************************		Client ou serveur ?		************************************************/

/** \fn  int choix_client_serv(void) */
int choix_client_serv(void){/** permet de savoir si le pc sera l hote ou le client*/
    int choix;
    do{
        system("cls");
        printf("Bienvenue dans la partie multijoueur d' EraDUCKation, souhaitez vous �tre hote ou rejoindre un ami pr�t � vous recevoir ? \n");
        printf("        Si vous voulez �tre l'h�te de la partie tapez 1 ;\n");
        printf("        Si vous voulez rejoindre un ami  tapez 2 ;\n");
        entrer_int(&choix);
    }while(choix <1 || choix >2);

    switch(choix){

        case 1 : //traitement hote
            break;
        case 2 : //traitement client
            break;
    }
} /** \return 1 si le joueur veut etre serveur et 2 si l hote veut etre client*/








