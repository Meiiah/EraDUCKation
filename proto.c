#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_LABY 20
#define MAX 3
case_t mat[TAILLE_LABY][TAILLE_LABY];

void affichage(){ //utilisation table ASCII
	for(i=0;i<;i++){
		for(j=0;j<TAILLE_LABY;j++){
			if(mat[i][j].mur.murN==1 || mat[i][j].mur.murS== 1) printf("_");
			if(mat[i][j].mur.murE==1 || mat[i][j].mur.murO== 1) printf("|");
		}
	}
}

void init_laby(){ /*initialisation de tous les murs de la map a 1*/
	for(i=0;i<TAILLE_LABY;i++){
		for(j=0;j<TAILLE_LABY;j++){
		
			mat[i][j].mur.murN= 1;
			mat[i][j].mur.murO= 1;
			mat[i][j].mur.murS= 1;
			mat[i][j].mur.murE= 1;
		}
	}		
}

int verif dessus

void case_adja(int coord_x, int coord_y, int compteur){ /*recupere une case des 4 cases adajacente de la case prit en random*/
	int case_adj;
	int temp_x =x , temp_y= y;

/*verification des coordonnees aux alentours pour eviter de casser un mur "bordure"*/
	do {
		case_adj= (rand() % (MAX+1));
	
		switch(case_adj){
			case 0: //case du dessus				
				temp_y = coord_y-1;
				
			case 1: //case du dessous				
				temp_y = coord_y+1;

			case 2: //case de gauche				
				temp_x = coord_x-1;

			case 3: //case de droite				
				temp_x = coord_x+1;

		}
	}while(coord_x<0 || coord_y<0 && coord_x>N || coord_y>N);
		
/*transformation des murs*/
		switch(case_adj){
			case 0: //case du dessus
				mat[coord_y][coord_x].mur.murN=0;				
				mat[temp_y][coord_x].mur.murS=0;
				mat[temp_y][coord_x]=compteur;
				
			case 1: //case du dessous
				mat[coord_y][coord_x].mur.murS=0;				
				mat[temp_y][coord_x].mur.murN=0;
				mat[temp_y][coord_x]=compteur;

			case 2: //case de gauche
				mat[coord_y][coord_x].mur.murO=0;				
				mat[coord_y][temp_x].mur.murE=0;
				mat[coord_y][temp_x]=compteur;

			case 3: //case de droite
				mat[coord_y][coord_x].mur.murE=0;
				mat[coord_y][temp_x].mur.murO=0;
				mat[coord_y][temp_x]=compteur;

		}
	
}

void coord_case(int compteur){ /* choix d'une case en random */
	int coord_x; 
	int coord_y;
	
	coord_x= (rand() % (TAILLE_LABY+1));
	coord_y= (rand() % (TAILLE_LABY+1));
	mat[coord_y][coord_x]=compteur;
	case_adja(coord_x,coord_y,compteur);
}
	
void laby(){ /*generation de l'interieur de la map*/
	
	mur_t mur;
	
	int mur_value;
	int compteur=0;
	compteur++;
	
	
	
	
	
}
