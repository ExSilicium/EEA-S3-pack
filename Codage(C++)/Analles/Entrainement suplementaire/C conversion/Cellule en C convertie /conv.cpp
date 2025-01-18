#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int* avant;  // Pointeur vers un tableau de 3 entiers
   int resultat;
} regle;

regle init(int* a, int r) {
    regle R;
    R.avant = (int*)malloc(3 * sizeof(int));
    for(int i = 0; i < 3; i++) {
        R.avant[i] = a[i];
    }
    R.resultat = r;
    return R;
}

regle* toutesRegles() {
    regle* T = (regle*)malloc(8 * sizeof(regle));
    int regles[8][3] = {{0,0,0}, {0,0,1}, {0,1,0}, {0,1,1},
                        {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1}};
    int resultats[8] = {0, 1, 1, 1, 1, 1, 1, 0};

    for(int i = 0; i < 8; i++) {
        T[i] = init(regles[i], resultats[i]);
    }
    return T;
}

void affLigne(int* m, int nb) {
    for(int k = 0; k < nb; k++) {
        printf(m[k] == 0 ? " " : "*");
    }
    printf("\n");
}

int appliquerRegles(int* m, int position, regle* regles, int nb_regles) {
    for(int r = 0; r < nb_regles; r++) {
        if (m[position-1] == regles[r].avant[0] &&
            m[position] == regles[r].avant[1] &&
            m[position+1] == regles[r].avant[2]) {
            return regles[r].resultat;
        }
    }
    return -1;
}

int* calcLigne(int* m, int nb, regle* r) {
    int* n = (int*)malloc(nb * sizeof(int));

    for(int k = 1; k < nb - 1; k++) {
        n[k] = appliquerRegles(m, k, r, 8);
    }

    n[0] = 0;
    n[nb-1] = 0;

    return n;
}

int main() {
    regle* regles = toutesRegles();
    int* ligne = (int*)malloc(80 * sizeof(int));
    int nb = 80;

    // Initialisation de la ligne
    for(int k = 0; k < nb; k++) {
        ligne[k] = 0;
    }
    ligne[40] = 1;

    // Calcul et affichage
    for(int l = 0; l < 32; l++) {
        affLigne(ligne, nb);
        int* nouvelle_ligne = calcLigne(ligne, nb, regles);
        free(ligne);  // Libère l'ancienne ligne
        ligne = nouvelle_ligne;
    }

    // Libération finale de la mémoire
    free(ligne);
    for(int i = 0; i < 8; i++) {
        free(regles[i].avant);
    }
    free(regles);

    return 0;
}
