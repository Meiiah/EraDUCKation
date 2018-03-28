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

/**
 * \file jeu_solo.c
 * \brief Algo de jeu solo
 * \author PHILLIPE Marion
 * \version 1.1
 * \date 19 Mars 2018
*/

/** \fn int jeu_solo(caract_mat_t,int,int,joueur_t,joueur_t)*/
<<<<<<< HEAD
int jeu_solo(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t * joueur,joueur_t * joueur2,int nb_gen){
	

	
	while ( nb_gen<100 && presence_canard(cmat)==1){ // fin du jeu
		printf("Score %s : %i\n",joueur->nom_joueur,joueur->score);
		printf("Nourriture accouplement: %i\n",nourriture_accouplement);
		printf("Nourriture générée: %i\n",nourriture_genere);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));
=======
int jeu_solo(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2,int nb_gen){
	
	while ( nb_gen<100 && presence_canard(cmat)==1){ // fin du jeu
>>>>>>> f391686e352b5d9963b53538561d186194776a87
		
		spawn_nourriture(cmat,nourriture_genere);
		
		piege(cmat);
		affichage_laby(cmat);
		deplacer(cmat,nourriture_accouplement,nourriture_genere,*joueur,*joueur2);
		
<<<<<<< HEAD
		choix_joueur(cmat,joueur,joueur2,&nourriture_genere,&nourriture_accouplement,nb_gen);
		
=======
		choix_joueur(cmat,&joueur,&joueur2,&nourriture_genere,&nourriture_accouplement,nb_gen);
		ajout_score(101,&joueur,&joueur2);
>>>>>>> f391686e352b5d9963b53538561d186194776a87
		nb_gen++;
		printf("Score %s : %i\n",joueur.nom_joueur,joueur.score);
		printf("Nourriture accouplement: %i\n",nourriture_accouplement);
		printf("Nourriture générée: %i\n",nourriture_genere);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));
		
	}
	return 1;
}
