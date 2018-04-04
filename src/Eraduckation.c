#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Fonction_SDL.h"
#include "jeu.h"


#define LARGEUR_WIN 640
#define HAUTEUR_WIN 480
#define N 100

/**
* \file Eraduckation.c
* \brief Programme comprennant le MENU SDL
* \author Marchand Killian 
* \version 3.0
* \date 28 Mars 2018
*/


/** \fn int main(int, char**)*/
/** Création et affichage du MENU SDL*/
int main(int argc, char** argv)
{
	
    	//Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
   	SDL_Surface *texteC=NULL, *texteC2=NULL, *texteC3=NULL, *titre=NULL, *image=NULL, *bouton=NULL, *boutonP=NULL, *boutonC=NULL, *boutonQ=NULL;
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


	if( (police = TTF_OpenFont("FrescoStamp.ttf", 20)) == NULL){
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
	rwop=SDL_RWFromFile("Credit.png", "rb");
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
	rwop=SDL_RWFromFile("Quit.png", "rb");
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
	
	////////////// Chargement texte credit/////////////////////

	
	texteC = TTF_RenderUTF8_Blended(police,"Jeu realise par:", couleurNoire);
	if(!texteC){
		fprintf(stderr, "Erreur à la création du texteC : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texteC_tex = SDL_CreateTextureFromSurface(renderer, texteC); 
	if(!texteC_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texteC);
	
	////////////// Chargement texte credit2/////////////////////

	
	texteC2 = TTF_RenderUTF8_Blended(police,"TOUZE Maxime, PHILIPPE Marion, VAIDIE Camille, MARCHAND Killian", couleurNoire);
	if(!texteC2){
		fprintf(stderr, "Erreur à la création du texteC2 : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texteC2_tex = SDL_CreateTextureFromSurface(renderer, texteC2); 
	if(!texteC2_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte  : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texteC2);
	
	
	////////////// Chargement texte credit3/////////////////////

	texteC3 = TTF_RenderUTF8_Blended(police, "Licence 2 Inforamtique", couleurNoire);
	if(!texteC3){
		fprintf(stderr, "Erreur à la création du texteC33 : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texteC3_tex = SDL_CreateTextureFromSurface(renderer, texteC3); 
	if(!texteC3_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texteC3);
	
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

				txtDestRect.x = LARGEUR_WIN/2.2;
				txtDestRect.y = HAUTEUR_WIN/8;
								
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, titre_tex, NULL, &txtDestRect);
                                SDL_RenderPresent(renderer);
								
                                /* Ajout Image de Fond */
                                imgDestRect.x = 0;
				imgDestRect.y = 0;
				SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
				
				/* Ajout Bouton Play */
				imgDestRect.x = LARGEUR_WIN/4.1;
				imgDestRect.y = HAUTEUR_WIN/4;
				SDL_QueryTexture(boutonP_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonP_tex, NULL, &imgDestRect);
								
				/* Ajout Bouton Credit */
				imgDestRect.x = LARGEUR_WIN/1.4;
				imgDestRect.y = HAUTEUR_WIN/4;
				SDL_QueryTexture(boutonC_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonC_tex, NULL, &imgDestRect);
				
				/* Ajout Bouton Quit */
				imgDestRect.x = LARGEUR_WIN/2.4;
				imgDestRect.y = HAUTEUR_WIN/1.3;
				SDL_QueryTexture(boutonQ_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
				SDL_RenderCopy(renderer, boutonQ_tex, NULL, &imgDestRect);
								
                                /* On fait le rendu ! */
                                SDL_RenderPresent(renderer);
								
							break;
						}
					break;
					///////////Gestion evenement clique souris////////////////////////
					////Recuperer LARGEUR_WIN HAUTEUR_WIN de chaque image/////
					case SDL_MOUSEBUTTONUP:
						////PLAY////
                 				if (e.button.y > (HAUTEUR_WIN/4) && e.button.y <= (HAUTEUR_WIN/4)+72 && e.button.x >(LARGEUR_WIN/4.1) && e.button.x <= (LARGEUR_WIN/4.1)+166 ){// si clic sur boutton
                 					///////ACCES A ECRAN CHOIX NB JOUEUR////
							jeu();
                 				}
						////CREDIT////
						if (e.button.y > (HAUTEUR_WIN/4) && e.button.y <= (HAUTEUR_WIN/4)+72 && e.button.x > (LARGEUR_WIN/1.4) && e.button.x <= (LARGEUR_WIN/1.4)+166 ){// si clic sur boutton
                 					///////ACCES A ECRAN CREDIT////
											/* Ajout Bouton Quit */
							imgDestRect.x = LARGEUR_WIN/2.4;
							imgDestRect.y = HAUTEUR_WIN/1.3;
							SDL_QueryTexture(boutonQ_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							SDL_RenderCopy(renderer, boutonQ_tex, NULL, &imgDestRect);
                 				
							
							credit( image_tex, texteC_tex, texteC2_tex, texteC3_tex, renderer, txtDestRect, imgDestRect);
							}
						////QUIT////
						if (e.button.y > (HAUTEUR_WIN/1.3) && e.button.y <= (HAUTEUR_WIN/1.3)+72 && e.button.x > (LARGEUR_WIN/2.2) && e.button.x <= (LARGEUR_WIN/2.4)+166 ){// si clic sur boutton
                 					//DESTRUCTION DE LA FENETRE POUR FERMETURE//
							SDL_Quit();
							return 0;
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