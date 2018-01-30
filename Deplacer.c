#include <stdio.h>
#include <stdlib.h>
//debut 22h00 fin 22h40
//debut 23h30 fin 00:00
//tps total : 70min
#define N 10

int voit_nourriture(int i,int j,int k){
    //une direction, toute la ligne jusqua un mur
    int l = 1;
    int mur[4] = {0,0,0,0};
    //on renvoit la direction ou il voit le miam miam et -1 si il voit pas (choisi la nouriture la plus proche

    //dir 1
    while(true){//tant qu on a pas de mur partout(break) et qu on n'a pas de fruit (break)

        /*
        SI pas de mur enregistré on regarde si il y a un fruit, si c est le cas on break,
        puis on regarde si il y a un mur, et si il y a on memorise qu il y en a un et
            on verifie que tous les murs soient pas trouvés
    */
//////////////////////////////////////////////////////////////////////
                //pour i croissant direction est

        if(mur[0]==0){
            if(matrice[i+l][j].pres_nourriture==1){ //si presence de nourriture sur la ligne
                return 1;
            }
        }
        if(matrice[i+l][j].mur.murE == 0){
            if(mur[1]==1 && mur[2]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                return -1;
            mur[0] = 1;
        }

/////////////////////////////////////////////////////////////////////
                //pour i décroissant direction ouest

        if(mur[1]==0){
            if(matrice[i-l][j].pres_nourriture==1){
                return 2;
            }
        }
        if(matrice[i-l][j].mur.murO == 0){
            if(mur[0]==1 && mur[2]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                return -1;
            mur[1] = 1;
        }

/////////////////////////////////////////////////////////////////////
                //pour j croissant direction sud

        if(mur[2]==0){
            if(matrice[i][j+l].pres_nourriture==1){
                return 3;
            }
        }
        if(matrice[i][j+l].mur.murS == 0){
            if(mur[0]==1 && mur[1]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                return -1;
            mur[2] = 1;
        }

/////////////////////////////////////////////////////////////////////
                //pour j décroissant direction Nord

        if(mur[3]==0){
            if(matrice[i][j-l].pres_nourriture==1){
                return 4;
            }
        }
        if(matrice[i][j-l].mur.murN == 0){
            if(mur[0]==1 && mur[1]==1 && mur[2]==1) // sipas de nourriture visible retourner -1
                return -1;
            mur[3] = 1;
        }
        l++;
    }
    return -1;  // au cas où mais pas besoin normalement
}

/*=======================================================================================================================*/

void deplacer(void){
    int i,j,k;
    int direction;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){//pour chaque case de la matrice
                for(k=0; k<matrice[i][j].nb_occupants; i++){
                        if(matrice[i][j].tab_cannard[k]!= 0 && matrice[i][j].tab_cannard[k]!= -1){ //pour chaque canard qui peut se deplacer
                            direction = rand()%4;
                                // /!\ 1/3 des canards se déplacent, donc rand
                                //si il voit de la nourriture aller dessus
                                //sinon se deplacer d une case vers la direction random
                                //reverifier

                              //tirage aleatoire d une premiere direction
                            switch(direction){
                                case 0:
                                    break;
                                case 1:
                                    break;
                                case 2:
                                    break;
                                case 3:

                            }
                        }
            }
        }
    }
}
