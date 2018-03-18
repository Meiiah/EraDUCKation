#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


#define LARGEUR_WIN 640
#define HAUTEUR_WIN 480
#define N 100

/////////FONCTION POUR MENU/////
int choix_nb_joueur(){
	//IF POUR CHAQUE COORDONNE DE BOUTON CHOIX JOUEUR//
	//APPEL DE CHOIX_DIFFICULTE//
	
}

int choix_difficulte(){
	//IF POUR CHAQUE COORDONNE DE BOUTON CHOIX DIFFICULTE//
	//DEMARRAGE PARTIE//
}

int credit(){
	//AFFICHAGE REMERCIEMENT ET NOMS PERSONNES DU GROUPE//
}

int quit(){
	//DESTRUCTION DE LA FENETRE POUR FERMETURE//
}


///////////////////////////////
/*
typedef struct text_s{
	SDL_Texture text;
	int imgDestRect.x;
	int imgDestRect.y;
}text_t
*//*

//Vérification de la presence de la texture dans le tableau
int Verif_texture(text_t tab, SDL_Texture){
	int i;
	for(i=0; i<N; i++){
		if(SDL_Texture == tab[i].text) return 1;
	return 0;
}
*/
int main(int argc, char** argv)
{

	//tableau regroupant chaque textures
	//text_t *tab = malloc(sizeof(text_t));
	
    	//Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
   	SDL_Surface *texte=NULL, *image=NULL, *bouton=NULL, *boutonP=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect;

	// Le pointeur vers notre police
	TTF_Font *police = NULL;
	// Une variable de couleur noire
	SDL_Color couleurNoire = {0, 0, 0};

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    } 

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}


	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("EraDUCKation",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  LARGEUR_WIN,
												  HAUTEUR_WIN,
												  SDL_WINDOW_SHOWN);

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}


	if( (police = TTF_OpenFont("04B_30__.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
	texte = TTF_RenderUTF8_Blended(police, "EraDUCKation!!", couleurNoire);
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte); 
	if(!texte_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	/* Position ou sera mis le texte dans la fenêtre */
    	txtDestRect.x = txtDestRect.y = 10;
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	//////////Chargement image de fond////////////////////////////
	
	SDL_RWops *rwop=SDL_RWFromFile("12651.png", "rb");
	image=IMG_LoadPNG_RW(rwop);
	if(!image) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *image_tex = SDL_CreateTextureFromSurface(renderer, image); 
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Option/////////////////////
	rwop=SDL_RWFromFile("option.png", "rb");
	boutonO=IMG_LoadPNG_RW(rwop);
	if(!boutonO) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *boutonO_tex = SDL_CreateTextureFromSurface(renderer, boutonO); 
	if(!boutonO_tex){
		fprintf(stderr, "Erreur à la création du rendu du bouton : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(boutonO); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Play/////////////////////
	rwop=SDL_RWFromFile("Play.png", "rb");
	boutonP=IMG_LoadPNG_RW(rwop);
	if(!boutonP) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *boutonP_tex = SDL_CreateTextureFromSurface(renderer, boutonP); 
	if(!boutonP_tex){
		fprintf(stderr, "Erreur à la création du rendu du boutonP : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(bouton); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Credit/////////////////////
	rwop=SDL_RWFromFile("credit.png", "rb");
	boutonC=IMG_LoadPNG_RW(rwop);
	if(!boutonC) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *boutonC_tex = SDL_CreateTextureFromSurface(renderer, boutonC); 
	if(!boutonC_tex){
		fprintf(stderr, "Erreur à la création du rendu du boutonC : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(boutonC); /* on a la texture, plus besoin de l'image */
	
	////////////// Chargement Image Bouton Quit/////////////////////
	rwop=SDL_RWFromFile("quit.png", "rb");
	boutonQ=IMG_LoadPNG_RW(rwop);
	if(!boutonQ) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *boutonQ_tex = SDL_CreateTextureFromSurface(renderer, boutonQ); 
	if(!boutonQ_tex){
		fprintf(stderr, "Erreur à la création du rendu du bouton : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(boutonQ); /* on a la texture, plus besoin de l'image */
	
	////////////////////////////////////////////////////////////


	if( pWindow )
	{
		int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
				/* Le fond de la fenêtre sera blanc */
                                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderClear(renderer);
                                
                                /* Ajout du texte en noir */
				txtDestRect.x = LARGEUR/2.2;
				txtDestRect.y = HAUTEUR/5;
								
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                SDL_RenderPresent(renderer);
								
                                /* Ajout Image de Fond */
                                imgDestRect.x = 0;
				imgDestRect.y = 0;
				SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* Ajout Bouton Option */
				imgDestRect.x = LARGEUR/1.3;
				imgDestRect.y = HAUTEUR/1.5;
				SDL_QueryTexture(boutonO_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonO_tex, NULL, &imgDestRect);
				
				/* Ajout Bouton Play */
				imgDestRect.x = LARGEUR/4;
				imgDestRect.y = HAUTEUR/2;
				SDL_QueryTexture(boutonP_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonP_tex, NULL, &imgDestRect);
								
				/* Ajout Bouton Credit */
				imgDestRect.x = LARGEUR/1.3;
				imgDestRect.y = HAUTEUR/2;
				SDL_QueryTexture(boutonC_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonC_tex, NULL, &imgDestRect);
				
				/* Ajout Bouton Quit */
				imgDestRect.x = LARGEUR/2.2;
				imgDestRect.y = HAUTEUR/5;
				SDL_QueryTexture(boutonQ_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonQ_tex, NULL, &imgDestRect);
								
                                /* On fait le rendu ! */
                                SDL_RenderPresent(renderer);
								
							break;
						}
					break;
					///////////Gestion evenement clique souris////////////////////////
					////Recuperer largeur hauteur de chaque image/////
					case SDL_MOUSEBUTTONUP:
						////OPTION////
						if (e.button.y > (HAUTEUR/1.5) && e.button.y <= (HAUTEUR/1.5)+156 && e.button.x > (LARGEUR/1.3) && e.button.x <= (LARGEUR/1.3)+156 ){// si clic sur boutton
                 					/////ACCES AUX OPTIONS////
							txtDestRect.x = 10;
							txtDestRect.y = 50;
                 					/* Ajout du texte en noir */
                                			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                			SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                			SDL_RenderPresent(renderer);
                 				}
						////PLAY////
                 				if (e.button.y > (HAUTEUR/2) && e.button.y <= (HAUTEUR/2)+72 && e.button.x >(LARGEUR/4) && e.button.x <= (LARGEUR/4)+166 ){// si clic sur boutton
                 					///////ACCES A ECRAN CHOIX NB JOUEUR////
							txtDestRect.x = 50;
							txtDestRect.y = 50;
                 					/* Ajout du texte en noir */
                                			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                			SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                			SDL_RenderPresent(renderer);
                 				}
						////CREDIT////
						if (e.button.y > (HAUTEUR/2) && e.button.y <= (HAUTEUR/2)+72 && e.button.x > (LARGEUR/1.3) && e.button.x <= (LARGEUR/1.3)+166 ){// si clic sur boutton
                 					///////ACCES A ECRAN CREDIT////
							txtDestRect.x = 50;
							txtDestRect.y = 50;
                 					/* Ajout du texte en noir */
                                			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                			SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                			SDL_RenderPresent(renderer);
                 				}
						////QUIT////
						if (e.button.y > (HAUTEUR/5) && e.button.y <= (HAUTEUR/5)+72 && e.button.x > (LARGEUR/2.2) && e.button.x <= (LARGEUR/2.2)+166 ){// si clic sur boutton
                 					///////DESTRUCTION FENETRE/FERMETURE////
							txtDestRect.x = 50;
							txtDestRect.y = 50;
                 					/* Ajout du texte en noir */
                                			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                			SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
                                			SDL_RenderPresent(renderer);
                 				} 
                 			break;
				
				} 
			} 
		}
	} else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
	TTF_Quit();
    SDL_Quit();

    return 0;
}

