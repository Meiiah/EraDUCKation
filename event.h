#define M 10

int (*mauvais[M])(void);
int (*bon[M])(void);

/* Evenement mauvais */
int tsunami(caract_mat_t * cmat, joueur_t joueur, joueur_t joueur2);

int tempete(caract_mat_t * cmat, joueur_t joueur, joueur_t joueur2);

int famine(int nourriture_genere);

int reproduction_ralentie(int nourriture_accouplement);

int apparition_predateur(caract_mat_t * cmat, joueur_t joueur, joueur_t joueur2);

/* Evenement bon */

int reproduction_acceleree(int nourriture_accouplement);

int plus_nourriture(int nourriture_genere);

int joker_nourriture(caract_mat_t * cmat);

int liberation_canard(caract_mat_t * cmat, joueur_t joueur, joueur_t joueur2); //ajout au score

int canard_invincible();

int init_tab_event_mauvais();

int init_tab_event_bon();