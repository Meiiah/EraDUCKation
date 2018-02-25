canard_t canard_vide(void);

int voit_nourriture(case_t ** matrice,int i,int j,int k);

int voit_accouplement(case_t ** matrice,int nourriture_accouplement,int i,int j,int k);

void deplacer_canard(case_t ** matrice,int i, int j, int k, int direction);

void deplacer(case_t ** matrice,int nourriture_accouplement);