#ifndef __JOUEUR_H__
#define __JOUEUR_H__

char *mauv_evts[nb_event]={
	"Lance un tsunami sur le labyrinthe",
	"Lance une tempete sur le labyrinthe",
	"Famine : R�duit la nourriture g�n�r�e",
	"R�duit la reproduction des canards",
	"Appartion de 0 � 5 pr�dateurs de canards"
};
char *bon_evts[nb_event]={
	"Accel�re la reproduction des canards",
	"G�n�ration de nourriture augment�e",
	"Rien changer",
	"Lib�re entre 0 et 5 canards",
	"Rend un canard invincible"
	};

void ajout_score(int,joueur_t*, joueur_t*);
void caract_joueur(joueur_t*);
void tab_event_mauvais(int,int,int);
void tab_event_bon(int,int,int);
void choix_mechant(caract_mat_t * cmat,joueur_t joueur, joueur_t joueur2, int * nourriture_genere, int * nourriture_accouplement,int);
void choix_bon(caract_mat_t *,joueur_t , joueur_t , int* , int* ,int);
void choix_joueur(caract_mat_t *,joueur_t , joueur_t , int*, int*,int );

#endif
