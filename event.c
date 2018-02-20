#include <stdlib.h>
#include "struct.h"
#include "joueur.h"
#define N 20// N est le taille de la matrice
#define M 10 // taille tableau de pointeur


void (*mauvais[M])(void); /*tableau de pointeur sur les fonctions mauvaises*/
void (*bon[M])(void); /*tableau de pointeur sur les fonctions bonnes*/
void (*event[M])(void); /*tableau de pointeur sur les deux types d'evenements*/

int rand_map(void){ /*fonction pour choisir un random contenu dans la matrice*/
	return((rand()%(N-2))+1);
}

/*Evenement mauvais */

void tsunami(){
	int i,j,k;
	int random_min=rand_map();
	int random_max=rand_map();
	while(random_min>random_max){
		random_min=rand_map();
		random_max=rand_map();
	}
	int align=rand()%1;// 0 pour horizontal 1 pour vertical

	if(align==0){
		for(i=0;i<N;i++){
			for(j=random_min;j<random_max;j++){
				for(k=0;k<matrice[i][j].nb_occupant;k++){
					matrice[i][j].tab_canard[k].nourriture=0;
					matrice[i][j].tab_canard[k].etat=-1;
					ajout_score(-50,joueur,joueur2);	
				}
				matrice[i][j].nb_occupant=0;
			}
		}
	}
	if(align==1){
		for(i=random_min;i<random_max;i++){
			for(j=0;j<N;j++){
				for(k=0;k<matrice[i][j].nb_occupant;k++){
					matrice[i][j].tab_canard[k].nourriture=0;
					matrice[i][j].tab_canard[k].etat=-1;	
					ajout_score(-50,joueur,joueur2);
				}
				matrice[i][j].nb_occupant=0;
			}
		}
	}	
}

void tempete(){
	int i,j,k;
	int random_min=rand_map();
	int random_max=rand_map();
	while(random_min>random_max){
		random_min=rand_map();
		random_max=rand_map();
	}

	for(i=random_min;i<random_max;i++){
		for(j=random_min;j<random_max;j++){
			for(k=0;k<matrice[i][j].nb_occupant;k++){
				matrice[i][j].tab_canard[k].nourriture=0;
				matrice[i][j].tab_canard[k].etat=-1;	
				ajout_score(-50,joueur,joueur2);
			}
			matrice[i][j].nb_occupant=0;
		}
	}
}

int famine(int famine){
	return famine;
	
}

void reproduction_ralentie(){
	nourriture_accouplement=90; //variable de deplacer.c 
}

void apparition_predateur(){
	int i,k;	
	int random_x;
	int random_y;
	int random_nbre_predateur=rand()%5;//random pour le nombre de prédateur
	for(i=0;i<random_nbre_predateur;i++){ //boucle pour tuer des canards en fonction du nombre de prédateur
		random_x=rand_map();
		random_y=rand_map();
		//destruction des canards
		for(k=0;k<matrice[random_x][random_y].nb_occupant;k++){
			tab_canard[k].nourriture=0;
			tab_canard[k].etat=-1;	
			ajout_score(-100,joueur,joueur2);
		}
		matrice[random_x][random_y].nb_occupant=0;	
	}
}

/* Evenement bon */

void reproduction_acceleree(){
	nourriture_accouplement=30;//variable de deplacer.c 
}

void plus_nourriture(){
	nourriture_genere=60;//generation de nourriture plus élevée
}

void joker_nourriture(){
	int i,j,k;
	for(i=0;i<N;i++){//balayage de toute la matrice
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				matrice[i][j].tab_canard[k].nourriture=100;
			}
		}
	}
}
//ajout au score
void liberation_canard(){
	int i,k;	
	int random_x;
	int random_y;
	int random_nbre_de_canard_liberer=rand()%5;//random pour le nombre de canard
	for(i=0;i<random_nbre_canard;i++){ //boucle pour tuer des canards en fonction du nombre de prédateur
		random_x=rand_map();
		random_y=rand_map();
		//sortie des canards
		for(k=0;k<matrice[random_x][random_y].nb_occupant;k++){
			tab_canard[k].nourriture=0;
			tab_canard[k].etat=-1;	
			ajout_score(500,joueur,joueur2); //ajout de 500 points par libération
		}
		matrice[random_x][random_y].nb_occupant=0;	
	}
}

void canard_invincible(){
	/*prend un canard qui ne peut pas mourir*/
}

void init_tab_event_mauvais(){
	*mauvais[0] = tsunami;
	*mauvais[1] = tempete;
	*mauvais[2] = famine;
	*mauvais[3] = reproduction_ralentie;
	*mauvais[4] = apparition_predateur;
}

void init_tab_event_bon(){
	*bon[0] = reproduction_acceleree;
	*bon[1] = plus_nourriture;
	*bon[2] = joker_nourriture;
	*bon[3] = liberation_canard;
	*bon[4] = canard_invincible;
}


void init_tab_event(){
	*event[0]=init_tab_event_mauvais();
	*event[1]=init_tab_event_bon();
}






