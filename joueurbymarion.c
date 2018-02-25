#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "event.h"
#include "joueur.h"

/**
*\file joueur.c
*\brief programme qui gere tout ce qui est en rapport avec le joueur
*\author VAIDIE Camille
*\version 1.0
*\date 20 fevrier 2018
*/

#define nb_event 4
/** \fn void ajout_score(int,joueur_t,joueur_t)*/
/**fonction d'ajour de score des deux joueurs*/

void ajout_score(int point,joueur_t joueur, joueur_t joueur2){
	
	joueur.score+=point; // ajout des points en fonction de l'action faite
	if(strcmp(joueur2.nom_joueur,"null")){
		joueur2.score-=point;
	}
}

/**\fn void caract_joueur(joueur_t)*/
/** saisi du pseudo du joueur */
void caract_joueur(joueur_t joueur){
	printf("Saisir le pseudo du joueur");
	scanf("%s",joueur.nom_joueur);
	joueur.score=0;
}



/** \fn void choix_mauvais(void)*/
void choix_mechant(case_t ** matrice,int taille_mat,int nourriture_accouplement,int nourriture_genere,joueur_t joueur, joueur_t joueur2){
	int result;
	int choix1,choix2,choix3;
	choix1= ( rand()%4 )+6; // entre 6 et 10
	do{
		choix2=  ( rand()%4 )+6;
	}while(choix2==choix1);
	do{
		choix3=  ( rand()%4 )+6;
	}while(choix3==choix1 || choix3==choix2);
	

	if(choix1==6 || choix2==6 || choix3==6){
		printf("Accelère la reproduction des canards");
	}
	if(choix1==7 || choix2==7 || choix3==7){
		printf("Génération de nourriture augmentée");
	}
	if(choix1==8 || choix2==8 || choix3==8){
		printf("Remplie toutes les réverses de nourriture des canards");
	}
	if(choix1==9 || choix2==9 || choix3==9){
		printf("Libère entre 0 et 5 canards");
	}
	if(choix1==10 || choix2==10 || choix3==10){
		printf("Rend un canard invincible");
	}

	
	do{
		printf("Choisir le numero de l'evenement choisit");
		scanf("%i",&result);// Saisit du choix du joueur//
	}while(result!=choix1 && result!=choix2 && result!=choix3);
	
	switch(result){
		case 6: reproduction_acceleree(nourriture_accouplement);
			break;
		case 7: plus_nourriture(nourriture_genere);
			break;
		case 8: joker_nourriture(matrice,taille_mat);
			break;
		case 9: liberation_canard(matrice, taille_mat,joueur,joueur2);
			break;
		case 10: canard_invincible();
			break;
	}
}

/** \fn void choix_bon(void)*/
/** choix random parmis les evenements bon */

void choix_bon(case_t ** matrice,int taille_mat,int nourriture_accouplement,int nourriture_genere,joueur_t joueur, joueur_t joueur2){
	int result;
	int choix1,choix2,choix3;
	choix1= ( rand()%4 )+1; // entre 1 et 5
	do{
		choix2=  ( rand()%4 )+1;
	}while(choix2==choix1);
	do{
		choix3=  ( rand()%4 )+1;
	}while(choix3==choix1 || choix3==choix2);
	

	if(choix1==1 || choix2==1 || choix3==1){
		printf("Lance un tsunami sur le labyrinthe");
	}
	if(choix1==2 || choix2==2 || choix3==2){
		printf("Lance une tempete sur le labyrinthe");
	}
	if(choix1==3 || choix2==3 || choix3==3){
		printf("Famine : Réduit la nourriture générée");
	}
	if(choix1==4 || choix2==4 || choix3==4){
		printf("Réduit la reproduction des canards");
	}
	if(choix1==5 || choix2==5 || choix3==5){
		printf("Appartion de 0 à 5 prédateurs de canards");
	}

	
	do{
		printf("Choisir le numero de l'evenement choisit");
		scanf("%i",&result);// Saisit du choix du joueur//
	}while(result!=choix1 && result!=choix2 && result!=choix3);
	
	switch(result){
		case 6: tsunami(matrice, taille_mat, joueur, joueur2);
			break;
		case 7: tempete(matrice, taille_mat, joueur, joueur2);
			break;
		case 8: famine(nourriture_genere);
			break;
		case 9: reproduction_ralentie( nourriture_accouplement);
			break;
		case 10: apparition_predateur( matrice,  taille_mat, joueur,  joueur2);
			break;
	}
}

/** \fn void choix_joueur(void)*/
/** choix du joueur parmis les evenements */
void choix_joueur(case_t ** matrice,int taille_mat,int nourriture_accouplement,int nourriture_genere,joueur_t joueur, joueur_t joueur2){
	int nature_event= ( rand() % 2); // Choix randome d'un evenement positif ou negatif//
	if (nature_event%2==0){ // Si pair : Evenement negatif //
		choix_mechant(matrice, taille_mat,nourriture_accouplement, nourriture_genere, joueur,  joueur2);
		
	}
	else { // Si impaire: Evenement positif//
		choix_bon( matrice, taille_mat,nourriture_accouplement,nourriture_genere, joueur,  joueur2);
	}
}
