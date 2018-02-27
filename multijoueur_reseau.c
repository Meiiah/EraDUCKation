/**
 * \file multi_joueur_reseau.c
 * \brief fonctions principales de jeu multijoueur en réseau
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/

#include "include_connection.h"
#include "multijoueur.c"
#include "deplacer_multi.h"
#include "outils.h
#include "connection.h"



/*
faire fonction qui demande qui commence, si pas d accord tirage aleatoire
demande chacun de son coté, systeme sleep, et gestion alea ou non par serv
*/

/*
main multi res serv
*/


/**********************************************		INITIALISATION TOUR DE JEU		*******************************************/
int demander_qui_commence(){
	int qui;
	printf("Voulez-vous commencer? si oui tapez 1 si non tapez 0 : ");
	scanf("%i", &qui);
	
	return qui;
}

void commence_client(int socket, int role, joueur_multi_t tab[]){
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

//qui joue en premier sinon aleatoire
void commence_serveur(int socket, int role, joueur_multi_t tab[]){
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

//qui joue quel role sinon c est aleatoire
void saisir_role(int * role){
	printf("quel role voulez vous endosser ? \n");
	printf("	Le mechant tapez 0\n");
	printf("	Le gentil tapez 1\n");
	scanf("%i",role);
}

void afficher_role(int role){
	system("cls");
	if(role == 0)
		printf("\n				VOUS ETES LE MECHANT		\n");
	else
		printf("\n				VOUS ETES LE GENTIL			\n");
}

void quel_role_serveur(int socket, joueur_multi_t tab[]){
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

void quel_role_client(int socket, joueur_multi_t tab[]){
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

/**********************************************		JEU			*****************************************/

/** \fn main_multijoueur_reseau_client(int SocketServeur)*/
void main_multijoueur_reseau_client(int SocketServeur){/**  ce sera le "main" du jeu en multi coté client*/
    //variables :
    joueur_multi_t tab[2];

    init_tab_joueurs(tab, tampon);

    //maintenant on initialise l ordre de jeu

}

void main_multijoueur_reseau_serveur(int SocketServeur){
	
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
    return choix;
} /** \return 1 si le joueur veut etre serveur et 2 si l hote veut etre client*/

/*************************************************		menu		************************************************/


/** \fn void menu_multi_reseau(void) */

void menu_multi_reseau(void){ /** gere qui fait quoi*/
    int choix;
    int sockett;
     choix = choix_client_serv();

     switch(choix){
                    // Partie serveur
        case 1: sockett = menu_serveur();
                    main_multijoueur_reseau_serveur(sockett);
            break;
                    // Partie client
        case 2: sockett = menu_client();
                    main_multijoueur_reseau_client(sockett);
            break;
     }
}




