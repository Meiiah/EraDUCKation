#ifndef __DEPLACER_H__
#define __DEPLACER_H__

typedef enum{Aucune_direction = -1, Est = 1, Ouest=2, Sud =3, Nord = 4, Pas_besoin_de_bouger =42} t_direction;

t_direction voit_accouplement(caract_mat_t * cmat,int nourriture_accouplement,int i,int j,int k);
t_direction voit_nourriture(caract_mat_t * cmat,int i,int j);

void deplacer_canard(caract_mat_t * cmat,int i, int j, int k, int direction);

void deplacer(caract_mat_t * cmat, int nourriture_accouplement,int nourriture_genere, joueur_t joueur, joueur_t joueur2);

#endif // __DEPLACER_H__
