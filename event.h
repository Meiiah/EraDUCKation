
int (*mauvais[M])(void);
int (*bon[M])(void);

/* Evenement mauvais */
int tsunami(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2);

int tempete(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2);

int famine(int nourriture_genere);

int reproduction_ralentie(int nourriture_accouplement);

int apparition_predateur(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2);

/* Evenement bon */

int reproduction_acceleree(int nourriture_accouplement);

int plus_nourriture(int nourriture_genere);

int joker_nourriture(case_t ** matrice,int taille_mat);

int liberation_canard(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2); //ajout au score

int canard_invincible();

/*
int init_tab_mauvais();

int init_tab_bon();
*/
