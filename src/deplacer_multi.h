#ifndef __DEPLACER_MULTI_H__
#define __DEPLACER_MULTI_H__

void deplacer_multi_serveur(caract_mat_t * cmat,int nourriture_accouplement,int socket_to_client);

void deplacer_multi_client(caract_mat_t * cmat,int socket_to_serv);

#endif // __DEPLACER_MULTI_H__
