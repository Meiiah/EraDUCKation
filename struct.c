#define N 20 //taille de la matrice//
typedef struct mur_s {
	int murN;
	int murS;
	int murE;
	int murO;
}mur_t;

typedef struct canard_s {
	int nourriture;	// /!\ POURCENTAGE//
	int etat; // 0: oeuf,1:adulte//
}canard_t;
	
typedef struct case_s{
	mur_t mur;
	canard_t tab_canard[N];
	int nb_occupant; 
}case_t

