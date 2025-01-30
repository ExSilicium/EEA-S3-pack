#include <iostream>
#include <vector>
using namespace std;

// Structure pour modéliser une règle
typedef struct {
    vector<int> avant; // Motif de 3 cases
    int resultat;      // Résultat (0 ou 1) pour la case centrale
} Regle;

// Fonction pour initialiser une règle
Regle init(vector<int> avant, int resultat) {
    Regle r;
    r.avant = avant;
    r.resultat = resultat;
    return r;
}

// Fonction pour appliquer une règle à un motif donné
int appliquerRegle(vector<Regle>* regles, int gauche, int centre, int droite) {
    for (size_t i = 0; i < regles->size(); i++) {
        if ((*regles)[i].avant[0] == gauche && (*regles)[i].avant[1] == centre && (*regles)[i].avant[2] == droite) {
            return (*regles)[i].resultat; // Retourner le résultat si le motif correspond
        }
    }
    return 0; // Par défaut, retourne 0 si aucune règle ne correspond
}

int main() {
    const int TAILLE = 80; // Taille du tableau
    const int ETAPES = 24; // Nombre d'étapes d'évolution

    // Initialisation des règles pour la règle 126
    vector<Regle> regles;
    regles.push_back(init({1, 1, 1}, 0));
    regles.push_back(init({1, 1, 0}, 1));
    regles.push_back(init({1, 0, 1}, 1));
    regles.push_back(init({1, 0, 0}, 1));
    regles.push_back(init({0, 1, 1}, 1));
    regles.push_back(init({0, 1, 0}, 1));
    regles.push_back(init({0, 0, 1}, 1));
    regles.push_back(init({0, 0, 0}, 0));

    // Initialisation du tableau
    vector<int> tableau(TAILLE, 0);
    tableau[TAILLE / 2] = 1; // Mettre un "1" au centre du tableau

    // Tableau temporaire pour calculer l'étape suivante
    vector<int> nouveauTableau(TAILLE, 0);

    // Affichage de l'état initial
    for (int i = 0; i < TAILLE; i++) {
        cout << (tableau[i] ? '*' : ' '); // Affiche '*' pour 1 et ' ' pour 0
    }
    cout << endl;

    // Simulation des étapes
    for (int etape = 0; etape < ETAPES; etape++) {
        for (int i = 1; i < TAILLE - 1; i++) { // Ignore les bords
            int gauche = tableau[i - 1];
            int centre = tableau[i];
            int droite = tableau[i + 1];
            nouveauTableau[i] = appliquerRegle(&regles, gauche, centre, droite);
        }

        // Mise à jour du tableau
        tableau = nouveauTableau;

        // Affichage de l'étape
        for (int i = 0; i < TAILLE; i++) {
            cout << (tableau[i] ? '*' : ' '); // Affiche '*' pour 1 et ' ' pour 0
        }
        cout << endl;
    }

    return 0;
}
