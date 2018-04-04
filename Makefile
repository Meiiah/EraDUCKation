CC=gcc
FLAGS=-Wall -g

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

OBJ= Eraduckation.o Fonction_SDL.o fonction_multi_reseau.o deplacer_multi.o connection.o client_reseau.o main_reseau.o multijoueur_reseau.o outils_reseau.o canard.o deplacer.o event.o matrice.o outils.o jeu_solo.o joueur.o labyrinthe.o jeu.o nourriture.o piege.o reproduction.o sauvegarde.o multijoueur.o

PROG=era


${PROG}: ${OBJ}
	${CC} ${OBJ} -o ${PROG} ${FLAGS} ${LIBS} ${INCLUDES}

Eraduckation.o: Eraduckation.c
	${CC} -c Eraduckation.c ${FLAGS} ${LIBS} ${INCLUDES}

Fonction_SDL.o: Fonction_SDL.c
	${CC} -c Fonction_SDL.c ${FLAGS} ${LIBS} ${INCLUDES}

canard.o: canard.c 
	${CC} -c canard.c ${FLAGS}

deplacer.o: deplacer.c 
	${CC} -c deplacer.c ${FLAGS}

event.o: event.c 
	${CC} -c event.c ${FLAGS}
	
outils.o: outils.c 
	${CC} -c outils.c ${FLAGS}

jeu_solo.o: jeu_solo.c 
	${CC} -c jeu_solo.c ${FLAGS}

joueur.o: joueur.c 
	${CC} -c joueur.c ${FLAGS}

labyrinthe.o: labyrinthe.c 
	${CC} -c labyrinthe.c ${FLAGS}

jeu.o: jeu.c 
	${CC} -c jeu.c ${FLAGS}

nourriture.o: nourriture.c 
	${CC} -c nourriture.c ${FLAGS}

piege.o: piege.c 
	${CC} -c piege.c ${FLAGS}

reproduction.o: reproduction.c 
	${CC} -c reproduction.c ${FLAGS}

sauvegarde.o: sauvegarde.c 
	${CC} -c sauvegarde.c ${FLAGS}

matrice.o: matrice.c
	${CC} -c matrice.c ${FLAGS}

fonction_multi_reseau.o: fonction_multi_reseau.c
	${CC} -c fonction_multi_reseau.c ${FLAGS}

multijoueur.o: multijoueur.c 
	${CC} -c multijoueur.c ${FLAGS}

connection.o: connection.c 
	${CC} -c connection.c ${FLAGS}

deplacer_multi.o: deplacer_multi.c 
	${CC} -c deplacer_multi.c ${FLAGS}

main_reseau.o: main_reseau.c 
	${CC} -c main_reseau.c ${FLAGS}

outils_reseau.o: outils_reseau.c 
	${CC} -c outils_reseau.c ${FLAGS}
	
client_reseau.o: client_reseau.c 
	${CC} -c client_reseau.c ${FLAGS}


clean:
	rm -f *.o
	rm -f Eraduckation	
	rm -f Fonction_SDL
	rm -f canard
	rm -f deplacer
	rm -f deplacer_multi
	rm -f event
	rm -f jeu_solo
	rm -f joueur
	rm -f labyrinthe
	rm -f jeu
	rm -f matrice
	rm -f outils
	rm -f nourriture
	rm -f piege
	rm -f reproduction
	rm -f sauvegarde
	rm -f fonction_multi_reseau
	rm -f multijoueur
	rm -f client_reseau
	rm -f outils_reseau
	rm -f multijoueur_reseau
	rm -f deplacer_multi
	rm -f connection
	rm -f ${PROG}

