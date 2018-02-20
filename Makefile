CC=gcc
PROG=canard.o deplacer.o deplacer_multi.o event.o init_matrice.o jeu_solo.c joueur.o labyrinthe.o main.o multijoueur.o multijoueur_reseau.o nourriture.o piege.o reproduction.o sauvegarde.o


era: ${PROG}.o 
	${CC} ${PROG}.o -o ${PROG}


canard.o: canard.c 
	${CC} -c canard.c

deplacer.o: deplacer.c 
	${CC} -c deplacer.c

deplacer_multi.o: deplacer_multi.c 
	${CC} -c deplacer_multi.c

event.o: $event.c 
	${CC} -c event.c

init_matrice.o: init_matrice.c 
	${CC} -c init_matrice.c

jeu_solo.o: jeu_solo.c 
	${CC} -c jeu_solo.c

joueur.o: joueur.c 
	${CC} -c joueur.c

labyrinthe.o: labyrinthe.c 
	${CC} -c labyrinthe.c

main.o: main.c 
	${CC} -c main.c

multijoueur.o: multijoueur.c 
	${CC} -c multijoueur.c

multijoueur_reseau.o: multijoueur_reseau.c 
	${CC} -c multijoueur_reseau.c

nourriture.o: nourriture.c 
	${CC} -c nourriture.c

piege.o: piege.c 
	${CC} -c piege.c

reproduction.o: reproduction.c 
	${CC} -c reproduction.c

sauvegarde.o: sauvegarde.c 
	${CC} -c sauvegarde.c
clean:
	rm -f *.o
	rm -f canard
	rm -f deplacer
	rm -f deplacer_multi
	rm -f event
	rm -f init_matrice
	rm -f jeu_solo
	rm -f joueur
	rm -f labyrinthe
	rm -f main
	rm -f multijoueur
	rm -f multijoueur_reseau
	rm -f nourriture
	rm -f piege
	rm -f reproduction
	rm -f sauvegarde