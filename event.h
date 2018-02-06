#include <stdlib.h>
#define N 20// N est le taille de la matrice
#define M 10 // taille tableau de pointeur
#define score_liberation_canard 500

//tour_actuel défini par camille

void (*mauvais[M])(void); /*tableau de pointeur sur les fonctions mauvaises*/
void (*bon[M])(void); /*tableau de pointeur sur les fonctions bonnes*/
void (*event[M])(void); /*tableau de pointeur sur les deux types d'evenements*/

int rand_map(void); /*fonction pour choisir un random contenu dans la matrice*/

/* Evenement mauvais */
void tsunami();

void tempete();

void famine();

void reproduction_ralentie();

void apparition_predateur();

/* Evenement bon */

void reproduction_acceleree();

void plus_nourriture();

void joker_nourriture();

void liberation_canard(); //ajout au score

void canard_invincible();

void init_tab_event_mauvais();

void init_tab_event_bon();

void init_tab_event();

