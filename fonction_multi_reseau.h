#ifndef  __FONCTION_MULTI_RESEAU_H__
#define __FONCTION_MULTI_RESEAU_H__

void choix_mechant_quijoue(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui permet de choisir entre 3 evenements mauvais*/
void choix_mechant_quirecoit(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui applique le choix mechant effectué par l adversaire */

void choix_gentil_quijoue(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui permet de choisir entre 3 evenements gentil*/
void choix_gentil_quirecoit(int socket, caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int generation);/** fonction qui applique le choix gentil effectué par l adversaire */

#endif // __FONCTION_MULTI_RESEAU_H__
