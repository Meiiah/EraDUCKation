

typedef enum clan_t{ bon, mechant };

typedef struct joueur_s{
    clan_t clan;
    char nom [20];
    void (*choix) (void);
}joueur_t

/*================================================*/

joueur_t joueur_gentil(void){ // initialise un joueur en joueur gentil
    joueur_t mem;
    mem.clan = bon;
    mem.choix = choix_bon;
    return mem ;
}

joueur_t joueur_mechant(void){ //initialise un joueur en tant que mechant
    joueur_t mem;
    mem.clan = mechant;
    mem.choix = choix_mechant;
    return mem ;
}

/*=======================================================*/


void tour_multijoueur(joueur_t tab[]){

}

/*===============================================*/

  int qui_commence(void){
       printf("Si vous voulez que ce soit le joueur gentil qui commence, tapez 0, pour le mechant,         tapez 1, et si vous voulez que ce soit aleatoire tapez 2\n");
       scanf("%i”,&tampon);
       while(tampon <0 || tampon >2){
            printf(" \n entree invalide veuillez de nouveau sesir qui va commencer \n");
            scanf("%i",&tampon);
        }
        if(tampon ==2) tampon = rand()%2;
        return tampon;
}

/*============================================================*/

void init_tab_joueurs(joueur_t tab[], int tampon){
    tab[tampon]= joueur_gentil();    //c est de la logique
    tab[tampon +1 %2] = joueur_mechant();

   //demander les noms

    demander_nom(tab[tampon].nom, tab[tampon+1 %2].nom);

/*============================================================*/

void main_multijoueur(void){
    //variables :
    joueur_t tab [2];
    int tampon;
    //maintenant on initialise l ordre de jeu
    tampon = qui_commence();
    init_tab_joueurs(tab, tampon);

    /** Tant que les canards sont pas tous morts on fait les tours

    a chaque tour on fait deplacement, choix, on verifie les cond d arret,, et on recommence */


}
