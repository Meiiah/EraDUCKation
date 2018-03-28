CC=gcc
FLAGS=-Wall -g
OBJ=  canard.o deplacer.o event.o matrice.o outils.o jeu_solo.o joueur.o labyrinthe.o main.o nourriture.o piege.o reproduction.o sauvegarde.o multijoueur.o

PROG=era


${PROG}: ${OBJ}
	${CC} ${OBJ} -o ${PROG} ${FLAGS}

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

main.o: main.c 
	${CC} -c main.c ${FLAGS}

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
	rm -f fonction_multi_reseau
	rm -f multijoueur
	rm -f ${PROG}

