#include <stdlib.h>
#include "struct.h"
#include "matrice.h"
#include "outils.h"

void spawn_nourriture(caract_mat_t * cmat,int nourriture_genere){
	int i,k;

	int random_x;
	int random_y;
	int random_nbre_apparition=rand()%5;//random pour le nombre d'appartion de nourriture
	for(i=0;i<random_nbre_apparition;i++){
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);

		//spawn de nourriture
		cmat->matrice[random_x][random_y].pres_nourriture=nourriture_genere;
	}
}

void manger(caract_mat_t * cmat){
    int i, j, k;
    int val_nutritive;

    for(i=0; i<cmat->taille_mat_x; i++){
        for(j=0; j<cmat->taille_mat_y; j++){//balayage matrice

            if(cmat->matrice[i][j].pres_nourriture){ // si il y a de la nourriture sur la case
                    if(cmat->matrice[i][j].nb_occupant > 0){
                        val_nutritive = rand()%101;
                        val_nutritive /= cmat->matrice[i][j].nb_occupant;   // on réparti la nourriture entre les canards présents sur la case

                        for(k=0 ; k<cmat->matrice[i][j].nb_occupant; k++){
                            cmat->matrice[i][j].tab_canard[k].nourriture += val_nutritive;
                        }
                    }
            }
        }
    }//fin balayage matrice

}
