#ifndef  __MULTIJOUEUR_RESEAU_H__
#define __MULTIJOUEUR_RESEAU_H__
#include "struct.h"
#include "outils_reseau.h"

void envoyer_laby(int socket, caract_mat_t * cmat);     /** Fonction qui envoit le laby */
void envoyer_cmat(int socket, caract_mat_t * cmat); /** Fonction qui envoit la cmat pour l initialisation */

void commence_serveur(int socket, int role, joueur_reseau_t tab[]);     /** Demande au serveur si il veut commencer, et renvoit qui commencera */

void quel_role_serveur(int socket, joueur_reseau_t tab[]); /** demande au serveur quel role il veut jouer */

void demander_nom_serv(joueur_reseau_t tab[], int socket);

#endif // __MULTIJOUEUR_RESEAU_H__
