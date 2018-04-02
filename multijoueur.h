#ifndef __MULTIJOUEUR_H__
#define __MULTIJOUEUR_H__

typedef enum { gentil, mechant }clan_t;

typedef struct joueurm_s{

    joueur_t joueur;
    clan_t clan;
    char nom [20];
    void (*choix) (caract_mat_t *,joueur_t *, joueur_t * , int* , int*,int );
}joueur_multi_t;

int boucle_multi(caract_mat_t * cmat,joueur_t joueur1, joueur_t joueur2, int nourriture_genere , int nourriture_accouplement, int nb_gen, int tampon);

int main_multijoueur(caract_mat_t * cmat, int nourriture_genere, int nourriture_accouplement, int nb_gen);

#endif // __MULTIJOUEUR_H__
