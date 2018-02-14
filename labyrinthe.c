#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

#define N 4
#define MAX 4

typedef struct{
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
			fprintf(stderr, " [ %i, %i, %i, %i ],%i ", m.murN, m.murE, m.murS, m.murO,mat[j][i].valeur);
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "#### FIN LABY\n");
}

void init_laby(){ /*initialisation de tous les murs de la map a 1*/
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


void maxmin(int *max, int*min, int val1, int val2){
	if(val1<val2){
		 *min=val1;
		 *max=val2;
	}
	if(val1>val2){
		 *max=val1;
		 *min=val2;
	}
}


void valeur_case(int x1, int y1, int x2, int y2, int *compteur){
	int i,j;
	int max, min;
	if(mat[x1][y1].valeur==-1 && mat[x2][y2].valeur==-1){
		mat[x1][y1].valeur=*compteur;
		mat[x2][y2].valeur=*compteur;
		(*compteur)++;
	} else
	if(mat[x1][y1].valeur==-1) {
		mat[x1][y1].valeur=mat[x2][y2].valeur;
	} else if ( mat[x2][y2].valeur!=-1){
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


void case_adja(int coord_x, int coord_y, int *compteur){ /*recupere une case des 4 cases adajacente de la case prit en random*/
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

void coord_case(int* compteur){ /* choix d'une case en random */
	int coord_x; 
	int coord_y;
	
	coord_x= (rand() % N);
	coord_y= (rand() % N);
	
	fprintf(stderr, "case de depart (%d,%d]\n", coord_x, coord_y);
	
	case_adja(coord_x,coord_y,compteur);
}
	

int laby_fini(){
	int i,j;
	for(i=0; i<N; i++){
		for(j=0;j<N;j++){
			if(mat[i][j].valeur != 0)
				return 0;
		}
	}
	return 1;
}


void creer_labyrinthe(){ /*generation de l'interieur de la map*/
	
	mur_t mur;
	
	int mur_value;
	int compteur=0;

	//fprintf(stderr, "initialisation laby lancee\n");
	init_laby();	
	//fprintf(stderr, "initialisation laby OK\n");
	
	int i=0;
	do{
		coord_case(&compteur);
		aff();
	}while(!laby_fini());
	//	i++;
	//}while(i<5);
	
}


int main(int argc, char**argv){
	
	for(int i=0; i<argc; i++){
		printf("argv[%d]=%s\n", i, argv[i]);
	}

	creer_labyrinthe();
	aff();

	return EXIT_SUCCESS;

}













