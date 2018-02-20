#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

void affichage_laby();//Affichage du labyrinthe avec les murs sour forme ASCII

void init_laby(); //Permet d'initialiser chaques mur du labyrinthe à 1(présence d'un mur) et de la valeur de la case à -1

int maxmin(int *, int *, int, int); //Permet de déterminer le minimu et la maximum entre deux cases adjacentes

void valeur_case(int, int, int, int, int *); //Permet de changer la valeur d'une case du labyrinthe afin de creer des galeries. Appel la fonction minmax

void case_adja(int, int, int *); //Choisie une case aléatoirement(Nord, Sud, Est, Ouest) afin de creer la galerie en cassant les murs entre les deux cases. Appel la fonction valeur_case

void coord_case(int*); //Choisie aléatoirement une case dans le labyrinthe afin de lui attribué une valeur et de creer les galeries a partir des fonctions précédentes. Appel la fonction case_adj

int laby_fini(); //Vérification permettant de savoir si le labyrinthe est finit ou non

void creer_labyrinthe(); //Appel toutes les fonctions pour creer le labyrinthe