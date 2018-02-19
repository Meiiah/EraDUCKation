#include <stdlib.h>
#include <stdio.h>

typede enum clan_t{ bon, mechant };

typedef struct joueur_s{
    clan_t clan;
    char nom [20];
    void (*choix) (void);
}joueur_t

void entrer_int(int* val){
    scanf("%i", val);
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
    *val = c;
}


/* Merci au prof*/

int init_socket_serveur(int port){
	int ma_socket;
	struct sockaddr_in mon_address;
	bzero(&mon_address,sizeof(mon_address));
	mon_address.sin_port = htons(port);
	mon_address.sin_family = AF_INET;
	mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

	ma_socket = socket(AF_INET,SOCK_STREAM,0)
    bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));
    return ma_socket;
}



void main_multijoueur_reseau_serveur(int SocketClient){
    //variables :
    joueur_t tab [2];
    int tampon;

    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    //maintenant on initialise l ordre de jeu

}

void main_multijoueur_reseau_client(int SocketServeur){
    //variables :
    joueur_t tab [2];
    int tampon;

    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    //maintenant on initialise l ordre de jeu

}

int choix_client_serv(void){
    int choix;
    do{
        system("cls");
        printf("Bienvenue dans la partie multijoueur d' EraDUCKation, souhaitez vous être hote ou rejoindre un ami prêt à vous recevoir ? \n");
        printf("        Si vous voulez être l'hôte de la partie tapez 1 ;\n");
        printf("        Si vous voulez rejoindre un ami  tapez 2 ;\n");
        entrer_int(&choix);
    }while(choix <1 || choix >2);
    return choix;
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
    printf("Votre IP est : \n Vous avez choisi le port : %i \n Recherche d'un adversaire en cours");
            //creation de la socket client
    listen(socket_heberge,5);
    longueur_adresse = sizeof(adresse_client);
    client_socket = accept(socket_heberge,
                    (struct sockaddr *)&adresse_client,
                         &longueur_adresse);
            //connection effectuee

}

void menu_multi_reseau(void){ /* Choix de client ou serveur, avec ensuite lancement du jeu*/
    int choix;
     choix = choix_client_serv();

     switch(choix){
                    // Partie serveur
        case 1: menu_serveur();
                    main_multijoueur_reseau_serveur();
            break;
                    // Partie client
        case 2: menu_client();
                    main_multijoueur_reseau_client();
            break;
     }

}





