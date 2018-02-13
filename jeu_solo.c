#include "piege.h"
#include "nourriture.h"
#include "joueur.h"
#include "struct.h"

int jeu_solo(){
	int jeu=1 // 1 en cours de partie , 0 partie finit
	int nb_gen=0; // Compteur de génération
	

	while ( nb_gen<100 && presence_canard()==1){ // fin du jeu
		spawn_nourriture();
		piege();
		deplacer();
		choix_joueur();
		ajout_score(100,joueur,NULL);
		nb_gen++;
		printf("Score: %i",joueur.score);	
	}
}
