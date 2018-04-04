#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Fonction_SDL.h"

#define LARGEUR_WIN 640
#define HAUTEUR_WIN 480
#define N 10

int main(int argc, char** argv)
{
	//char page[N]={"main","play","credit"};
	//char page_act;
	
    	//Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
   	SDL_Surface *titre=NULL, *image=NULL, *bouton=NULL, *boutonP=NULL, *texteC=NULL;
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


	if( (police = TTF_OpenFont("04B_30__.TTF", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
	titre = TTF_RenderUTF8_Blended(police, "EraDUCKation!!", couleurNoire);
	if(!titre){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *titre_tex = SDL_CreateTextureFromSurface(renderer, titre); 
	if(!titre_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(titre); /* on a la texture, plus besoin du texte */
	
	/* Position ou sera mis le texte dans la fenêtre*/ 
    	txtDestRect.x = txtDestRect.y = 10;
	SDL_QueryTexture(titre_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

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
	
	////////////// Chargement texte credit/////////////////////
	
	char texte[500]="";

	sprintf(texte,"Jeu réalisé par:\n - TOUZE Maxime\n - PHILIPPE Marion\n - VAIDIE Camille\n - MARCHAND Killian\n\n\n Licence 2 Inforamtique \n\n\n \u24B8 DUCKCorporation");

	texteC = TTF_RenderUTF8_Blended(police, texte, couleurNoire);
	if(!texteC){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texteC_tex = SDL_CreateTextureFromSurface(renderer, texteC); 
	if(!texteC_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texteC); 
	
	
	////////////////////////////////////////////////////////////


	if( pWindow )
	{
		//page_act=page[0]; //page principale

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
				txtDestRect.x = LARGEUR_WIN/2.2;
				txtDestRect.y = HAUTEUR_WIN/5;
							
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, titre_tex, NULL, &txtDestRect);
                                SDL_RenderPresent(renderer);
								
                                /* Ajout Image de Fond */
                                imgDestRect.x = 0;
				imgDestRect.y = 0;
				SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                
								
							break;
						}
					break;
						case SDL_KEYDOWN:
               						 switch(e.key.keysym.sym)
               						 {
             						       
								case SDLK_SPACE:	
								////PLAY////
                 							//page_act=page[1];
                 						///////ACCES A ECRAN CHOIX NB JOUEUR////
									//choix_nb_joueur();
                 						break;
								
								case SDLK_c:
								////CREDIT////
									//page_act=page[2];
                 						///////ACCES A ECRAN CREDIT////
									credit( image_tex, texteC_tex, renderer, txtDestRect, imgDestRect );
                 						break;
					
								case SDLK_q:
								////QUIT////
									SDL_Quit();
									return 0;
                 						break;
						}break;
			
				
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