#ifndef  __FONCTION_MULTI_RESEAU_H__
#define __FONCTION_MULTI_RESEAU_H__

void choix_mechant_quijoue(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui permet de choisir entre 3 evenements mauvais*/
void choix_mechant_quirecoit(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui applique le choix mechant effectu� par l adversaire */

void choix_gentil_quijoue(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui permet de choisir entre 3 evenements gentil*/
void choix_gentil_quirecoit(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui applique le choix gentil effectu� par l adversaire */

void init_joueurs_serv(joueur_reseau_t tab[]);/** initialise le tableau joueurs du serveur */
void init_joueurs_client(joueur_reseau_t tab[]);/** initialise le tableau joueurs du client */

#endif // __FONCTION_MULTI_RESEAU_H__
