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
/** fonction qui fait le déroulement du jeu */
int jeu_solo(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t * joueur,joueur_t * joueur2,int nb_gen){
	// fin du jeu si 100 génération ou qu'il n'y a plus de canard
	while ( nb_gen<100 && presence_canard(cmat)==1){ 
		printf("Nombre de génération: %i \n",nb_gen);
		printf("Score %s : %i\n",joueur->nom_joueur,joueur->score);
		printf("Nombre de canard: %i \n",nombre_canard(cmat));
		//fonction qui fait apparaïtre de la nourriture
		spawn_nourriture(cmat,nourriture_genere);
		// fonction qui fait apparaître des pièges
		piege(cmat); 
		affichage_laby(cmat); // fonction qui affiche le labyrinthe
		//fonction qui fait deplacer les canards, les fait manger, les fait se reproduire
		deplacer(cmat,nourriture_accouplement,nourriture_genere,*joueur,*joueur2);
		//fonction qui fait choisir le joueur entre 3 événements bon ou mauvais
		choix_joueur(cmat,joueur,joueur2,&nourriture_genere,&nourriture_accouplement,nb_gen);
		//detruit quelques tas de nourriture car ils sont périmés
		detruire_nourriture(cmat);
		nb_gen++;
	}
	return 1;
}