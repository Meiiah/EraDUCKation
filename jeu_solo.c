#include <stdio.h>

#include "struct.h"
#include "piege.h"
#include "nourriture.h"
#include "joueur.h"
#include "canard.h"
#include "deplacer.h"
#include "deplacer_multi.h"

int jeu_solo(case_t ** matrice,int taille_mat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2){
	int jeu=1; // 1 en cours de partie , 0 partie finit
	int nb_gen=0; // Compteur de génération

	while ( nb_gen<100 && presence_canard(matrice,taille_mat)==1){ // fin du jeu

		spawn_nourriture(matrice,taille_mat,nourriture_genere);
		piege();
		deplacer(matrice,nourriture_accouplement);
		choix_joueur(matrice,taille_mat,nourriture_accouplement,nourriture_genere,joueur,joueur2);
		ajout_score(100,joueur,joueur2);
		nb_gen++;
		printf("Score: %i",joueur.score);	
	}
}
