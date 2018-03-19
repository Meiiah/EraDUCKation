#ifndef __EVENT_H__
#define __EVENT_H__

#define M 10

int (*mauvais[M])(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);
int (*bon[M])(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

/* Evenement mauvais */
int tsunami(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int *nourriture_genere,int* nourriture_accouplement);

int tempete(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int famine(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int reproduction_ralentie(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int apparition_predateur(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

/* Evenement bon */

int reproduction_acceleree(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int plus_nourriture(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int joker_nourriture(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int liberation_canard(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);
int canard_invincible(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int* nourriture_genere,int* nourriture_accouplement);

int init_tab_event_mauvais();

int init_tab_event_bon();

#endif