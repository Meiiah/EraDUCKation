#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"


#define MAX 4

/**
* \file labyrinthe.c
* \brief Programme comprennant la génération d'un labyrinthe
* \author MARCHAND Killian
* \version 3.0
* \date 20 Février 2018
*/

/** \struct ini_t*/
typedef struct{ /** Strucure appelant une structure mur_t, et une valeur de case*/
	mur_t mur;
	int valeur;
}ini_t;


///////////////////////////////////Fonctions affichage//////////

int compter_murs(ini_t mat[taille_mat_x][taille_mat_y],int i, int j){// on compte les murs au niveau de l angle, sur la case suivante et sur la case du dessous
    int res=0;
    if(mat[i][j].mur.murE) res++;
    if(mat[i][j].mur.murS) res++;
    if(j+1<taille_mat_y) if(mat[i][j+1].mur.murE) res++;
    if(i+1<taille_mat_x) if(mat[i+1][j].mur.murS) res ++;
    return res;
}

void afficher_angle(ini_t mat[taille_mat_x][taille_mat_y],int j, int i){ // affiche l angle bas-droite de la case [ j ] [ i ]
    int nb_murs;
    nb_murs = compter_murs(mat,j, i);
				

               if(nb_murs == 4)        printf("\u256c"); // SI TOUS LES MURS ADJACENTS A L ANGLE EXISTENT ON MEYT UN ANGE EN CROIX

               else

                // Si il y a 3 murs on identifie lesquels et on affiche en concéquence
               if(nb_murs == 3){
                   if(mat[j][i].mur.murE){
                       //si il y a le mur est
                       if(mat[j][i].mur.murS){ // si il y a le mur sud
                           if(j+1<taille_mat_y){
                               if(mat[j+1][i].mur.murS) // si il y a le mur sud de la case suivante
                                   printf("\u2569");

                               else    // sinon vu qu on a 3 murs on a forcement le mur est de la case du dessous
                                   printf("\u2563");
                           } else    // sinon vu qu on a 3 murs on a forcement le mur est de la case du dessous
                                   printf("\u2563");
                       }else // si on a pas le mur sud on a forcement les autres
                               printf("\u2560");

                   }else //comme precedemment
                      printf("\u2566");
               }

                else
                // Si il y a 2 murs on les identifie et on affiche en fonction
               if(nb_murs == 2){
                   if(mat[j][i].mur.murE){
                       //si il y a le mur est
                       if(mat[j][i].mur.murS){ // si il y a le mur sud
                           // on a les deux murs donc on affiche
                           printf("\u255d");

                        }else if(j+1<taille_mat_y){
                               if(mat[j+1][i].mur.murS) // si il y a le mur sud de la case suivante
                                   //on a les deux murs
                                   printf("\u255a");

                                else    // sinon vu qu on a 2 murs on a forcement le mur est de la case du dessous
                                   printf("\u2551");

                        }else    // sinon pareil (effet de bord
                                   printf("\u2551");

                    }else// fin si mur est
                       if(mat[j][i].mur.murS){ // si il y a le mur sud
                            if(j+1<taille_mat_y){
                               if(mat[j+1][i].mur.murS) // si il y a le mur sud de la case suivante
                                   //on a les deux murs
                                   printf("\u2550");

                                else    // sinon vu qu on a 2 murs on a forcement le mur est de la case du dessous
                                   printf("\u2557");

                            }else    // sinon pareil (effet de bord
                                   printf("\u2557");

                        }else// si pas le mur sud on a forcement les deus autres
                       printf("\u2554");

               }else // On a soit 1 mur, il se finit, et donc on affiche juste un espace, ou alors il y en a pas donc on fait un espace
               printf(" ");
}

/** \fn void affichage_laby()*/
void affichage_laby2(ini_t mat[taille_mat_x][taille_mat_y]){ /** Affichage du labyrinthe avec les murs sour forme ASCII */
	int i,j;
	int case_i;


	printf("\u2554");// angle haut gauche basique
	for(i=0; i<taille_mat_x-1; i++){// on affiche toute la ligne du haut
        printf("\u2550"); // on affiche l horizontal

        if(mat[i][0].mur.murE==1)   printf("\u2566"); // si la case en dessous a un mur a droite on affiche un coin en triple, et vu que c est juste la premiere ligne il y a pas de case au dessus
        else printf("\u2550"); // sinon on met une barre horizontale
	}printf("\u2550");
	printf("\u2557");


	for(i=0; i<taille_mat_x; i++){ // pour toute la matrice
            printf("\n");
            printf("\u2551");// a chaque changement de ligne on fait le mur de gauche

			for(j=0;j<taille_mat_x;j++){// pour chaque ligne on fait les murs verticaux
			    printf(" ");
                if(mat[j][i].mur.murE==1)   printf("\u2551"); //afficher mur si il faut
                else printf(" ");

			}printf("\n");


			if(i<N-1){
				if(mat[0][i].mur.murS)
					printf("\u2560");//afficher triple hdb
				else
					printf("\u2551");
			}else
				printf("\u255a");


			for(j=0;j<taille_mat_y;j++){// pour chaque ligne on fait les murs horizontaux, et les anges
				
			    if(mat[j][i].mur.murS) printf("\u2550"); //affichage du mur du bas
			    else printf(" ");

			    //afficher agle en fonction des cases adjacentes

                afficher_angle(mat,j, i);

			}

	}

}

////////////////////////////////Fonctions creation du labyrinthe//////////////

/** \fn void init_laby()*/
void init_laby(ini_t mat[taille_mat_x][taille_mat_y]){ /** Permet d'initialiser chaques mur du labyrinthe à 1(présence d'un mur) et de la valeur de la case à -1*/
	int i,j;
	for(i=0;i<taille_mat_x;i++){
		for(j=0;j<taille_mat_y;j++){

			mat[i][j].mur.murN = 1;
			mat[i][j].mur.murO = 1;
			mat[i][j].mur.murS = 1;
			mat[i][j].mur.murE = 1;
			mat[i][j].valeur = -1;

		}
	}
}

/** \fn void maxmin(int *max, int*min, int val1, int val2)*/
void maxmin(ini_t mat[taille_mat_x][taille_mat_y],int *max, int*min, int val1, int val2){/** Permet de déterminer le minimu et la maximum entre deux cases adjacentes*/
	if(val1<val2){
		 *min=val1;
		 *max=val2;
	}
	if(val1>val2){
		 *max=val1;
		 *min=val2;
	}
}
/** \fn void valeur_case(int x1, int y1, int x2, int y2, int *compteur)*/
void valeur_case(ini_t mat[taille_mat_x][taille_mat_y],int x1, int y1, int x2, int y2, int *compteur){/** Permet de changer la valeur d'une case du labyrinthe afin de creer des galeries. Appel la fonction minmax*/
	int i,j;
	int max, min;

	if(mat[x1][y1].valeur==-1 && mat[x2][y2].valeur==-1){

		mat[x1][y1].valeur=*compteur;
		mat[x2][y2].valeur=*compteur;
		(*compteur)++;


	} else if(mat[x1][y1].valeur==-1) {

		mat[x1][y1].valeur=mat[x2][y2].valeur;


	} else if( mat[x2][y2].valeur==-1){

		mat[x2][y2].valeur=mat[x1][y1].valeur;


	} else if ( mat[x1][y1].valeur != mat[x2][y2].valeur ){
		maxmin(mat,&max,&min,mat[x1][y1].valeur,mat[x2][y2].valeur);
		for(i=0;i<taille_mat_x;i++){
			for(j=0;j<taille_mat_y;j++){
				if(mat[i][j].valeur==max) mat[i][j].valeur=min;
			}
		}
	}
}

/** \fn void case_adja(int coord_x, int coord_y, int *compteur)*/
void case_adja(ini_t mat[taille_mat_x][taille_mat_y],int coord_x, int coord_y, int *compteur){ /** Choisie une case aléatoirement(Nord, Sud, Est, Ouest) afin de creer la galerie en cassant les murs entre les deux cases. Appel la fonction valeur_case */
	int case_adj;
	int temp_x= coord_x , temp_y= coord_y;

/*verification des coordonnees aux alentours pour eviter de casser un mur "bordure"*/
	do {
		temp_x= coord_x;
		temp_y= coord_y;
		case_adj= (rand() % (MAX));

		switch(case_adj){
			case 0: //case du dessus
				temp_y = coord_y-1;
				//fprintf(stderr, "on casse la case du dessus [%d,%d]\n", temp_x, temp_y);
				break;

			case 1: //case du dessous
				temp_y = coord_y+1;
				//fprintf(stderr, "on casse la case du dessous[%d,%d]\n", temp_x, temp_y);
				break;

			case 2: //case de gauche
				temp_x = coord_x-1;
				//fprintf(stderr, "on casse la case de gauche[%d,%d]\n", temp_x, temp_y);
				break;

			case 3: //case de droite
				temp_x = coord_x+1;
				//fprintf(stderr, "on casse la case de droite [%d,%d]\n", temp_x, temp_y);
				break;

		}
	}while(temp_x<0 || temp_y<0 || temp_x>=taille_mat_x || temp_y>=taille_mat_y); //fonction coord_valides

/*transformation des murs*/
		switch(case_adj){
			case 0: //case du dessus
				mat[coord_x][coord_y].mur.murN=0;
				mat[temp_x][temp_y].mur.murS=0;
				valeur_case(mat,coord_x,coord_y,temp_x,temp_y, compteur);
				break;

			case 1: //case du dessous
				mat[coord_x][coord_y].mur.murS=0;
				mat[temp_x][temp_y].mur.murN=0;
				valeur_case(mat,coord_x,coord_y,temp_x,temp_y, compteur);
				break;

			case 2: //case de gauche
				mat[coord_x][coord_y].mur.murO=0;
				mat[temp_x][temp_y].mur.murE=0;
				valeur_case(mat,coord_x,coord_y,temp_x,temp_y, compteur);
				break;

			case 3: //case de droite
				mat[coord_x][coord_y].mur.murE=0;
				mat[temp_x][temp_y].mur.murO=0;
				valeur_case(mat,coord_x,coord_y,temp_x,temp_y, compteur);
				break;

		}

}

/** \fn void coord_case(int* compteur)*/
void coord_case(ini_t mat[taille_mat_x][taille_mat_y],int* compteur){ /** Choisie aléatoirement une case dans le labyrinthe afin de lui attribué une valeur et de creer les galeries a partir des fonctions précédentes. Appel la fonction case_adj*/
	int coord_x;
	int coord_y;

	coord_x= (rand() % taille_mat_x);
	coord_y= (rand() % taille_mat_y);

	//fprintf(stderr, "case de depart [%d,%d]\n", coord_x, coord_y);

	case_adja(mat,coord_x,coord_y,compteur);
}

/** \fn int laby_fini()*/
int laby_fini(ini_t mat[taille_mat_x][taille_mat_y]){/** Vérification permettant de savoir si le labyrinthe est finit ou non*/
	int i,j;
	for(i=0; i<taille_mat_x; i++){
		for(j=0;j<taille_mat_y;j++){
			if(mat[i][j].valeur != 0)
				return 0;
		}
	}
	return 1;
}

/** \fn void creer_labyrinthe()*/
void creer_labyrinthe(ini_t mat[taille_mat_x][taille_mat_y]){ /** Appel toutes les fonctions pour creer le labyrinthe*/

	mur_t mur;

	int mur_value;
	int compteur=0;

	//fprintf(stderr, "initialisation laby lancee\n");
	init_laby(mat);
	//fprintf(stderr, "initialisation laby OK\n");

	int i=0;
	do{
		coord_case(mat,&compteur);
	}while(!laby_fini(mat));
	//	i++;
	//}while(i<5);

}

void copi_laby(ini_t mat[taille_mat_x][taille_mat_y],caract_mat_t * cmat){
	for(i=0; i<taille_mat_x; i++){
		for(j=0;j<taille_mat_y;j++){
			cmat->matrice[i][j].mur = mat.mur;
		}
	}
}
	


int main_laby(ini_t mat,carac_mat_t * cmat){
	srand(time(NULL));
	int i;
	
	ini_t TAMP= malloc(sizeof(ini_t)*cmat->taille_mat_x*cmat->taille_mat_y);//malloc
	ini_t mato =malloc(sizeof(ini_t *)*cmat->taille_mat_y);
	
	for(i=0; i<argc; i++){
		printf("argv[%d]=%s\n", i, argv[i]);
	}

	creer_labyrinthe(mat);
	affichage_laby2(mat);
	copi_laby(cmat);
	
	free(mato);
	free(TAMP);

	return EXIT_SUCCESS;

}
