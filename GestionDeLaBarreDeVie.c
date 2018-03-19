#include <stdio.h>
#include <stdlib.h>
#define N 13

/**
* \file GestionDeLaBarreDeVie.c
* \brief Programme comprennant la gestion de la arre de vie en version terminal
* \author MARCHAND Killian
* \version 1.5
* \date 20 Février 2018
*/

/** \fn void vie_perdu(char tab[], int vie_restante)*/
void vie_perdu(char tab[], int vie_restante){/**Reactualisation de la barre de vie*/
    int i,j;
    //Reactualisation du nouveau nombre de points de vie//
    for(i=0;i< vie_restante;i++){
        tab[i]='=';
    }

    //Supprime le nombre de point de vie perdu (remplacement par espace vide)//
    for(j=0;j<N;j++){
        if(j>=vie_restante && tab[j]=='='){
            tab[j]=' ';
        }
    }
    printf("\n%s",tab);
}

/** \fn int Gestion_vie(char tab[], int point_vie_i)*/
int Gestion_vie(char tab[], int point_vie_i){/**Gestion de la vie restante/vie perdu*/
    int i;
    int point_vie;
    int degat;
    printf("\n nombre degat(0 et 10): ");
    scanf("%i",&degat);

    point_vie_i=point_vie_i-degat;
    printf("\nIl vous reste %i point de vie ", point_vie_i);

    if(point_vie_i!=point_vie){
        //appel fonction reactualisation barre de vie//
        vie_perdu(tab,point_vie_i);
    }
    return point_vie_i;
}

