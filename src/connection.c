#include <stdio.h>
#include <stdlib.h>
#include "include_connection.h"
#include <string.h>

/**********************************************		UTILS		*****************************************/

void prendreIP(char nom[]){
	char res[256];
	gethostname(res, sizeof(res));
	
	struct hostent *host = gethostbyname(res);
	
	strcpy(nom, (inet_ntoa(**( (struct in_addr**)host->h_addr_list))) );

}



/**********************************************		INIT de la SOCKET serveur		*****************************************/

/* Merci au prof*/
/** \fn int init_socket_serveur(int port)*/
int init_socket_serveur(int port){ /**  initialise la socket du serveur */ /** \param port le port sur lequel on créé la socket */
	int ma_socket;
	struct sockaddr_in mon_address;
	bzero(&mon_address,sizeof(mon_address));
	mon_address.sin_port = htons(port);
	mon_address.sin_family = AF_INET;
	mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

	ma_socket = socket(AF_INET,SOCK_STREAM,0);
    bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));
    return ma_socket; /** \return la socket créée*/
}



/*************************************************		Pour la connection serveur client		************************************************/

/** \fn int menu_client(void) */
int menu_client(void){ /** demande au client le port et l ip du serveur, et créé la socket*/
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
	printf(" Adversaire trouvé ! ");
    return to_server_socket;
} /**  \return retourne la socket pour communiquer avec le serveur*/




/** \fn int menu_serveur(void) */
int menu_serveur(void){/** demande au serveur le port sur lequel il veut jouer , et le lie avec le client avec un veuillez patienter*/
    int socket_heberge, Socket_Client;
    struct sockaddr_in adresse_client;
    unsigned int longueur_adresse;
    int port;
    char IP[256];
    system("cls");
    printf("Sur quel port voulez-vous jouer? \n");
    scanf("%i", &port);
    socket_heberge = init_socket_serveur(port);

    prendreIP(IP);
    
    system("cls");
    printf("Votre IP est : %s \n Vous avez choisi le port : %i \n Recherche d'un adversaire en cours, veuillez patienter ....", IP ,port);
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
    
} /**  \return retourne la socket pour communiquer avec le client*/    
    
    