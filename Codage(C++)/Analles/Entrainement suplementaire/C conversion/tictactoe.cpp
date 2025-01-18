#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Partie du code qui gère la grille
int** creerGrille(unsigned int N) {
    int** G;
    G = (int**)malloc(N * sizeof(int*));
    for (unsigned int k = 0; k < N; k++) {
        G[k] = (int*)malloc(N * sizeof(int));
    }
    return G;
}

void effacerGrille(int** G, int size) {
    for (unsigned int y = 0; y < size; y++) {
        for (unsigned int x = 0; x < size; x++) {
            G[y][x] = 0;
        }
    }
}

int estAligne(int joueur, int x0, int y0, int nb, int dx, int dy, int** G) {
    for (unsigned int k = 0; k < nb; k++) {
        if (G[y0 + k * dy][x0 + k * dx] != joueur) {
            return 0;
        }
    }
    return 1;
}

int grillePleine(int** G, int size) {
    for (unsigned int y = 0; y < size; y++) {
        for (unsigned int x = 0; x < size; x++) {
            if (G[y][x] == 0) return 0;
        }
    }
    return 1;
}

// Partie du code qui gère le jeu
void afficherGrille(int** G, int size) {
    printf("\n");
    for (unsigned int y = 0; y < size; y++) {
        for (unsigned int x = 0; x < size; x++) {
            if (G[y][x] == 0) {
                printf(" ");
            } else if (G[y][x] == 1) {
                printf("X");
            } else if (G[y][x] == 2) {
                printf("O");
            }
            if (x != size - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (y != size - 1) {
            for (unsigned int x = 0; x < size * 3+2; x++) {
                printf("-");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int placePion(int x, int y, int joueur, int** G) {
    if (G[y][x] == 0) {
        G[y][x] = joueur;
        return 1;
    } else {
        return 0;
    }
}

int aGagne(int joueur, int** G) {
    // Test diagonales, puis lignes, puis colonnes
    int diags = estAligne(joueur, 0, 0, 3, 1, 1, G) == 1 || estAligne(joueur, 2, 0, 3, -1, 1, G) == 1;
    int lines = 0;
    int cols = 0;
    for (unsigned int i = 0; i < 3; i++) {
        lines = lines || estAligne(joueur, i, 0, 3, 0, 1, G);
        cols = cols || estAligne(joueur, 0, i, 3, 1, 0, G);
    }
    if (diags || lines || cols) {
        return 1;
    }
    return 0;
}

int partieTerminee(int** G, int size) {
    if (aGagne(1, G) == 1) {
        printf("\nJoueur 1 a gagné !\n");
        return 1;
    }
    if (aGagne(2, G) == 1) {
        printf("\nJoueur 2 a gagné !\n");
        return 1;
    }
    if (grillePleine(G, size) == 1) {
        printf("\nAucun joueur n'a gagné.\n");
        return 1;
    }
    return 0;
}

// Une IA idiote qui joue au hasard
void joueurIA(int joueur, int** G, int size) {
    int* X;
    int* Y;
    X = (int*)malloc(size * size * sizeof(int));
    Y = (int*)malloc(size * size * sizeof(int));
    int k = 0;
    for (unsigned int y = 0; y < size; y++) {
        for (unsigned int x = 0; x < size; x++) {
            if (G[y][x] == 0) {
                X[k] = x;
                Y[k] = y;
                k++;
            }
        }
    }
    int IA = rand() % k;
    G[Y[IA]][X[IA]] = joueur;
    free(X);
    free(Y);
}

// Programme principal
int main() {
    srand(time(NULL));
    int size = 3;

    int** grille = creerGrille(size);
    effacerGrille(grille, size);

    int x, y, joueur = 1;
    int fini = 0;
    while (fini == 0) {
        afficherGrille(grille, size);
        joueur = 1;
        printf(" # C'est à Joueur %d\n", joueur);
        int place = 0;
        while (place != 1) {
            printf("Où jouez-vous ? (x, y) \nx : ");
            scanf("%d", &x);
            printf("y : ");
            scanf("%d", &y);
            if (x < 0 || x >= size || y < 0 || y >= size) {
                printf("Coordonnées invalides. Essayez encore.\n");
                continue;
            }
            place = placePion(x, y, joueur, grille);
            if (place == 0) {
                printf("(%d, %d) est déjà pris. Proposez autre chose.\n", x, y);
            }
        }

        fini = partieTerminee(grille, size);
        if (fini == 0) {
            joueur = 2;
            printf("# C'est à Joueur %d\n", joueur);
            joueurIA(joueur, grille, size);
            fini = partieTerminee(grille, size);
        }
    }
    printf("Jeu Terminé\n");
    afficherGrille(grille, size);

    for (unsigned int i = 0; i < size; i++) {
        free(grille[i]);
    }
    free(grille);

    return 0;
}
