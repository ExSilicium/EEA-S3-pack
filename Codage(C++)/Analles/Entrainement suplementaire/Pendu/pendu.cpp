#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

string IniJeu(vector<string> *mots, string *rep) {
    double valeur;
    valeur = ((double)rand()) / RAND_MAX;
    valeur *= mots->size();
    string mot = (*mots)[(int)valeur];

    for (int i = 0; i < mot.size(); i++) {
        rep->push_back('-');
    }
    return mot;
}

void jeu(string mot, string *repo, int vie) {
    char devine;
    while (vie > 0 && (*repo) != mot) {
        cout << "Mot actuel : " << (*repo) << endl;
        cout << "Devinez une lettre (vies restantes : " << vie << "): ";
        cin >> devine;

        int c = 0;
        for (int u = 0; u < mot.size(); u++) {
            if (mot[u] == devine) {
                (*repo)[u] = devine;
                c++;
            }
        }

        if (c == 0) {
            vie--;
            cout << "Ce n'est pas la bonne lettre. Il vous reste " << vie << " vies." << endl;
        } else {
            cout << "Bonne lettre !" << endl;
        }

        if (*repo == mot) {
            cout << "Félicitations, vous avez gagné ! Le mot était : " << mot << endl;
            return;
        }
    }

    if (vie == 0) {
        cout << "Désolé, vous avez perdu. Le mot était : " << mot << endl;
    }
}

int main() {
    srand(time(NULL));

    vector<string> mots = {"pomme", "banane", "cerise", "orange", "mangue", "fraise", "kiwi"};
    string mot;
    string rep;
    int vie = 8;

    mot = IniJeu(&mots, &rep);
    jeu(mot, &rep, vie);


    return 0;
}
