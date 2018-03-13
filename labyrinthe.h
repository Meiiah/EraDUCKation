

#ifndef __LABYRINTHE_H__
#define __LABYRINTHE_H__


/** \struct ini_t*/
typedef struct{ /** Strucure appelant une structure mur_t, et une valeur de case*/
	mur_t mur;
	int valeur;
}ini_t;

int compter_murs(caract_mat_t*,ini_t ** ,int i, int j);// on compte les murs au niveau de l angle, sur la case suivante et sur la case du dessous

void afficher_angle(caract_mat_t *,ini_t ** ,int j, int i); // affiche l angle bas-droite de la case [ j ] [ i ]

void affichage_laby2(caract_mat_t *,ini_t **);//Affichage du labyrinthe avec les murs sour forme ASCII

void init_laby(caract_mat_t *,ini_t ** ); //Permet d'initialiser chaques mur du labyrinthe à 1(présence d'un mur) et de la valeur de la case à -1

void maxmin(ini_t **,int *, int *, int, int); //Permet de déterminer le minimu et la maximum entre deux cases adjacentes

void valeur_case(caract_mat_t *,ini_t **,int, int, int, int, int *); //Permet de changer la valeur d'une case du labyrinthe afin de creer des galeries. Appel la fonction minmax

void case_adja(caract_mat_t *,ini_t **,int, int, int *); //Choisie une case aléatoirement(Nord, Sud, Est, Ouest) afin de creer la galerie en cassant les murs entre les deux cases. Appel la fonction valeur_case

void coord_case(caract_mat_t *,ini_t **,int*); //Choisie aléatoirement une case dans le labyrinthe afin de lui attribué une valeur et de creer les galeries a partir des fonctions précédentes. Appel la fonction case_adj

int laby_fini(caract_mat_t *,ini_t **); //Vérification permettant de savoir si le labyrinthe est finit ou non

void creer_labyrinthe(caract_mat_t *,ini_t **); //Appel toutes les fonctions pour creer le labyrinthe

void copi_laby(ini_t **,caract_mat_t *);

int main_laby(caract_mat_t *);

#endif