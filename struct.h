
/**
*\file struct.h
*\brief structure
*\author VAIDIE Camille
*\version 1.0
*\date 20 fevrier 2018
*/

#define nb_max 15

/** \struct mur_s struct.h*/
/** etat du mur*/
typedef struct mur_s {
	int murN;	//mur :1 , pas mur :0//
	int murS;
	int murE;
	int murO;
}mur_t;

/**\struct canard_s struct.h*/
/** etat des canards*/
typedef struct canard_s {
	int nourriture;	// /!\ POURCENTAGE//
	int etat; // 0: oeuf,1:adulte, -1:inexistant//
}canard_t;

/**struct case_s struct.h*/
/** etat des cases	*/
typedef struct case_s{
	mur_t mur; // Contient les 4murs : Nord,Est,Ouest,Sud d'une case//
	canard_t tab_canard[nb_max];
	int nb_occupant; 
	int pres_nourriture;
	int pres_piege;
}case_t;

/**\struct joueur_s struct.h*/
/**brief information joueur*/
typedef struct joueur_s{
	int score;
	char nom_joueur[25];
}joueur_t;

