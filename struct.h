
#define nb_max 10
int nb_gen;
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
	mur_t mur; // Contient les 4murs : Nord,Est,Ouest,Sud d'une case//
	canard_t tab_canard[nb_max];
	int nb_occupant; 
	int pres_nourriture;
	int pres_piege;
}case_t;

typedef struct joueur_s{
	int score;
	char nom_joueur[25];
}joueur_t;

int taille_mat;

case_t ** matrice;