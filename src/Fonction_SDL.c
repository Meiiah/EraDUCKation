#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define LARGEUR_WIN 640
#define HAUTEUR_WIN 480


/**
* \file Fonction_SDL.c
* \brief Programme comprennant la génération d'un labyrinthe
* \author Marchand Killian 
* \version 2.0
* \date 28 Mars 2018
*/

/////////FONCTION POUR MENU/////

/** \fn int credit(SDL_Texture ,SDL_Texture , SDL_Texture, SDL_Texture,SDL_Renderer,SDL_Rect, SDL_Rect)*/
/** Affichage du texte, de l'image de fond du menu Credit*/
void credit(SDL_Texture *image_tex,SDL_Texture *texteC_tex, SDL_Texture *texteC2_tex, SDL_Texture *texteC3_tex,SDL_Renderer *renderer,SDL_Rect txtDestRect, SDL_Rect imgDestRect){
	//FOND BLANC//
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
	
	SDL_RenderClear(renderer);
	imgDestRect.x = 0;
	imgDestRect.y =	0;
	
	SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	
	SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
	
	//AFFICHAGE REMERCIEMENT ET NOMS PERSONNES DU GROUPE//
       	/* Ajout du texte en noir */
       	txtDestRect.x = 10;
	txtDestRect.y = 10;
	
	txtDestRect.h = 25;
	txtDestRect.w = 100;
	SDL_RenderCopy(renderer, texteC_tex, NULL, &txtDestRect);
     	
     	txtDestRect.x = 10;
	txtDestRect.y = 100;
	
	txtDestRect.h = 20;
	txtDestRect.w = 500;
	
     	SDL_RenderCopy(renderer, texteC2_tex, NULL, &txtDestRect);
     	
     	txtDestRect.x = 10;
	txtDestRect.y = 150;
	
	txtDestRect.h = 20;
	txtDestRect.w = 100;
	
     	SDL_RenderCopy(renderer, texteC3_tex, NULL, &txtDestRect);
     	
     	SDL_RenderPresent(renderer);
}