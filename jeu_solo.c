#include <stdio.h>
#include "struct.h"
#include "matrice.h"
#include "piege.h"
#include "nourriture.h"
#include "joueur.h"
#include "canard.h"
#include "deplacer.h"
#include "deplacer_multi.h"
#include "labyrinthe.h"

int jeu_solo(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2){
	int jeu=1; // 1 en cours de partie , 0 partie finit
	int nb_gen=0; // Compteur de génération
	
	while ( nb_gen<100 && presence_canard(cmat)==1){ // fin du jeu
		
		spawn_nourriture(cmat,nourriture_genere);
		
		piege(cmat);
		affichage_laby(cmat);
		deplacer(cmat,nourriture_accouplement);
		
		choix_joueur(cmat,joueur,joueur2,&nourriture_genere,&nourriture_accouplement);
		
		ajout_score(100,joueur,joueur2);
	
		nb_gen++;
		printf("Score %s : %i\n",joueur.nom_joueur,joueur.score);
		printf("Nourriture accouplement: %i\n",nourriture_accouplement);
		printf("Nourriture générée: %i\n",nourriture_genere);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));
		
	}
	return 1;
}
