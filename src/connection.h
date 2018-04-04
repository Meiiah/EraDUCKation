#ifndef __connection_h__
#define __connection_h__

// Outils
void prendreIP(char nom[]);

// Set des socket
int init_socket_serveur(int port);
int menu_client(void);
int menu_serveur(void);


#endif