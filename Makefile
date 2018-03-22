CC=gcc
<<<<<<< HEAD
OBJ=canard.o deplacer.o event.o matrice.o outils.o jeu_solo.o joueur.o labyrinthe.o main.o nourriture.o piege.o reproduction.o sauvegarde.o 

PROG=era

=======
OBJ=canard.o deplacer.o event.o matrice.o outils.o jeu_solo.o joueur.o labyrinthe.o main.o nourriture.o piege.o reproduction.o sauvegarde.o multijoueur.o

PROG=era


>>>>>>> 6ea772379796f68d37bc5ff156b489532c49e43a

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

fonction_multi_reseau.o: fonction_multi_reseau.c
	${CC} -c fonction_multi_reseau.c



=======
fonction_multi_reseau.o: fonction_multi_reseau.c
	${CC} -c fonction_multi_reseau.c

labyrinthe.o: multijoueur.c 
	${CC} -c multijoueur.c

>>>>>>> 6ea772379796f68d37bc5ff156b489532c49e43a
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
	rm -f fonction_multi_reseau
	
	rm -f ${PROG}

=======
	rm -f fonction_multi_reseau
	rm -f multijoueur
	rm -f ${PROG}
>>>>>>> 6ea772379796f68d37bc5ff156b489532c49e43a
