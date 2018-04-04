#ifndef  __CLIENT_RESEAU_H__
#define __CLIENT_RESEAU_H__

#include "matrice.h"
#include "outils_reseau.h"

void recevoir_laby(int socket, caract_mat_t * cmat);     /** Fonction qui tecoit le laby */
caract_mat_t *  recev_init_laby(int socket); /** Fonction qui recoit la cmat pour l initialisation */

void commence_client(int socket, int role, joueur_reseau_t tab[]);     /** Demande au serveur si il veut commencer, et renvoit qui commencera */

void quel_role_client(int socket, joueur_reseau_t tab[]); /** demande au serveur quel role il veut jouer */

void demander_nom_client(joueur_reseau_t tab[]);

#endif // __CLIENT_RESEAU_H__
