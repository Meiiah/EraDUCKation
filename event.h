
/* Evenement mauvais */
void tsunami(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2);

void tempete(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2);

int famine(int nourriture_genere);

int reproduction_ralentie(int nourriture_accouplement);

void apparition_predateur(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2);

/* Evenement bon */

int reproduction_acceleree(int nourriture_accouplement);

int plus_nourriture(int nourriture_genere);

void joker_nourriture(case_t ** matrice,int taille_mat);

void liberation_canard(case_t ** matrice, int taille_mat, joueur_t joueur, joueur_t joueur2); //ajout au score

void canard_invincible();


