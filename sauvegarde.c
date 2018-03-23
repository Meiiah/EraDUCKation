#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "matrice.h"

/**
 * \file deplacer.c
 * \brief fichier contenant les fonctions de deplacement
 * \author Maxime Touzé
 * \version 1.0
 * \date 19 mars 2018
*/

/** \fn void sauvegarde(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2,int generation)*/
void sauvegarde(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2,int generation)
{/**sauvegarde l avancee du jeu (nombre de generations),la nourriture nécessaire pour l accouplement,  les tailles de la matrice et la matrice.*/
    FILE * fichier;
    fichier=fopen("sav.txt", "w"); //fichier de sauvegarde
    
    fwrite(&generation, sizeof(int),1,fichier);//on sauvegarde le nb generation
	fwrite(&nourriture_genere, sizeof(int),1,fichier);//on sauvegarde la nourritue générée
	fwrite(&nourriture_accouplement, sizeof(int),1,fichier);//on sauvegarde la nourriture d accouplement

	fwrite(&joueur , sizeof(joueur_t),1,fichier);//on sauvegarde le joueur 1 (ses points....)
	fwrite(&joueur2, sizeof(joueur_t),1,fichier);//on sauvegarde le nb generation (
 
    fwrite(cmat, sizeof(caract_mat_t),1, fichier);//on sauvegarde cmat et donc les tailles etc
    fwrite(cmat->matrice[0], sizeof(case_t), (cmat->taille_mat_x * cmat->taille_mat_y) ,fichier);//on sauvegarde la matrice de taille case t et de taille_mat_x*taille_mat_y elements

    fclose(fichier);
 }

/** \fn void charger(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2,int generation)*/
void charger(caract_mat_t * cmat,int* nourriture_genere,int* nourriture_accouplement,joueur_t* joueur,joueur_t* joueur2,int* generation)
{/**charge l avancee du jeu (nombre de generations),la nourriture nécessaire pour l accouplement, malloc cmat, charge les tailles de la matrice, l init et donc la malloc, et y met les valeurs.*/
    FILE * fichier;
    
    fichier=fopen("sav.txt", "r");
    //on recupere les int

    fread(&generation, sizeof(int),1,fichier);//on sauvegarde le nb generation
	fread(&nourriture_genere, sizeof(int),1,fichier);//on sauvegarde la nourritue générée
	fread(&nourriture_accouplement, sizeof(int),1,fichier);//on sauvegarde la nourriture d accouplement

	fread(&joueur , sizeof(joueur_t),1,fichier);//on sauvegarde le joueur 1 (ses points....)
	fread(&joueur2, sizeof(joueur_t),1,fichier);//on sauvegarde le nb generation (


    //on enleve les allocations obsoletes de la matrice, on l alloc a la bonne taille, et on y met les donnees
	int i;
	if(cmat->matrice){
		
		free(cmat->matrice[0]);fprintf(stderr, "Avant le free");
		free(cmat->matrice);
	}
	if(cmat){
		free(cmat);
	}
	////////
    cmat=malloc(sizeof(case_t));
    fwrite(cmat, sizeof(caract_mat_t),1, fichier);

    init_matrice(cmat); 

	fread(cmat->matrice[0], sizeof(case_t), (cmat->taille_mat_x * cmat->taille_mat_y) ,fichier);

    fclose(fichier);
}
