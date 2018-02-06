#include <stdio.h>
#define nb_event 4
void pseudo_joueur(char joueur[25]){
	printf("Saisir le pseudo du joueur");
	scanf("%s",joueur);
}
char mauv_evts[nb_event+1]={"tsunami", "tempete","famine","reproduction_ralenti","predateur"}
char bon_evts[nb_event+1]={"plus_nourriture","joker_nourriture","liberation_canard","canard_invassible","reproduction_accelere"}

void tab_event_mausvais(){
	int choix1=(rand() % (nb_event + 1); // Random du choix des evenement parmis 5 possibilités//
	int choix2=(rand() % (nb_event + 1);
	int choix3=(rand() % (nb_event + 1);
	printf("%s",mauv_evts[choix1]);
	printf("%s",mauv_evts[choix2]);
	printf("%s",mauv_evts[choix3]);
}

void tab_event_bon(){
	int choix1=(rand() % (nb_event + 1); // Random du choix des evenement parmis 5 possibilités//
	int choix2=(rand() % (nb_event + 1);
	int choix3=(rand() % (nb_event + 1);
	printf("%s",bon_evts[choix1]);
	printf("%s",bon_evts[choix2]);
	printf("%s",bon_evts[choix3]);
}

void choix_joueur(int result){
	int nature_event ( rand % 2); // Choix randome d'un evenement positif ou negatif//
	if (nature_envent%2==0){ // Si pair : Evenement positif //
		tab_event_bon();
		printf("Choisir le numero de l'evenement choisi");
		scanf("%i",result);// Saisit du choix du joueur//
		switch(result){
			case 1: mauvais[choix1]();
				break;
			case 2: mauvais[choix2]();
				break;
			case 3: mauvais[choix3]();
				break;
			default: printf("saisir un choix possible");
				break;
		}
		
	}
	else { // Si impaire: Evenement negatif//
		tab_event_mauv();
		printf("Choisir le numero de l'evenement choisi");
		scanf("%i",result); // Saisit du choix du joueur//
		switch(result){
			case 1: bon[choix1]();
				break;
			case 2:bon[choix2]();
				break;
			case 3: bon[choix3]();
				break;
			default: printf("saisir un choix possible");
				break;
		}
	}
}
