CC=gcc
OBJ=canard.o deplacer.o event.o matrice.o outils.o jeu_solo.o joueur.o labyrinthe.o main.o nourriture.o piege.o reproduction.o sauvegarde.o GestionDeLaBarreDeVie.o 

PROG=era

SDL_DIR=${HOME}/Documents/cours/l2-projets/tuto_SDL/SDL2-2.0.7/bin
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2
INCS=-I${SDL_INC_DIR}


${PROG}: ${OBJ}
	${CC} ${OBJ} -o ${PROG}

canard.o: canard.c 
	${CC} -c canard.c

deplacer.o: deplacer.c 
	${CC} -c deplacer.c

event.o: event.c 
	${CC} -c event.c
	
outils.o: outils.c 
	${CC} -c outils.c

jeu_solo.o: jeu_solo.c 
	${CC} -c jeu_solo.c

joueur.o: joueur.c 
	${CC} -c joueur.c

labyrinthe.o: labyrinthe.c 
	${CC} -c labyrinthe.c

main.o: main.c 
	${CC} -c main.c

nourriture.o: nourriture.c 
	${CC} -c nourriture.c

piege.o: piege.c 
	${CC} -c piege.c

reproduction.o: reproduction.c 
	${CC} -c reproduction.c

sauvegarde.o: sauvegarde.c 
	${CC} -c sauvegarde.c

matrice.o: matrice.c
	${CC} -c matrice.c

<<<<<<< HEAD
GestionDeLaBarreDeVie.o: GestionDeLaBarreDeVie.c
	${CC} -c GestionDeLaBarreDeVie.c
=======
fonction_multi_reseau.o: fonction_multi_reseau.c
	${CC} -c fonction_multi_reseau.c

GestionDeLaBareDeVie.o: GestionDeLaBareDeVie.c
	${CC} -c GestionDeLaBareDeVie.c
	
all: sdl_text
sdl_text: sdl_test.c
	${CC} -o ${PROG} sdl_test.c ${LIBS} ${INCS}

>>>>>>> 0db0b1139bbe985b0fde54ea62cf9508e99e0f96
clean:
	rm -f *.o
	rm -f canard
	rm -f deplacer
	rm -f deplacer_multi
	rm -f event
	rm -f jeu_solo
	rm -f joueur
	rm -f labyrinthe
	rm -f main
	rm -f matrice
	rm -f outils
	rm -f nourriture
	rm -f piege
	rm -f reproduction
	rm -f sauvegarde
<<<<<<< HEAD
	rm -f GestionDeLaBareDeVie
=======
	rm -f fonction_multi_reseau
	rm -f GestionDeLaBareDeVie
	rm -f ${PROG}
>>>>>>> 0db0b1139bbe985b0fde54ea62cf9508e99e0f96
