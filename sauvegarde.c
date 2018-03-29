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
	fprintf(stderr, "sauvegarde %d,  %d, %d\n", generation, nourriture_genere, nourriture_accouplement);
	fwrite(&joueur , sizeof(joueur_t),1,fichier);//on sauvegarde le joueur 1 (ses points....)
	fwrite(&joueur2, sizeof(joueur_t),1,fichier);//on sauvegarde le nb generation (
 

	fprintf(stderr, "sauvegarde de la matrice %d, %d\n", cmat->taille_mat_x, cmat->taille_mat_y);
    fwrite(&(cmat->taille_mat_x), sizeof(int),1, fichier);//on sauvegarde cmat et donc les tailles etc
	fwrite(&(cmat->taille_mat_y), sizeof(int),1, fichier);
    fwrite(cmat->matrice[0], sizeof(case_t) * cmat->taille_mat_x * cmat->taille_mat_y, 1 ,fichier);//on sauvegarde la matrice de taille case t et de taille_mat_x*taille_mat_y elements

    fclose(fichier);
 }

/** \fn void charger(caract_mat_t * cmat,int nourriture_genere,int nourriture_accouplement,joueur_t joueur,joueur_t joueur2,int generation)*/
void charger(caract_mat_t * cmat,int* nourriture_genere,int* nourriture_accouplement,joueur_t* joueur,joueur_t* joueur2,int* generation)
{/**charge l avancee du jeu (nombre de generations),la nourriture nécessaire pour l accouplement, malloc cmat, charge les tailles de la matrice, l init et donc la malloc, et y met les valeurs.*/
    FILE * fichier;
	int t_y;
	int t_x;
    
    fichier=fopen("sav.txt", "r");
    //on recupere les int
	
    fread(&generation, sizeof(int),1,fichier);//on charge le nb generation

	fread(&nourriture_genere, sizeof(int),1,fichier);//on charge la nourritue générée

	fread(&nourriture_accouplement, sizeof(int),1,fichier);//on charge la nourriture d accouplement

	fread(&joueur , sizeof(joueur_t),1,fichier);//on charge le joueur 1 (ses points....)
	fread(&joueur2, sizeof(joueur_t),1,fichier);//on charge le nb generation (


    //on enleve les allocations obsoletes de la matrice, on l alloc a la bonne taille, et on y met les donnees
	fprintf(stderr, "On va supprimer cmat si besoin\n");
	//detruire_Cmatrice(cmat);
	fprintf(stderr, "On a supprime cmat (peut etre)\n");
	////////

    fread(&t_x, sizeof(int),1, fichier);//on charge cmat et donc les tailles etc
	fread(&t_y, sizeof(int),1, fichier);
	fprintf(stderr, "Creation de la matrice %d, %d\n", t_x,t_y);
    cmat= creation_matrice(t_x, t_y);
	fprintf(stderr, "Matrice créée %d, %d\n", cmat->taille_mat_x,cmat->taille_mat_y );
	fread(cmat->matrice[0], sizeof(case_t) * cmat->taille_mat_x * cmat->taille_mat_y, 1 ,fichier);

    fclose(fichier);
	fprintf(stderr, "Fichier chargé\n");
}
