#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

#define N 4
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

ini_t mat[N][N];



void aff(){
	int i,j;
	mur_t m;
	for(i=0; i<N; i++){
		for(j=0;j<N;j++){
			m = mat[j][i].mur;
			if(m.murN==1 || m.murS==1) fprintf(stderr,"_");
			else if(m.murN==0 || m.murS==0) fprintf(stderr," ");
			
			if(m.murE==1 || m.murO==1) fprintf(stderr,"|");
			else if(m.murE==0 || m.murO==0) fprintf(stderr," ");
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "#### FIN LABY\n");
}


/** \fn void affichage_laby()*/
void affichage_laby(){ /** Affichage du labyrinthe avec les murs sour forme ASCII */
	int i,j;
	int case_i;
	mur_t m;
	for(i=0; i<N; i++){
		for(case_i=0; case_i<3; case_i++){
			for(j=0;j<N;j++){
				
						m = mat[j][i].mur;

						//premier balayage
						if(case_i==0){
							if(m.murN==1 && m.murO==1) printf("\u2554");
							
							if(m.murN==1) printf("\u2550");
							else if(m.murN==0) printf(" ");
							if(m.murN==1 && m.murE==1) printf("\u2557");
						
							
						}
						//second balayage
						if(case_i==1){
							
							if(m.murE==1) printf("\u2551");
							if(m.murE==0 && m.murO==0) printf(" ");
							if(m.murO==1) printf("\u2551");
							
							
						}
						//troisieme balayage
						if(case_i==2){ 
							
							if(m.murS==1 && m.murO==1) printf("\u255A");
							
							if(m.murS==1) printf("\u2550");
							else if(m.murS==0) printf(" ");
							if(m.murS==1 && m.murE==1) printf("\u255D");
						
							
						}				
				}printf("\n");
		}
		
		
	}
}



/** \fn void init_laby()*/
void init_laby(){ /** Permet d'initialiser chaques mur du labyrinthe à 1(présence d'un mur) et de la valeur de la case à -1*/
	int i,j;	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
		
			mat[i][j].mur.murN = 1;
			mat[i][j].mur.murO = 1;
			mat[i][j].mur.murS = 1;
			mat[i][j].mur.murE = 1;
			mat[i][j].valeur = -1;
	
		}
	}		
}

//Peut etre passé en boite a outils
/** \fn void maxmin(int *max, int*min, int val1, int val2)*/
void maxmin(int *max, int*min, int val1, int val2){/** Permet de déterminer le minimu et la maximum entre deux cases adjacentes*/
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
void valeur_case(int x1, int y1, int x2, int y2, int *compteur){/** Permet de changer la valeur d'une case du labyrinthe afin de creer des galeries. Appel la fonction minmax*/
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
		maxmin(&max,&min,mat[x1][y1].valeur,mat[x2][y2].valeur);
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(mat[i][j].valeur==max) mat[i][j].valeur=min;
			}
		}
	} 
}

/** \fn void case_adja(int coord_x, int coord_y, int *compteur)*/
void case_adja(int coord_x, int coord_y, int *compteur){ /** Choisie une case aléatoirement(Nord, Sud, Est, Ouest) afin de creer la galerie en cassant les murs entre les deux cases. Appel la fonction valeur_case */
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
				fprintf(stderr, "on casse la case du dessus [%d,%d]\n", temp_x, temp_y);				
				break;
				
			case 1: //case du dessous				
				temp_y = coord_y+1;
				fprintf(stderr, "on casse la case du dessous[%d,%d]\n", temp_x, temp_y);			
				break;

			case 2: //case de gauche				
				temp_x = coord_x-1;
				fprintf(stderr, "on casse la case de gauche[%d,%d]\n", temp_x, temp_y);				
				break;

			case 3: //case de droite
				temp_x = coord_x+1;
				fprintf(stderr, "on casse la case de droite [%d,%d]\n", temp_x, temp_y);					
				break;

		}
	}while(temp_x<0 || temp_y<0 || temp_x>=N || temp_y>=N); //fonction coord_valides
		
/*transformation des murs*/
		switch(case_adj){
			case 0: //case du dessus
				mat[coord_x][coord_y].mur.murN=0;				
				mat[temp_x][temp_y].mur.murS=0;
				valeur_case(coord_x,coord_y,temp_x,temp_y, compteur);
				break;
				
			case 1: //case du dessous
				mat[coord_x][coord_y].mur.murS=0;				
				mat[temp_x][temp_y].mur.murN=0;
				valeur_case(coord_x,coord_y,temp_x,temp_y, compteur);
				break;

			case 2: //case de gauche
				mat[coord_x][coord_y].mur.murO=0;				
				mat[temp_x][temp_y].mur.murE=0;
				valeur_case(coord_x,coord_y,temp_x,temp_y, compteur);
				break;

			case 3: //case de droite
				mat[coord_x][coord_y].mur.murE=0;
				mat[temp_x][temp_y].mur.murO=0;
				valeur_case(coord_x,coord_y,temp_x,temp_y, compteur); 
				break;

		}
	
}

/** \fn void coord_case(int* compteur)*/
void coord_case(int* compteur){ /** Choisie aléatoirement une case dans le labyrinthe afin de lui attribué une valeur et de creer les galeries a partir des fonctions précédentes. Appel la fonction case_adj*/
	int coord_x; 
	int coord_y;
	
	coord_x= (rand() % N);
	coord_y= (rand() % N);
	
	fprintf(stderr, "case de depart [%d,%d]\n", coord_x, coord_y);
	
	case_adja(coord_x,coord_y,compteur);
}
	
/** \fn int laby_fini()*/
int laby_fini(){/** Vérification permettant de savoir si le labyrinthe est finit ou non*/
	int i,j;
	for(i=0; i<N; i++){
		for(j=0;j<N;j++){
			if(mat[i][j].valeur != 0)
				return 0;
		}
	}
	return 1;
}

/** \fn void creer_labyrinthe()*/
void creer_labyrinthe(){ /** Appel toutes les fonctions pour creer le labyrinthe*/
	
	mur_t mur;
	
	int mur_value;
	int compteur=0;

	//fprintf(stderr, "initialisation laby lancee\n");
	init_laby();	
	//fprintf(stderr, "initialisation laby OK\n");
	
	int i=0;
	do{
		coord_case(&compteur);
	}while(!laby_fini());
	//	i++;
	//}while(i<5);
	
}


int main(int argc, char**argv){
	srand(time(NULL));
	for(int i=0; i<argc; i++){
		printf("argv[%d]=%s\n", i, argv[i]);
	}

	creer_labyrinthe();
	aff();
	affichage_laby();
	

	return EXIT_SUCCESS;

}













