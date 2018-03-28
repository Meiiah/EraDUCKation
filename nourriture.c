#include <stdlib.h>
#include "struct.h"
#include "matrice.h"
#include "outils.h"

/**
* \file nouriture.c
* \brief Programme concernant la nourriture des canards
* \author PHILIPPE Marion
* \version 1.0
* \date 19 Mars 2018
*/ 

/** \fn void spawn_nourriture(caract_mat_t,int)*/
void spawn_nourriture(caract_mat_t * cmat,int nourriture_genere){
	int i;
	int random_x;
	int random_y;
	//random pour le nombre d'appartion de nourriture
	int random_nbre_apparition=rand()%3;
	for(i=0;i<random_nbre_apparition;i++){
		random_x=rand_map(cmat->taille_mat_x);
		random_y=rand_map(cmat->taille_mat_y);

		//spawn de nourriture � des endroits al�atoires 
		cmat->matrice[random_x][random_y].pres_nourriture=nourriture_genere;
	}
}

/** \fn void manger(caract_mat_t)*/
void manger(caract_mat_t * cmat,int nourriture_genere){
    int i, j, k;
    int val_nutritive;

    for(i=0; i<cmat->taille_mat_x; i++){
        for(j=0; j<cmat->taille_mat_y; j++){//balayage matrice

            if(cmat->matrice[i][j].pres_nourriture){ // si il y a de la nourriture sur la case
                    if(cmat->matrice[i][j].nb_occupant > 0){
                        val_nutritive = rand()%nourriture_genere;
                        val_nutritive /= cmat->matrice[i][j].nb_occupant;   // on r�parti la nourriture entre les canards pr�sents sur la case

                        for(k=0 ; k<cmat->matrice[i][j].nb_occupant; k++){
                            cmat->matrice[i][j].tab_canard[k].nourriture += val_nutritive;
                        }
                    }
            }
        }
    }//fin balayage matrice

}
