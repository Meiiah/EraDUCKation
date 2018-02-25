#include <stdlib.h>
int rand_map(int taille_mat){ /*fonction pour choisir un random contenu dans la matrice*/
	return((rand()%(taille_mat-2))+1);
}