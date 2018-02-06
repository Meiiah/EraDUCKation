#include <stdlib.h>

void (*p[N])(void); /*tableau de pointeur sur des fonctions*/

int rand_map(void){
	return((rand()%(N-2))+1);
}

/*Evenement mauvais */

void tsunami(){
	int i;
	int random_x_1=rand_map();
	int random_y_1=rand_map();
	int align=rand()%1;// 0 pour horizontal 1 pour vertical
	
		for(i=(random_x-);i<(random_x+1)
	
}

void tempête();

void famine();

void moins_nourriture();

void reproduction_ralentie();

/* Evenement bon */

void reproduction_acceleree();

void plus_nourriture();

void joker_nourriture();


void init-tab-event-mauvais(){
	*p[0] = tsunami;
	*p[1] = tempête;
	*p[2] = famine;
	*p[3] = moins_nourriture;
	*p[4] = reproduction_ralentie;
}

void init-tab-event-bon(){
	*p[0] = reproduction_acceleree;
	*p[1] = plus_nourriture;
	*p[2] = joker_nourriture;
}


void init-tab-event(){
	*p[0]=void init-tab-event-mauvais();
	*p[1]=void init-tab-event-bon();
}






