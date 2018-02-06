#include <stdlib.h>
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
					tab_canard[k].nourriture=0;
					tab_canard[k].etat=-1;	
				}
				matrice[i][j].nb_occupant=0;
			}
		}
	}
	if(align==1){
		for(i=random_min;i<random_max;i++){
			for(j=0;j<N;j++){
				for(k=0;k<nb_occupant;k++){
					tab_canard[k].nourriture=0;
					tab_canard[k].etat=-1;	
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
				tab_canard[k].nourriture=0;
				tab_canard[k].etat=-1;	
			}
			matrice[i][j].nb_occupant=0;
		}
	}
}

void famine(){
	nourriture_genere=0;
}

void reproduction_ralentie(){
	
}

void apparition_predateur();

/* Evenement bon */

void reproduction_acceleree();

void plus_nourriture();

void joker_nourriture();

void liberation_canard(); //ajout au score

void canard_invincible();




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






