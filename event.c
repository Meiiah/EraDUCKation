#include <stdlib.h>
#include "struct.h"
#include "joueur.h"
#include "outils.h"
#include "matrice.h"

#define M 10

int (*mauvais[M])(caract_mat_t *, joueur_t,joueur_t,int,int); /*tableau de pointeur sur les fonctions mauvaises*/
int (*bon[M])(caract_mat_t *, joueur_t,joueur_t,int,int); /*tableau de pointeur sur les fonctions bonnes*/
int (*event[M])(caract_mat_t *, joueur_t,joueur_t,int ,int); /*tableau de pointeur sur les deux types d'evenements*/

/*Evenement mauvais */

int tsunami(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	int i,j,k;
	int random_min=rand_map(cmat->taille_mat_x);
	int random_max=rand_map(cmat->taille_mat_y);
	while(random_min>random_max){
		random_min=rand_map(cmat->taille_mat_x);
		random_max=rand_map(cmat->taille_mat_y);
	}
	int align=rand()%1;// 0 pour horizontal 1 pour vertical

	if(align==0){
		for(i=0;i<cmat->taille_mat_x;i++){
			for(j=random_min;j<random_max;j++){
				for(k=0;k<cmat->matrice[i][j].nb_occupant;k++){
					cmat->matrice[i][j].tab_canard[k].nourriture=0;
					cmat->matrice[i][j].tab_canard[k].etat=-1;
					ajout_score(-50,joueur,joueur2);	
				}
				cmat->matrice[i][j].nb_occupant=0;
			}
		}
	}
	if(align==1){
		for(i=random_min;i<random_max;i++){
			for(j=0;j<cmat->taille_mat_y;j++){
				for(k=0;k<cmat->matrice[i][j].nb_occupant;k++){
					cmat->matrice[i][j].tab_canard[k].nourriture=0;
					cmat->matrice[i][j].tab_canard[k].etat=-1;	
					ajout_score(-50,joueur,joueur2);
				}
				cmat->matrice[i][j].nb_occupant=0;
			}
		}
	}
	return 1;
}

int tempete(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	int i,j,k;
	int random_min=rand_map(cmat->taille_mat_x);
	int random_max=rand_map(cmat->taille_mat_y);
	while(random_min>random_max){
		random_min=rand_map(cmat->taille_mat_x);
		random_max=rand_map(cmat->taille_mat_y);
	}

	for(i=random_min;i<random_max;i++){
		for(j=random_min;j<random_max;j++){
			for(k=0;k<cmat->matrice[i][j].nb_occupant;k++){
				cmat->matrice[i][j].tab_canard[k].nourriture=0;
				cmat->matrice[i][j].tab_canard[k].etat=-1;	
				ajout_score(-50,joueur,joueur2);
			}
			cmat->matrice[i][j].nb_occupant=0;
		}
	}
	return 1;
}

int famine(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	return nourriture_genere/=1.5;
	
}

int reproduction_ralentie(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	return nourriture_accouplement*=1.5; //variable de deplacer.c 
}

int apparition_predateur(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	int i,k;	
	int random_x;
	int random_y;
	int random_nbre_predateur=rand()%5;//random pour le nombre de prédateur
	for(i=0;i<random_nbre_predateur;i++){ //boucle pour tuer des canards en fonction du nombre de prédateur
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);
		//destruction des canards
		for(k=0;k<cmat->matrice[random_x][random_y].nb_occupant;k++){
			cmat->matrice[random_x][random_y].tab_canard[k].nourriture=0;
			cmat->matrice[random_x][random_y].tab_canard[k].etat=-1;	
			ajout_score(-100,joueur,joueur2);
		}
		cmat->matrice[random_x][random_y].nb_occupant=0;	
	}
	return 1;
}

/* Evenement bon */

int reproduction_acceleree(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	return nourriture_accouplement/=1.5;//variable de deplacer.c 
}

int plus_nourriture(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	return nourriture_genere*=1.5;//generation de nourriture plus élevée
}

int joker_nourriture(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	int i,j,k;
	for(i=0;i<cmat->taille_mat_x;i++){//balayage de toute la matrice
		for(j=0;j<cmat->taille_mat_y;j++){
			for(k=0;k<cmat->taille_mat_x;k++){
				cmat->matrice[i][j].tab_canard[k].nourriture=100;
			}
		}
	}
	return 1;
}
//ajout au score
int liberation_canard(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	int i,k;	
	int random_x;
	int random_y;
	int random_nbre_de_canard_liberer=rand()%5;//random pour le nombre de canard
	for(i=0;i<random_nbre_de_canard_liberer;i++){ //boucle pour tuer des canards en fonction du nombre de prédateur
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);
		//sortie des canards
		for(k=0;k<cmat->matrice[random_x][random_y].nb_occupant;k++){
			cmat->matrice[random_x][random_y].tab_canard[k].nourriture=0;
			cmat->matrice[random_x][random_y].tab_canard[k].etat=-1;	
			ajout_score(500,joueur,joueur2); //ajout de 500 points par libération
		}
		cmat->matrice[random_x][random_y].nb_occupant=0;	
	}
	return 1;
}

int canard_invincible(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
	/*prend un canard qui ne peut pas mourir*/
	return 1;
}

 int init_tab_event_mauvais(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
 	mauvais[0] = tsunami;
 	mauvais[1] = tempete;
 	mauvais[2] = famine;
 	mauvais[3] = reproduction_ralentie;
 	mauvais[4] = apparition_predateur;
 }
 
 int init_tab_event_bon(caract_mat_t * cmat, joueur_t joueur,joueur_t joueur2,int nourriture_genere,int nourriture_accouplement){
 	bon[0] = reproduction_acceleree;
 	bon[1] = plus_nourriture;
 	bon[2] = joker_nourriture;
 	bon[3] = liberation_canard;
 	bon[4] = canard_invincible;
 }

