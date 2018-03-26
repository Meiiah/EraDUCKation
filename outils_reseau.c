
/**
 * \file multi_joueur_reseau.c
 * \brief Fonctions communes au serveur et au client 
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/


/** \fn void envoyer_int(int socket, int valeur)*/
 void envoyer_int(int socket, int valeur){ /** Fonction qui envoie un int a la socket donnée en parametre */
    send(socket, valeur, sizeof(int), 0);
 }

 /** \fn void recevoir_int(int socket, int * valeur) */
void recevoir_int(int socket, int * valeur){/** fonction qui recoit un int de la socket passée en parametre*/
    recv(socket, valeur, sizeof(int), 0);
 }

/**\fn  int demander_qui_commence(void)*/
int demander_qui_commence(){/** Demande si la personne veut commencer ou non */
	int qui;
	printf("Voulez-vous commencer? si oui tapez 1 si non tapez 0 : ");
	scanf("%i", &qui);

	return qui;
}

/**\fn void saisir_role(int * role) */
void saisir_role(int * role){ /** Demande quel rôle le joueur veut jouer */
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






















