#ifndef __JOUEUR_H__
#define __JOUEUR_H__

typedef enum{premier_choix=1,deuxieme_choix=2,troisieme_choix=3,sauvegarder=4,quitter_jeu=5}choix_t;

void ajout_score(int,joueur_t*, joueur_t*);
void caract_joueur(joueur_t*);
void tab_event_mauvais(int*,int*,int*);
void tab_event_bon(int*,int*,int*);
void choix_mechant(caract_mat_t * cmat,joueur_t * joueur, joueur_t * joueur2, int * nourriture_genere, int * nourriture_accouplement,int);
void choix_bon(caract_mat_t *,joueur_t *, joueur_t *, int* , int* ,int);
void choix_joueur(caract_mat_t *,joueur_t *, joueur_t *, int*, int*,int );

#endif
