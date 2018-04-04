#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "matrice.h"
#include "deplacer.h"
#include "deplacer_multi.h"
#include "nourriture.h"
#include "reproduction.h"
#include "labyrinthe.h"
#include "canard.h"



/**
 * \file deplacer.c
 * \brief fichier contenant les fonctions de deplacement
 * \author Maxime Touzé
 * \version 0.8
 * \date 19 fevrier 2018
*/





/*=======================================================================================================================*/

/**\fn int voit_nourriture(int i,int j,int k) */
t_direction voit_nourriture(caract_mat_t * cmat,int i,int j){/**	fonction qui renvoit la direction dans laquelle le canard de la case i;j voit de la nouriture (-1 si pas de vision dessus)	*/
    //une direction, toute la ligne jusqua un mur
    int l = 1;
    int mur[4] = {0,0,0,0};

    //on renvoit la direction ou il voit le miam miam et -1 si il voit pas (choisi la nouriture la plus proche

    if(cmat->matrice[i][j].pres_nourriture==1)
                    return Pas_besoin_de_bouger ; //renvoit un chiffre qui ne sera pas traité, et donc le canard ne se déplacera pas


    //dir 1
    while(!(mur[0]==1 && mur[1]==1 && mur[2]==1 && mur[3]==1)){//tant qu on a pas de mur partout(break) et qu on n'a pas de fruit (break)

        /**
        SI pas de mur enregistré on regarde si il y a un fruit, si c est le cas on break,
        puis on regarde si il y a un mur, et si il y a on memorise qu il y en a un et
            on verifie que tous les murs soient pas trouvés
    */
//////////////////////////////////////////////////////////////////////
                //pour i croissant direction est
    if(i+l < cmat->taille_mat_x){ // si la case est valide
        if(mur[0]==0){ // et qu on a pas encore rencontré de mur dans cette direction
            if(cmat->matrice[i+l][j].pres_nourriture==1){ //si presence de nourriture sur la ligne on retourne la direction
                return Est;
            }

            if(cmat->matrice[i+l][j].mur.murE == 1){// sinon on regarde si il y a le mur
                mur[0] = 1; // si on a encore des chemins a traiter on continue le traitement
            }
        }
	}else
		mur[0] = 1;

/////////////////////////////////////////////////////////////////////
                //pour i décroissant direction ouest
     if(i-l > 0){
        if(mur[1]==0){
            if(cmat->matrice[i-l][j].pres_nourriture==1){
                return Ouest;
            }

            if(cmat->matrice[i-l][j].mur.murO == 1){
                mur[1] = 1;
            }
        }
	}else
		mur[1] = 1;


/////////////////////////////////////////////////////////////////////
                //pour j croissant direction sud
     if(j+l < cmat->taille_mat_y){
        if(mur[2]==0){
            if(cmat->matrice[i][j+l].pres_nourriture==1){
                return Sud;
            }

            if(cmat->matrice[i][j+l].mur.murS == 1){
                mur[2] = 1;
            }
        }
	}else
		mur[2] = 1;


/////////////////////////////////////////////////////////////////////
                //pour j décroissant direction Nord
    if(j-l >0){
        if(mur[3]==0){
            if(cmat->matrice[i][j-l].pres_nourriture==1){
                return Nord;
            }

            if(cmat->matrice[i][j-l].mur.murN == 1){
                mur[3] = 1;
            }
        }

	}else
		mur[3] = 1;

	l++;
	}
    return( Aucune_direction );
}

/*================================================== Accouplement ==================================================================*/

/**	\fn int voit_accouplement(int i,int j,int )	*/
t_direction voit_accouplement(caract_mat_t * cmat,int nourriture_accouplement,int i,int j,int kiem_canard){ /**	fonction qui renvoit la direction dans laquelle le canard k de la case i;j voit un partenaire de reprod (-1 si pas de vision dessus)	*/
    //une direction, toute la ligne jusqua un mur
    int l = 1; // distance où on cherche
    int cpt;
    int mur[4] = {0,0,0,0};
    //on renvoit la direction ou il voit le miam miam et -1 si il voit pas (choisi la nouriture la plus proche



    for(cpt=0; cpt<cmat->matrice[i][j].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
        if(cpt != kiem_canard){
						if(cmat->matrice[i][j].tab_canard[cpt].etat==1 && cmat->matrice[i][j].tab_canard[cpt].nourriture > nourriture_accouplement){ //si presence de partenaire sur la case
						    return Pas_besoin_de_bouger ;
						}
		    }
    }


    //dir 1
    while(! (mur[0]==1 && mur[1]==1 && mur[2]==1 && mur[3]==1)){//tant qu on a pas de mur partout(break) et qu on n'a pas de fruit (break)

        /**
        SI pas de mur enregistré on regarde si il y a un partenaire d accouplement, si c est le cas on break,
        puis on regarde si il y a un mur, et si il y a on memorise qu il y en a un et
            on verifie que tous les murs soient pas trouvés
    */
//////////////////////////////////////////////////////////////////////
                //pour i croissant direction est
     if(i+l < cmat->taille_mat_x){
        if(mur[0]==0){//si on a pas encore croise de mur
            if(cmat->matrice[i+l][j].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i+l][j].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i+l][j].tab_canard[cpt].etat==1 && cmat->matrice[i+l][j].tab_canard[cpt].nourriture > nourriture_accouplement){ //si presence de partenaire sur la case
                        return Est;
                    }
                }
            }

            if(cmat->matrice[i+l][j].mur.murE == 1){
                mur[0] = 1;
            }
        }
	}else
		mur[0] = 1;
/////////////////////////////////////////////////////////////////////
                //pour i décroissant direction ouest
     if(i-l >=0){
        if(mur[1]==0){
             if(cmat->matrice[i-l][j].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i-l][j].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i-l][j].tab_canard[cpt].etat==1 && cmat->matrice[i-l][j].tab_canard[cpt].nourriture > nourriture_accouplement){ //si presence de partenaire sur la case
                        return Ouest;
                    }
                }
            }

            if(cmat->matrice[i-l][j].mur.murO == 1){
                mur[1] = 1;
            }
        }
	}else
		mur[1] = 1;

/////////////////////////////////////////////////////////////////////
                //pour j croissant direction sud
    if(j+l < cmat->taille_mat_y){
        if(mur[2]==0){
            if(cmat->matrice[i][j+l].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i][j+l].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i][j+l].tab_canard[cpt].etat==1 && cmat->matrice[i][j+l].tab_canard[cpt].nourriture > nourriture_accouplement){
                       return Sud;
                    }
                }
            }

            if(cmat->matrice[i][j+l].mur.murS == 1){
                mur[2] = 1;
            }
        }
	}else
		mur[2] = 1;

/////////////////////////////////////////////////////////////////////
                //pour j décroissant direction Nord
    if(j-l >=0){
        if(mur[3]==0){
            if(cmat->matrice[i][j-l].nb_occupant>0){//si il y a des canards sur la case
                for(cpt=0; cpt<cmat->matrice[i][j-l].nb_occupant; cpt++){//on cherche si il y a au moins une cible pour accouplement
                    if(cmat->matrice[i][j-l].tab_canard[cpt].etat==1 && cmat->matrice[i][j-l].tab_canard[cpt].nourriture > nourriture_accouplement){
                       return Nord;
                    }
                }
            }

            if(cmat->matrice[i][j-l].mur.murN == 1){
                mur[3] = 1;
            }
        }

    }else
		mur[3] = 1;
	l++;
    }return Aucune_direction;  // au cas où mais pas besoin normalement
}

/*=======================================================================================================================*/

/**\fn void deplacer_canard(int i, int j, int k, int direction) */
void deplacer_canard(caract_mat_t * cmat,int i, int j, int k, int direction){/**	Deplace le kieme canard de la case i;j dans la direction donnée	*/

    switch(direction){ //en fonction de la direction le canard avance
            case Est:
					if( (i+1 < cmat->taille_mat_x  )&& cmat->matrice[ i ][ j ].mur.murE !=1){
		               //on copie le canard a sa destination
		               cmat->matrice[i+1][j].tab_canard[cmat->matrice[i+1][j].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

		               //on indique l augmentation de lz population dans la case ciblee
		               cmat->matrice[i+1][j].nb_occupant ++;

		               //on enleve le canard dans la case originelle, le nombre de canard diminue donc
		               cmat->matrice[i][j].tab_canard[k] = canard_vide();
		               cmat->matrice[i][j].nb_occupant --;
                    }               	break;

            /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            case Ouest:
					if( (i > 0) && cmat->matrice[ i ][ j ].mur.murO !=1){
			          //on copie le canard a sa destination
			          cmat->matrice[i-1][j].tab_canard[cmat->matrice[i-1][j].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

			           //on indique l augmentation de lz population dans la case ciblee
			           cmat->matrice[i-1][j].nb_occupant ++;

			           //on enleve le canard dans la case originelle, le nombre de canard diminue donc
			           cmat->matrice[i][j].tab_canard[k] = canard_vide();
			           cmat->matrice[i][j].nb_occupant --;
                    }                    break;

            /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            case Sud:
					if( (j+1 < cmat->taille_mat_y )&& cmat->matrice[ i ][ j ].mur.murS !=1 ){
		               //on copie le canard a sa destination
		               cmat->matrice[i][j+1].tab_canard[cmat->matrice[i][j+1].nb_occupant] = cmat->matrice[i][j].tab_canard[k];

		               //on indique l augmentation de lz population dans la case ciblee
		               cmat->matrice[i][j+1].nb_occupant ++;

		               //on enleve le canard dans la case originelle, le nombre de canard diminue donc
		               cmat->matrice[i][j].tab_canard[k] = canard_vide();
		               cmat->matrice[i][j].nb_occupant --;
                   }                  	break;

            /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            case Nord:
					if( (j >0) && cmat->matrice[ i ][ j ].mur.murN !=1 ){
		               //on copie le canard a sa destination
		               cmat->matrice[i][j-1].tab_canard[cmat->matrice[i][j-1].nb_occupant ] = cmat->matrice[i][j].tab_canard[k];

		               //on indique l augmentation de lz population dans la case ciblee
		               cmat->matrice[i][j-1].nb_occupant ++;

		               //on enleve le canard dans la case originelle, le nombre de canard diminue donc
		               cmat->matrice[i][j].tab_canard[k] = canard_vide();
		               cmat->matrice[i][j].nb_occupant --;
		            }                break;

    }

}

/*=======================================================================================================================*/

/**\fn void deplacer(void)*/
void deplacer(caract_mat_t * cmat, int nourriture_accouplement,int nourriture_genere, joueur_t joueur, joueur_t joueur2){/** fonction qui déplace des canards tirés au sort d une case puis d une autre */
    int i,j,k;
    int direction=-1;
    int verif =1;
	
    for(j=0; j< cmat->taille_mat_x ; j++){
    		for(i=0; i< cmat->taille_mat_y; i++){//pour chaque case de la matrice
        		for(k=0; k<cmat->matrice[i][j].nb_occupant; k++){
					
		    		if(cmat->matrice[i][j].tab_canard[k].etat==1){ //pour chaque canard qui peut se deplacer
		                        // /!\ 1/3 des canards se déplacent, donc rand, si c est pas bon on le deplace pas donc break
		                    if(rand()%3==0){
		                        //si il peut se deplacer on continue
		                        // si on voit un canard a accoupler on continue, sinon on continue les verifications
										
				                direction = voit_accouplement(cmat,nourriture_accouplement,i, j, k);
				                //fprintf(stderr,"\nFIN voit_accouplement\n");

		                    		if(direction==Aucune_direction){
		                        		//si il voit de la nourriture aller dessus sinon on deplace dabs une direction random arpres verif
											//fprintf(stderr,"\nDEB voit_nourriture i:%i j:%i \n", i, j);
		                        		direction = voit_nourriture(cmat,i, j);
										
		                        		if(direction==Aucune_direction){
		                        		//sinon se deplacer d une case vers la direction random apres verif
				                    		do{
									direction = rand()%4 +1;
									/* FAIRE VERIF */

										switch(direction){// effets de bord
											case Est:
												if( i+1 < cmat->taille_mat_x){
													//i croit et vu qu on est dans le tableau pas besoin de tout verifier
													if(cmat->matrice[ i ][ j ].mur.murE !=1){
														verif=1;
													}
												}
											break;

											case Ouest:
												if( i-1 >= 0){
												//i decroit et vu qu on est dans le tableau pas besoin de tout verifier
													if(cmat->matrice[ i ][ j ].mur.murO !=1)
														verif=1;
												}
											break;

											// idem avec j
											case Sud:
												if( j+1 < cmat->taille_mat_y ){
													if(cmat->matrice[ i ][ j ].mur.murS !=1 )
														verif=1;
												}
											break;

											case Nord:
												if( j-1 >=0){
													if(cmat->matrice[ i ][ j ].mur.murN !=1 )
														verif=1;
												}
											break;
										}

								}while(verif == 0);
							}
						}
						if(direction != Pas_besoin_de_bouger){
							deplacer_canard(cmat,i, j, k, direction);

						}
		                    }
                        }
                    }
        	}//fin balayage matrice
				
        	reproduction(cmat, nourriture_accouplement, joueur,joueur2);		
    		manger(cmat, nourriture_genere);
						
    	}
}

