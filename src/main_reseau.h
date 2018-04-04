#ifndef __MAIN_RESEAU_H__
#define __MAIN_RESEAU_H__
#include "outils_reseau.h"
void jeu_client(int socket, caract_mat_t * cmat, joueur_reseau_t tab[], int nourriture_accouplement, int nourriture_generee);/** Deroulement du jeu pour le client*/
void main_client(void);/** main pour le client */

void jeu_serv(int socket, caract_mat_t * cmat, joueur_reseau_t tab[],  int nourriture_accouplement, int nourriture_generee);/** Deroulement du jeu pour le serveur*/
void main_serveur(void); /** foncion main pour le serveur en mode réseau*/

void main_reseau(void);/** Le main en multijoueur qui permet de choisir si on est serveur ou client, et de lancer le main assicié */

#endif // __MAIN_RESEAU_H__
