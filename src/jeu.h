#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "matrice.h"
#include "event.h"
#include "joueur.h"
#include "canard.h"
#include "labyrinthe.h"
#include "deplacer_multi.h"
#include "jeu_solo.h"
#include "multijoueur.h"



int choix_difficultee(int choix);
int choix_nbr_joueur(int choix,joueur_t * joueur,joueur_t * joueur2);
int jeu(void);