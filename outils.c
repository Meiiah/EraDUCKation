#include <stdlib.h>
#include <stdio.h>



/**
* \file outils.c
* \brief Programme comprennant les piegfes dans le laby
* \author VAIDIE Camille, TOUZE Maxime,MARCHAND Killian,PHILIPPE Marion
* \version 1.0
* \date 20 Février 2018
*/

/** \fn int rand_map(int)*/
int rand_map(int taille_mat){ /*fonction pour choisir un random contenu dans la matrice*/
	return((rand()%(taille_mat-2))+1);
}

/** \fn void entrer_int(int* val) */
void entrer_int(int* val){ /** Permet une entrée d'un int, et seulement un int */  /** \param val fonctionne comme un scanf sans le cham %*/
    scanf("%i", val);
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
    *val = c;
}
