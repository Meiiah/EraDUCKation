#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_connection.h"
#include "struct.h"
#include "matrice.h"
#include "deplacer.h"
#include "outils_reseau.h"
/*==============================================================================================================================*/

void deplacer_multi_serveur(caract_mat_t * cmat,int nourriture_accouplement,int nourrture_generee, int socket_to_client){
    int i,j,k;
    int direction;
    int verif =1;

    /*! ENVOI  DU MESSAGE INDIQUANT LE DEBUT DU TRANSFERT DE DEPLACEMENT*/

    send(socket_to_client, debut_message, sizeof(int), 0);


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

                            /*! ENVOI  DU MESSAGE AVEC LES PARAM DE LA FONCTION DEPLACEMENT*/

                            envoyer_int(socket_to_client, i);
                            envoyer_int(socket_to_client, j);
                            envoyer_int(socket_to_client, k);
                            envoyer_int(socket_to_client, direction);
                            deplacer_canard(cmat,i, j, k, direction);
						}

		                    }
                        }
                    }
        	}//fin balayage matrice

        	 /*! ENVOI  DU MESSAGE INDIQUANT LA FIN DU TRANSFERT DE DEPLACEMENT*/
            envoyer_int(socket_to_client,fin_message);

        	reproduction(cmat, nourriture_accouplement, joueur,joueur2);
    		manger(cmat, nourriture_generee);

    	}
}





/*==============================================================================================================================*/

void deplacer_multi_client(caract_mat_t * cmat,int nourriture_accouplement, int nourriture_generee, int socket_to_serv){

    int i,j,k;
    int direction;
    int mess;

        //RECEPTION DU MESSAGE INDIQUANT LE DEBUT DU TRANSFERT DE DEPLACEMENT
    recv(socket_to_serv, mess, sizeof(int), 0);

    if(mess == debut_message){

        do{
             //TANT QU ON A PAS DEPLACE TOUS LES CANARDS A DEPLACER ON PREND LES DONNEES ET ON LES DEPLACE
            recevoir_int(socket_to_serv ,&i);
            if(i != fin_message){
                recevoir_int(socket_to_serv ,&j);
                recevoir_int(socket_to_serv ,&k);
                recevoir_int(socket_to_serv, &direction);
            }
            deplacer_canard(cmat,i, j, k, direction);
        }while(i !=  fin_message);

    }
    reproduction(cmat, nourriture_accouplement, joueur,joueur2);
    manger(cmat, nourriture_generee);
}




