#ifndef __DEPLACER_H__
#define __DEPLACER_H__


canard_t canard_vide(void);

int voit_nourriture(caract_mat_t * cmat,int i,int j,int k);

int voit_accouplement(caract_mat_t * cmat,int nourriture_accouplement,int i,int j,int k);

void deplacer_canard(caract_mat_t * cmat,int i, int j, int k, int direction);

void deplacer(caract_mat_t * cmat, int nourriture_accouplement,int nourriture_genere, joueur_t joueur, joueur_t joueur2);

#endif // __DEPLACER_H__
