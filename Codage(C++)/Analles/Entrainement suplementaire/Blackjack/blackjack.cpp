#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

typedef struct {
    int val;
    string couleur;
} carte;

void iniJeu(vector<carte>* jeu, vector<string>* Couleur) {
    carte tamp;
    for (int i = 0; i < Couleur->size(); i++) {
        for (int u = 1; u <= 13; u++) {
        	if(u>10){
            tamp.val = 10;
        	}
        	else{
        		tamp.val=u;
        	}
            tamp.couleur = (*Couleur)[i];
            jeu->push_back(tamp);
        }
    }
}

void melanger(vector<carte>* jeu) {
    double valeur;
    carte tamp;

    for (int i = 0; i < jeu->size(); i++) {
        valeur = ((double)rand()) / RAND_MAX;
        valeur *= jeu->size();
        tamp = (*jeu)[i];
        (*jeu)[i] = (*jeu)[(int)valeur];
        (*jeu)[(int)valeur] = tamp;
    }
}

int calculerTotal(vector<carte>* main) {
    int total = 0;
    int nbAs = 0;

    for (int i = 0; i < main->size(); i++) {
        total += (*main)[i].val;
        if ((*main)[i].val == 1) { // si c un as
            nbAs++;
        }
    }


    while (total <= 11 && nbAs > 0) {
        total += 10; // gestion as
        nbAs--;
    }
    return total;
}

void afftab(vector<carte>* J1, vector<carte>* Croup, int tj1, int tC) {
    cout << "Joueur 1 :\n";
    for (int k = 0; k < tj1; k++) {
        cout << (*J1)[k].val << " de " << (*J1)[k].couleur << endl;
    }

    cout << "\nCroupier :\n";
    for (int k = 0; k < tC; k++) {
        cout << (*Croup)[k].val << " de " << (*Croup)[k].couleur << endl;
    }
}

void deplaCarte(vector<carte>* jeu, vector<carte>* reception, int val) {
    if (jeu->size() > 0) {
        reception->emplace_back((*jeu)[val]);
        jeu->erase(jeu->begin() + val);
    } else {
        cout << "Erreur : Plus de cartes disponibles dans le jeu !" << endl;
    }
}

void regle(int* j1, int* C) {
    if ((*j1 > *C && *j1 <= 21) || *C > 21) {
        cout << "Joueur 1 gagne !" << endl;
    } else if ((*C > *j1 && *C <= 21) || *j1 > 21) {
        cout << "Croupier gagne !" << endl;
    } else {
        cout << "Égalité !" << endl;
    }
}

void tour(vector<carte>* jeu, vector<carte>* J1, vector<carte>* Croup) {
    int C = 2;
    int j1 = 2;

    for (int i = 0; i < 2; i++) {
        deplaCarte(jeu, J1, 0);
        deplaCarte(jeu, Croup, 0);
    }

    int totj1 = calculerTotal(J1);
    int totC = calculerTotal(Croup);

    // Boucle principale
    while (totj1 < 21 && totC < 21) {
        afftab(J1, Croup, j1, C);

        if (totC < 17) {
            deplaCarte(jeu, Croup, 0);
            C++;
            totC = calculerTotal(Croup);
        }

        char choix;
        cout << "Voulez-vous tirer une carte supplémentaire (Y/n) ? ";
        cin >> choix;

        if (choix == 'y' || choix == 'Y') {
            deplaCarte(jeu, J1, 0);
            j1++;
            totj1 = calculerTotal(J1);
        } else if (choix == 'n' || choix == 'N') {
            break;
        }
    }

    afftab(J1, Croup, j1, C);
    regle(&totj1, &totC);
}

int main() {
    srand(time(NULL));

    vector<string> couleursPossibles = {"Coeur", "Carreau", "Trefle", "Pique"};
    vector<carte> jeu, J1, Croup;

    iniJeu(&jeu, &couleursPossibles);
    melanger(&jeu);
    tour(&jeu, &J1, &Croup);

    return 0;
}
