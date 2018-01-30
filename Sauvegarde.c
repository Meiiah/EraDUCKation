#include <stdlib.h>
#include <stdio.h>

#define N 10

int mat[N][N];
int gen = 12;

void sauvegarde(){
    FILE * fichier;
    int n = N;
    fichier=fopen("sav.txt", "w");
    fprintf(fichier, "%i ", gen);
    fwrite(mat, sizeof(int),N*N,fichier);

    fclose(fichier);
}

void charger(){
    FILE * fichier;
    fichier=fopen("sav.txt", "r");
    fscanf(fichier, "%i ", &gen);

    fread(mat, sizeof(int),N*N,fichier);
    fclose(fichier);
}

void main(){


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
