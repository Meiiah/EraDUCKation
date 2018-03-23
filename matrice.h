#ifndef __MATRICE_H__
#define __MATRICE_H__

/*definition de la matrice */
typedef struct{
	case_t ** matrice;
	int taille_mat_x;
	int taille_mat_y;
}caract_mat_t;

int est_dans_matrice(caract_mat_t *cmat,int x, int y);

caract_mat_t * creation_matrice(int x, int y);

void init_matrice(caract_mat_t * cmat);

#endif // __MATRICE_H__
