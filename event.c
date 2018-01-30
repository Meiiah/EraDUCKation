void (*p[N])(void);


/*Evenement mauvais */

void tsunami();

void tempête();

void famine();

void moins_nourriture();

void reproduction_ralentie();

/* Evenement bon */

void reproduction_acceleree();

void plus_nourriture();

void joker_nourriture();


void init-tab-event(void (*p[N])(void)){
	*p[0] = tsunami;
	*p[1] = tempête;
	*p[2] = famine;
	*p[3] = moins_nourriture;
	*p[4] = reproduction_ralentie;
	*p[5] = reproduction_acceleree;
	*p[6] = plus_nourriture;
	*p[7] = joker_nourriture;
}

