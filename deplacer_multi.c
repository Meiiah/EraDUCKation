#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "include_connection.h"
#include "struct.h"
#include "deplacer.h"
/*==============================================================================================================================*/

void deplacer_multi_serveur(int socket_to_client){
    int i,j,k;
    int direction;
    int verif =1;
    char buffer[512];

    /*! ENVOI  DU MESSAGE INDIQUANT LE DEBUT DU TRANSFERT DE DEPLACEMENT*/
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"DEB_DEP");
    send(socket_to_client, buffer, 512, 0);


    for(i=0; i<taille_mat; i++){
        for(j=0; j<taille_mat; j++){//pour chaque case de la matrice
                for(k=0; k<matrice[i][j].nb_occupant; i++){
                        if(matrice[i][j].tab_canard[k].etat==1){ //pour chaque canard qui peut se deplacer

                                // /!\ 1/3 des canards se d�placent, donc rand, si c est pas bon on le deplace pas donc break
                            if(rand()%3!=0)     break;
                                //si il peut se deplacer on continue

                                // si on voit un canard a accoupler on continue, sinon on continue les verifications
                            direction = voit_accouplement(i, j, k);

                            if(direction==-1){

                                //si il voit de la nourriture aller dessus sinon on deplace dabs une direction random arpres verif
                                direction = voit_nourriture(i, j, k);

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

                                        }while(verif == 0);

                                        /*! ENVOI  DU MESSAGE AVEC LES PARAM DE LA FONCTION DEPLACEMENT*/
                                        memset(buffer, 0, sizeof(buffer));
                                        sprintf(buffer,"%i%i%i%i",i,j,k, direction);
                                        send(socket_to_client, buffer, 512, 0);

                                        deplacer_canard(i, j, k, direction);
                                }
                            }

                            }
                    }
            }
        }
    }

        /*! ENVOI  DU MESSAGE INDIQUANT LA FIN DU TRANSFERT DE DEPLACEMENT*/
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"FIN_DEP");
    send(socket_to_client, buffer, 512, 0);
}

/*==============================================================================================================================*/

void deplacer_multi_client(int socket_to_serv){

    int i,j,k;
    int direction;
     char buffer[512];

        /*! RECEPTION DU MESSAGE INDIQUANT LE DEBUT DU TRANSFERT DE DEPLACEMENT*/
    memset(buffer, 0, sizeof(buffer));
	recv(socket_to_serv,buffer,512, 0);

    if(strncmp("DEB_DEP", buffer, 7)){
        memset(buffer, 0, sizeof(buffer));
        recv(socket_to_serv,buffer,512, 0);

        while(!strncmp("FIN_DEP", buffer, 7)){
             /*!TANT QU ON A PAS DEPLACE TOUS LES CANARDS A DEPLACER ON PREND LES DONNEES ET ON LES DEPLACE*/
            fread(i, sizeof(int), 1, buffer);
            fread(j, sizeof(int), 1, buffer);
            fread(k, sizeof(int), 1, buffer);
            fread(direction, sizeof(int), 1, buffer);

            deplacer_canard(i, j, k, direction);
        }

    }

}




