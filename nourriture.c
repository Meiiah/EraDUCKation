void spawn_nourriture(int nourriture_genere){
	int i,k;
		
	int random_x;
	int random_y;
	int random_nbre_apparition=rand()%5;//random pour le nombre d'appartion de nourriture
	for(i=0;i<random_nbre_apparition;i++){ 
		random_x=rand_map();
		random_y=rand_map();
		//spawn de nourriture
		
		matrice[i][j].pres_nourriture=nourriture_genere;
			
	}
}
