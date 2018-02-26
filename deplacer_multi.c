#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_connection.h"
#include "struct.h"
#include "deplacer.h"
#include "envoi_recep.h"
/*==============================================================================================================================*/

void deplacer_multi_serveur(case_t ** matrice,int taille_mat,int nourriture_accouplement,int socket_to_client){
    int i,j,k;
    int direction;
    int verif =1;

    /*! ENVOI  DU MESSAGE INDIQUANT LE DEBUT DU TRANSFERT DE DEPLACEMENT*/

    send(socket_to_client, 42, sizeof(int), 0);


    for(i=0; i<taille_mat; i++){
        for(j=0; j<taille_mat; j++){//pour chaque case de la matrice
                for(k=0; k<matrice[i][j].nb_occupant; i++){
                        if(matrice[i][j].tab_canard[k].etat==1){ //pour chaque canard qui peut se deplacer

                                // /!\ 1/3 des canards se d�placent, donc rand, si c est pas bon on le deplace pas donc break
                            if(rand()%3!=0)     break;
                                //si il peut se deplacer on continue

                                // si on voit un canard a accoupler on continue, sinon on continue les verifications
                            direction = voit_accouplement(matrice,nourriture_accouplement,i, j, k);

                            if(direction==-1){

                                //si il voit de la nourriture aller dessus sinon on deplace dabs une direction random arpres verif
                                direction = voit_nourriture(matrice,i, j, k);

                                if(direction==-1){
                                //sinon se deplacer d une case vers la direction random apres verif
                                    do{
                                        direction = rand()%4;
                                        /* FAIRE VERIF */

                                        switch(direction){// effets de bord
                                            case 0: if((! (i+1 >= taille_mat)  )&& matrice[ i+1 ][ j ].mur.murN !=1) //i croit et vu qu on est dans le tableau pas besoin de tout verifier
                                                        verif=1;
                                                 break;
                                            case 1: if((! (i-1 < 0) )&& matrice[ i-1 ][ j ].mur.murS !=1) //i decroit et vu qu on est dans le tableau pas besoin de tout verifier
                                                        verif=1;
                                                 break;
                                                                     // idem avec j
                                            case 2: if((! (j+1 >= taille_mat) )&& matrice[ i ][ j+1 ].mur.murE !=1 )
                                                        verif=1;
                                                 break;
                                            case 3:  if((! (j+1 >= taille_mat) )&& matrice[ i ][ j -1].mur.murO !=1 )
                                                        verif=1;
                                          }
                                        }while(verif == 0);

									/*! ENVOI  DU MESSAGE AVEC LES PARAM DE LA FONCTION DEPLACEMENT*/

									envoyer_int(socket_to_client, i);
									envoyer_int(socket_to_client, j);
									envoyer_int(socket_to_client, k);
									envoyer_int(socket_to_client, direction);

									deplacer_canard(matrice,i, j, k, direction);

                                }

                            }
                    }
            }
        }
    }

        /*! ENVOI  DU MESSAGE INDIQUANT LA FIN DU TRANSFERT DE DEPLACEMENT*/
    envoyer_int(socket_to_client, -1);
}

/*==============================================================================================================================*/

void deplacer_multi_client(int socket_to_serv){

    int i,j,k;
    int direction;
    int mess;

        //RECEPTION DU MESSAGE INDIQUANT LE DEBUT DU TRANSFERT DE DEPLACEMENT
    recv(socket_to_serv, mess, sizeof(int), 0);

    if(mess == 42){

        do{
             //TANT QU ON A PAS DEPLACE TOUS LES CANARDS A DEPLACER ON PREND LES DONNEES ET ON LES DEPLACE
            recevoir_int(socket_to_serv ,&i);
            if(i != -1){
                recevoir_int(socket_to_serv ,&j);
                recevoir_int(socket_to_serv ,&k);
                recevoir_int(socket_to_serv, &direction);
            }
            deplacer_canard(i, j, k, direction);
        }while(i != -1);
    }
}




