
#define nb_max 10

typedef struct mur_s {
	int murN;	//mur :1 , pas mur :0//
	int murS;
	int murE;
	int murO;
}mur_t;

typedef struct canard_s {
	int nourriture;	// /!\ POURCENTAGE//
	int etat; // 0: oeuf,1:adulte, -1:inexistant//
}canard_t;
	
typedef struct case_s{
	mur_t mur;
	canard_t tab_canard[nb_max];
	int nb_occupant; 
	int pres_nourriture; //indique si il y a de la nouriture sur la case ou non, 0 nin 1 oui 
}case_t

