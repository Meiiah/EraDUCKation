#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

void aff();

void init_laby(); //initialisation du labyrinthe

int maxmin(int *, int *, int, int); //determine le min et max pour la fonction "valeur_case"

void valeur_case(int, int, int, int, int *); //attribut puis change la valeur d'une case afin de creer le labyrinthe en cassant des murs

void case_adja(int, int, int *); //choisit une case adajacente, afin de savoir quelle mur casser en fonction d'une direction

void coord_case(int*); //choisit une case au hasard dans le labyrinthe, pour la fonction "case_adja"

int laby_fini(); //verifie si le labyrinthe est fini ou non

void creer_labyrinthe(); //creation du labyrinthe en appellant les fonction precedente