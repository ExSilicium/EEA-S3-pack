#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef struct {
    int valeur;
    string couleur;
} carte;

void remplC(vector<string> couleursPossibles, vector<carte> *jeu);
int deplacerCarte(vector<carte> *origine, vector<carte> *destination, int numero);
void melanger(vector<carte> *amelanger);
void bataille(vector<carte>* j1, vector<carte>* j2);

int main() {
    vector<string> couleursPossibles = {"Coeur", "Carreau", "Trefle", "Pique"};
    vector<carte> jeu;
    vector<carte> joueur1, joueur2;
    vector<carte> defausse;

    // Remplir le jeu de cartes
    remplC(couleursPossibles, &jeu);

    // Mélanger les cartes
    melanger(&jeu);

    // Distribution de 5 cartes à chaque joueur
    for (int i = 0; i < 5; i++) {
        deplacerCarte(&jeu, &joueur1, 0); // Donne une carte à joueur1
        deplacerCarte(&jeu, &joueur2, 0); // Donne une carte à joueur2
    }

    // Jouer une partie de bataille
    bataille(&joueur1, &joueur2);

    return 0;
}

void remplC(vector<string> couleursPossibles, vector<carte> *jeu) {
    for (int i = 1; i <= 13; i++) {
        for (int u = 0; u < 4; u++) {
            carte nouvelleCarte;
            nouvelleCarte.valeur = i;
            nouvelleCarte.couleur = couleursPossibles[u];
            (*jeu).push_back(nouvelleCarte);
        }
    }
    carte joker1, joker2;
    joker1.valeur = 0;
    joker1.couleur = "Joker";
    joker2.valeur = 0;
    joker2.couleur = "Joker";
    (*jeu).push_back(joker1);
    (*jeu).push_back(joker2);
}

int deplacerCarte(vector<carte> *origine, vector<carte> *destination, int numero) {
    if (numero < 0 || numero >= origine->size()) {
        return -1;
    }

    destination->push_back((*origine)[numero]);

    for (int i = numero; i < origine->size() - 1; i++) {
        (*origine)[i] = (*origine)[i + 1];
    }

    origine->pop_back();

    return 0;
}

// Fonction de mélange
void melanger (vector<carte> *amelanger){

	for(int i=0;i<(*amelanger).size()/2;i++){
		carte stok;
		double valeur;
		valeur = ((double)rand()) / RAND_MAX;
		valeur = 54*valeur;
		stok =(*amelanger)[i];
		(*amelanger)[i]=(*amelanger)[valeur];
		(*amelanger)[valeur]=stok;


	}

}

// Fonction de la partie de bataille
void bataille(vector<carte>* j1, vector<carte>* j2) {
    int scoreJ1 = 0, scoreJ2 = 0;

    while (!j1->empty() && !j2->empty()) {
        carte carteJ1 = j1->back();
        carte carteJ2 = j2->back();

        cout << "Joueur 1: " << carteJ1.valeur << " de " << carteJ1.couleur << " - ";
        cout << "Joueur 2: " << carteJ2.valeur << " de " << carteJ2.couleur << endl;

        if (carteJ1.valeur == 0) {
            cout << "Joueur 1 gagne la manche avec un Joker!" << endl;
            scoreJ1++;
        } else if (carteJ2.valeur == 0) {
            cout << "Joueur 2 gagne la manche avec un Joker!" << endl;
            scoreJ2++;
        } else if (carteJ1.valeur > carteJ2.valeur) {
            cout << "Joueur 1 gagne la manche!" << endl;
            scoreJ1++;
        } else if (carteJ1.valeur < carteJ2.valeur) {
            cout << "Joueur 2 gagne la manche!" << endl;
            scoreJ2++;
        } else {
            cout << "Égalité! Les cartes sont égales!" << endl;
        }
        j1->pop_back();
        j2->pop_back();
    }


    cout << "Score final: " << endl;
    cout << "Joueur 1: " << scoreJ1 << " points" << endl;
    cout << "Joueur 2: " << scoreJ2 << " points" << endl;

    if (scoreJ1 > scoreJ2) {
        cout << "Joueur 1 remporte la partie!" << endl;
    } else if (scoreJ1 < scoreJ2) {
        cout << "Joueur 2 remporte la partie!" << endl;
    } else {
        cout << "La partie est un match nul!" << endl;
    }
}
