#include <stdlib.h>
#include <stdio.h>
#include "struct.h"


int gen = 12;

void sauvegarde(case_t **matrice,int N){//sauvegarde l avancee (nombre de generations), la taille N de la matrice et la matrice.
    FILE * fichier;
    fichier=fopen("sav.txt", "w"); //fichier de sauvegarde
    
    fwrite(&gen, sizeof(int),1,fichier);//on prend gen
    fwrite(&N, sizeof(int),1, fichier);//idem pour N
    fwrite(matrice, sizeof(case_t),N*N,fichier);//on recupere la matrice de la taille n*n

    fclose(fichier);
 }

void charger(case_t ** matrice, int N){//charge la matrice de jeu, sa taille N et le nombre de generation (gen,n,mat)
    FILE * fichier;
    fichier=fopen("sav.txt", "r");
    //on recupere les int
    fread(&gen, sizeof(int), 1, fichier);
    fread(&N, sizeof(int), 1, fichier);
    //on enleve l allocatiln obsolete de la matrice, on l alloc a la bonne taille, et on y met les donnees
    free(matrice);
    matrice=malloc(sizeof(case_t)*N*N);
    fread(matrice, sizeof(case_t),N*N,fichier);
    
    fclose(fichier);
}
/*
void main(){ // pour tester les fonctiins, a supprimer quand vérifié
    matrice=malloc(sizeof(case_t)*N*N);

    int i,j;
    for(i =0; i<N; i++){
        for(j=0; j<N; j++){
            mat[i][j]= i+j;
        }
    }

     for(i =0; i<N; i++){
        printf(" \n");
        for(j=0; j<N; j++){
            printf("%i ",mat[i][j]);
        }
    }

    sauvegarde();


    for(i =0; i<N; i++){
        for(j=0; j<N; j++){
            mat[i][j]= 0;
        }
    }
    
    charger();

    for(i =0; i<N; i++){
        printf(" \n");
        for(j=0; j<N; j++){
            printf("%i ",mat[i][j]);
        }
    }
    printf("gen:%i", gen);

}
*/