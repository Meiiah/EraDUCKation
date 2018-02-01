#include <stdlib.h>
#include <stdio.h>

int N =10;

case_t* matrice;
int gen = 12;

void sauvegarde(){
    FILE * fichier;
    fichier=fopen("sav.txt", "w");
    fwrite(&gen, sizeof(int),1,fichier);
    fwrite(&N, sizeof(int),1, fichier);
    fwrite(mat, sizeof(case_t),N*N,fichier);

    fclose(fichier);
 }

void charger(){
    FILE * fichier;
    fichier=fopen("sav.txt", "r");
    fread(&gen, sizeof(int), 1, fichier);
    fread(&N, sizeof(int), 1, fichier);
    free(matrice);
    matrice=malloc(sizeof(case_t)*N*N);
    fread(matrice, sizeof(case_t),N*N,fichier);
    fclose(fichier);
}

void main(){
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
