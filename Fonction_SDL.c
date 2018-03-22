#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define LARGEUR_WIN 640
#define HAUTEUR_WIN 480



/////////FONCTION POUR MENU/////
int choix_difficulte(SDL_Renderer *renderer){
	//IF POUR CHAQUE COORDONNE DE BOUTON CHOIX DIFFICULTE//
	//DEMARRAGE PARTIE//
	
	SDL_RenderClear(renderer);
	//APPEL DE CHOIX_DIFFICULTE//
	
}

int choix_nb_joueur(SDL_Renderer *renderer){
	//IF POUR CHAQUE COORDONNE DE BOUTON CHOIX JOUEUR//
		
	SDL_RenderClear(renderer);
	//APPEL FONCTION POUR LANCER JEU//
}

int credit(SDL_Texture *image_tex,SDL_Texture *texteC_tex,SDL_Renderer *renderer,SDL_Rect txtDestRect, SDL_Rect imgDestRect){
	//FOND BLANC//
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
	
	SDL_RenderClear(renderer);
	txtDestRect.x = 10;
	txtDestRect.y = 10;
	
	txtDestRect.h = 25;
	txtDestRect.w = 1000;	
		
	
	SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
	
	//AFFICHAGE REMERCIEMENT ET NOMS PERSONNES DU GROUPE//
       	/* Ajout du texte en noir */
     	SDL_RenderCopy(renderer, texteC_tex, NULL, &txtDestRect);
     	
     	SDL_RenderPresent(renderer);
}
