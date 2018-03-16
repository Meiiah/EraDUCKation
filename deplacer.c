#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "matrice.h"
#include "deplacer_multi.h"
#include "nourriture.h"
#include "reproduction.h"
#include "labyrinthe.h"

//debut 22h00 fin 22h40
//debut 23h30 fin 00:00
//tps total : 70min

/**
 * \file deplacer.c
 * \brief fichier contenant les fonctions de deplacement
 * \author Maxime Touzé
 * \version 0.8
 * \date 19 fevrier 2018
*/


/**\fn canard_t canard_vide(void) */
canard_t canard_vide(void){/**	renvoit un canard inexistant*/
    canard_t coincoin;
    coincoin.nourriture =0;
    coincoin.etat = -1;
    return coincoin;
}

/*=======================================================================================================================*/

/**\fn int voit_nourriture(int i,int j,int k) */
int voit_nourriture(caract_mat_t * cmat,int i,int j,int k){/**	fonction qui renvoit la direction dans laquelle le canard k de la case i;j voit de la nouriture (-1 si pas de vision dessus)	*/
    //une direction, toute la ligne jusqua un mur
    int l = 1;
    int mur[4] = {0,0,0,0};

    //on renvoit la direction ou il voit le miam miam et -1 si il voit pas (choisi la nouriture la plus proche

    if(cmat->matrice[i][j].pres_nourriture==1)
                    return 42; //revoit un chiffre qui ne sera pas traité, et donc le canard ne se déplacera pas


    //dir 1
    while(l < (cmat->taille_mat_x - i) || l < ( cmat->taille_mat_y - j)){//tant qu on a pas de mur partout(break) et qu on n'a pas de fruit (break)

        /**
        SI pas de mur enregistré on regarde si il y a un fruit, si c est le cas on break,
        puis on regarde si il y a un mur, et si il y a on memorise qu il y en a un et
            on verifie que tous les murs soient pas trouvés
    */
//////////////////////////////////////////////////////////////////////
                //pour i croissant direction est
    if(i+l < cmat->taille_mat_x) // si la case est valide
        if(mur[0]==0){ // et qu on a pas encore rencontré de mur dans cette direction
            if(cmat->matrice[i+l][j].pres_nourriture==1){ //si presence de nourriture sur la ligne on retourne la direction
                return 1;
            }
             
            if(cmat->matrice[i+l][j].mur.murE == 1){// sinon on regarde si il y a le mur
                if(mur[1]==1 && mur[2]==1 && mur[3]==1) // sipas de nourriture visible du tout retourner -1
                    return -1;
                mur[0] = 1; // si on a encore des chemins a traiter on continue le traitement
            }
        }

/////////////////////////////////////////////////////////////////////
                //pour i décroissant direction ouest
     if(i-l > 0)
        if(mur[1]==0){
            if(cmat->matrice[i-l][j].pres_nourriture==1){
                return 2;
            }

            if(cmat->matrice[i-l][j].mur.murO == 1){
                if(mur[0]==1 && mur[2]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                    return -1;
                mur[1] = 1;
            }
        }

/////////////////////////////////////////////////////////////////////
                //pour j croissant direction sud
     if(j+l < cmat->taille_mat_y)
        if(mur[2]==0){
            if(cmat->matrice[i][j+l].pres_nourriture==1){
                return 3;
            }

            if(cmat->matrice[i][j+l].mur.murS == 1){
                if(mur[0]==1 && mur[1]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                    return -1;
                mur[2] = 1;
            }
        }

/////////////////////////////////////////////////////////////////////
                //pour j décroissant direction Nord
    if(j-l >0)
        if(mur[3]==0){
            if(cmat->matrice[i][j-l].pres_nourriture==1){
                return 4;
            }

            if(cmat->matrice[i][j-l].mur.murN == 1){
                if(mur[0]==1 && mur[1]==1 && mur[2]==1) // sipas de nourriture visible retourner -1
                    return -1;
                mur[3] = 1;
            }
        }
    l++;
    }
    return -1;  // au cas où mais pas besoin normalement
}

/*================================================== Accouplement ==================================================================*/

/**	\fn int voit_accouplement(int i,int j,int k)	*/
int voit_accouplement(caract_mat_t * cmat,int nourriture_accouplement,int i,int j,int k){ /**	fonction qui renvoit la direction dans laquelle le canard k de la case i;j voit un partenaire de reprod (-1 si pas de vision dessus)	*/
    //une direction, toute la ligne jusqua un mur
    int l = 1; // distance où on cherche
    int cpt;
    int mur[4] = {0,0,0,0};
    //on renvoit la direction ou il voit le miam miam et -1 si il voit pas (choisi la nouriture la plus proche


    for(cpt=0; cpt<cmat->matrice[i+l][j].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
        if(cpt != k)
        if(cmat->matrice[i+l][j].tab_canard[cpt].etat==1 && cmat->matrice[i][j].tab_canard[cpt].nourriture > nourriture_accouplement){ //si presence de partenaire sur la case
            return 42;
        }
    }

    //dir 1
    while(l<cmat->taille_mat_x || l<cmat->taille_mat_y){//tant qu on a pas de mur partout(break) et qu on n'a pas de fruit (break)

        /**
        SI pas de mur enregistré on regarde si il y a un partenaire d accouplement, si c est le cas on break,
        puis on regarde si il y a un mur, et si il y a on memorise qu il y en a un et
            on verifie que tous les murs soient pas trouvés
    */
//////////////////////////////////////////////////////////////////////
                //pour i croissant direction est
     if(i+l < cmat->taille_mat_x)
        if(mur[0]==0){//si on a pas encore croise de mur
            if(cmat->matrice[i+l][j].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i+l][j].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i+l][j].tab_canard[cpt].etat==1 && cmat->matrice[i+l][j].tab_canard[cpt].nourriture > nourriture_accouplement){ //si presence de partenaire sur la case
                        return 1;
                    }
                }
            }

            if(cmat->matrice[i+l][j].mur.murE == 1){
                if(mur[1]==1 && mur[2]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                    return -1;
                mur[0] = 1;
            }
        }

/////////////////////////////////////////////////////////////////////
                //pour i décroissant direction ouest
     if(i-l >0)
        if(mur[1]==0){
             if(cmat->matrice[i-l][j].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i-l][j].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i-l][j].tab_canard[cpt].etat==1 && cmat->matrice[i-l][j].tab_canard[cpt].nourriture > nourriture_accouplement){ //si presence de partenaire sur la case
                        return 2;
                    }
                }
            }

            if(cmat->matrice[i-l][j].mur.murO == 1){
                if(mur[0]==1 && mur[2]==1 && mur[3]==1) // sipas de nourriture visible retourner -1
                    return -1;
                mur[1] = 1;
            }
        }

/////////////////////////////////////////////////////////////////////
                //pour j croissant direction sud
    if(j+l < cmat->taille_mat_y)
        if(mur[2]==0){
            if(cmat->matrice[i][j+l].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i][j+l].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i][j+l].tab_canard[cpt].etat==1 && cmat->matrice[i][j+l].tab_canard[cpt].nourriture > nourriture_accouplement){
                       return 3;
                    }
                }
            }

            if(cmat->matrice[i][j+l].mur.murS == 1){
                if(mur[0]==1 && mur[1]==1 && mur[3]==1) // sipas de partenaire visible retourner -1
                    return -1;
                mur[2] = 1;
            }
        }

/////////////////////////////////////////////////////////////////////
                //pour j décroissant direction Nord
    if(j-l >0)
        if(mur[3]==0){
            if(cmat->matrice[i][j-l].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i][j-l].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i][j-l].tab_canard[cpt].etat==1 && cmat->matrice[i][j-l].tab_canard[cpt].nourriture > nourriture_accouplement){
                       return 4;
                    }
                }
            }

            if(cmat->matrice[i][j-l].mur.murN == 1){
                if(mur[0]==1 && mur[1]==1 && mur[2]==1) // sipas de nourriture visible retourner -1
                    return -1;
                mur[3] = 1;
            }
        }
        l++;
    }
    return -1;  // au cas où mais pas besoin normalement
}

/*=======================================================================================================================*/

/**\fn void deplacer_canard(int i, int j, int k, int direction) */
void deplacer_canard(caract_mat_t * cmat,int i, int j, int k, int direction){/**	Deplace le kieme canard de la case i;j dans la direction donnée	*/

	fprintf(stderr,"\n--------MOOV--------\n");
    switch(direction){ //en fonction de la direction le canard avance
            case 1:
                   //on copie le canard a sa destination
                   cmat->matrice[i+1][j].tab_canard[cmat->matrice[i+1][j].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

                   //on indique l augmentation de lz population dans la case ciblee
                   cmat->matrice[i+1][j].nb_occupant ++;

                   //on enleve le canard dans la case originelle, le nombre de canard diminue donc
                   cmat->matrice[i][j].tab_canard[k] = canard_vide();
                   cmat->matrice[i][j].nb_occupant --;
                                    break;

            /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            case 2:
                   //on copie le canard a sa destination
                   cmat->matrice[i-1][j].tab_canard[cmat->matrice[i-1][j].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

                   //on indique l augmentation de lz population dans la case ciblee
                   cmat->matrice[i-1][j].nb_occupant ++;

                   //on enleve le canard dans la case originelle, le nombre de canard diminue donc
                   cmat->matrice[i][j].tab_canard[k] = canard_vide();
                   cmat->matrice[i][j].nb_occupant --;
                                        break;

            /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            case 3:
                   //on copie le canard a sa destination
                   cmat->matrice[i][j+1].tab_canard[cmat->matrice[i][j+1].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

                   //on indique l augmentation de lz population dans la case ciblee
                   cmat->matrice[i][j+1].nb_occupant ++;

                   //on enleve le canard dans la case originelle, le nombre de canard diminue donc
                   cmat->matrice[i][j].tab_canard[k] = canard_vide();
                   cmat->matrice[i][j].nb_occupant --;
                                     break;

            /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            case 4:
                   //on copie le canard a sa destination
                   cmat->matrice[i][j+1].tab_canard[cmat->matrice[i][j+1].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

                   //on indique l augmentation de lz population dans la case ciblee
                   cmat->matrice[i][j+1].nb_occupant ++;

                   //on enleve le canard dans la case originelle, le nombre de canard diminue donc
                   cmat->matrice[i][j].tab_canard[k] = canard_vide();
                   cmat->matrice[i][j].nb_occupant --;
                                        break;

    }
}

/*=======================================================================================================================*/

/**\fn void deplacer(void)*/
void deplacer(caract_mat_t * cmat, int nourriture_accouplement, joueur_t joueur, joueur_t joueur2){/** fonction qui déplace des canards tirés au sort d une case puis d une autre */
    int i,j,k;
    int direction=-1;
    int verif =1;

    for(i=0; i< cmat->taille_mat_x ; i++){
        for(j=0; j< cmat->taille_mat_y; j++){//pour chaque case de la matrice

                for(k=0; k<cmat->matrice[i][j].nb_occupant; k++){

                        if(cmat->matrice[i][j].tab_canard[k].etat==1){ //pour chaque canard qui peut se deplacer

                                // /!\ 1/3 des canards se déplacent, donc rand, si c est pas bon on le deplace pas donc break
                            if(rand()%3==0){
                                //si il peut se deplacer on continue
                                // si on voit un canard a accoupler on continue, sinon on continue les verifications
                            direction = voit_accouplement(cmat,nourriture_accouplement,i, j, k);
				fprintf(stderr,"\n accou %i", direction);
                            if(direction==-1){

                                //si il voit de la nourriture aller dessus sinon on deplace dabs une direction random arpres verif
                                direction = voit_nourriture(cmat,i, j, k);
				fprintf(stderr,"\n nourr %i\n", direction);
                                if(direction==-1){
                                //sinon se deplacer d une case vers la direction random apres verif
                                    do{
                                    direction = rand()%4 +1;
                                    /* FAIRE VERIF */

					   switch(direction){// effets de bord
								case 1: if((! (i+1 >= cmat->taille_mat_x)  )&& cmat->matrice[ i+1 ][ j ].mur.murN !=1) //i croit et vu qu on est dans le tableau pas besoin de tout verifier
											verif=1;
									 break;
								case 2: if((! (i-1 < 0) )&& cmat->matrice[ i-1 ][ j ].mur.murS !=1) //i decroit et vu qu on est dans le tableau pas besoin de tout verifier
											verif=1;
									 break;
														 // idem avec j
								case 3: if((! (j+1 >= cmat->taille_mat_y) )&& cmat->matrice[ i ][ j+1 ].mur.murE !=1 )
											verif=1;
									 break;
								case 4:  if((! (j-1 <0) )&& cmat->matrice[ i ][ j -1].mur.murO !=1 )
											verif=1;

                                    		}
                                    }while(verif == 0);

                                        

                                }
                            }deplacer_canard(cmat,i, j, k, direction);
                            }

                        }
                    }
        }//fin balayage matrice
        fprintf(stderr,"\nakii\n");
        //reproduction(cmat, nourriture_accouplement, joueur,joueur2);
        manger(cmat);
    }affichage_laby(cmat);
    fprintf(stderr,"FIN");
}


