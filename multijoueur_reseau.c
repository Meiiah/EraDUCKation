/**
 * \file multi_joueur_reseau.c
 * \brief fonctions principales de jeu multijoueur en réseau
 * \author Maxime.T
 * \version 0.5
 * \date 20 / 02 / 2018
*/

#include "include_connection.h"
#include "multijoueur.c"

/** \fn void entrer_int(int* val) */
void entrer_int(int* val){ /** Permet une entrée d'un int, et seulement un int */  /** \param val fonctionne comme un scanf sans le cham %*/
    scanf("%i", val);
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
    *val = c;
}


/* Merci au prof*/
/** \fn int init_socket_serveur(int port)*/
int init_socket_serveur(int port){ /**  initialise la socket du serveur */ /** \param port le port sur lequel on créé la socket */
	int ma_socket;
	struct sockaddr_in mon_address;
	bzero(&mon_address,sizeof(mon_address));
	mon_address.sin_port = htons(port);
	mon_address.sin_family = AF_INET;
	mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

	ma_socket = socket(AF_INET,SOCK_STREAM,0)
    bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));
    return ma_socket; /** \return la socket créée*/
}


/** \fn int init_socket_serveur(int port)*/
int init_socket_serveur(int port){ /**  initialise la socket du serveur */ /** \param port le port sur lequel on créé la socket */
    //variables :
    joueur_multi_t tab[2];
    int tampon;

    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    //maintenant on initialise l ordre de jeu

}

void main_multijoueur_reseau_client(int SocketServeur){
    //variables :
    joueur_multi_t tab[2];
    int tampon;

    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    //maintenant on initialise l ordre de jeu

}

int choix_client_serv(void){
    int choix;
    do{
        system("cls");
        printf("Bienvenue dans la partie multijoueur d' EraDUCKation, souhaitez vous �tre hote ou rejoindre un ami pr�t � vous recevoir ? \n");
        printf("        Si vous voulez �tre l'h�te de la partie tapez 1 ;\n");
        printf("        Si vous voulez rejoindre un ami  tapez 2 ;\n");
        entrer_int(&choix);
    }while(choix <1 || choix >2);
    return choix;
}

int menu_client(){
    /* POMPE */
    struct sockaddr_in serverSockAddr;
	struct hostent *serverHostEnt;
	long hostAddr;
	int to_server_socket;
	int port;
	char SERVEURNAME[30];

	system("cls");
    printf("Sur quel port voulez-vous jouer? \n");
    scanf("%i", &port);
    printf("\nEntrez l'ip de votre adversaire \n");
    scanf("%s", SERVEURNAME);

	bzero(&serverSockAddr,sizeof(serverSockAddr));
	hostAddr = inet_addr(SERVEURNAME);
	if ( (long)hostAddr != (long)-1)
		bcopy(&hostAddr,&serverSockAddr.sin_addr,sizeof(hostAddr));
	else
	{
		serverHostEnt = gethostbyname(SERVEURNAME);
	  	if (serverHostEnt == NULL)
	  	{
			printf("gethost rate\n");
			exit(0);
	  	}
	  	bcopy(serverHostEnt->h_addr,&serverSockAddr.sin_addr,serverHostEnt->h_length);
	}
	serverSockAddr.sin_port = htons(port);
	serverSockAddr.sin_family = AF_INET;
	/* creation de la socket */
	if ( (to_server_socket = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("creation socket client ratee\n");
	  	exit(0);
	}
	/* requete de connexion */
	if(connect( to_server_socket,
				(struct sockaddr *)&serverSockAddr,
				sizeof(serverSockAddr)) < 0 )
	{
		printf("demande de connection ratee\n");
	  	exit(0);
	}
	/* -------------- */

    return to_server_socket;
}

int menu_serveur(){
    int socket_heberge, Socket_Client;
    struct sockaddr_in adresse_client;
    unsigned int longueur_adresse;
    int port;
    system("cls");
    printf("Sur quel port voulez-vous jouer? \n");
    scanf("%i", &port);
    socket_heberge = init_socket_serveur(port);

    system("cls");
    printf("Votre IP est : \n Vous avez choisi le port : %i \n Recherche d'un adversaire en cours", port);
            //creation de la socket client
    listen(socket_heberge,5);
    longueur_adresse = sizeof(adresse_client);
    Socket_Client = accept(socket_heberge,
                    (struct sockaddr *)&adresse_client,
                         &longueur_adresse);
            //connection effectuee

    system("cls");
    printf(" Adversaire trouvé ! ");

    return Socket_Client;

}

void menu_multi_reseau(void){ /* Choix de client ou serveur, avec ensuite lancement du jeu*/
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

int main(){

}



