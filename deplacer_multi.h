#ifndef __DEPLACER_MULTI_H__
#define __DEPLACER_MULTI_H__

void deplacer_multi_serveur(case_t ** matrice,int taille_mat,int nourriture_accouplement,int socket_to_client);

void deplacer_multi_client(int socket_to_serv);

#endif // __DEPLACER_MULTI_H__
