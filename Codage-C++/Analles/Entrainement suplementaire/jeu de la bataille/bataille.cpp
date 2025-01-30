#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct {
int valeur;
string couleur;
}carte;

void iniJeu(vector<carte>* jeu ,vector<string>* couleursPossibles){
	carte nouv;
	for (int i=0 ; i<couleursPossibles->size();i++){
		for(int u=1; u<=13;u++){
			nouv.valeur=u;
			nouv.couleur=(*couleursPossibles)[i];
			jeu->push_back(nouv);
		}
	}
carte jok1;
carte jok2;
jok1.couleur="Joker";
jok2.couleur="Joker";
jok1.valeur=0;
jok2.valeur=0;

jeu->push_back(jok1);
jeu->push_back(jok2);
}

int deplacerCarte ( vector <carte>* origine , vector <carte>* destination , int numero){

	if(numero>origine->size() || numero<0){
		return 1;
	}
	else{
		destination->emplace_back((*origine)[numero]);
		for(int i=numero;i<origine->size()-1;i++){
			(*origine)[i]=(*origine)[i+1];
		}
		origine->pop_back();
		return 0;
	}
}

void melanCarte(vector<carte>* jeu){
	double valeur;
	carte stak;
	for(int i=0; i<jeu->size();i++){
		valeur= ((double)rand()) / RAND_MAX;
		valeur*=jeu->size();
		stak=(*jeu)[i];
		(*jeu)[i]=(*jeu)[(int)valeur];
		(*jeu)[(int)valeur]=stak;
	}
}

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

int main() {
vector<string> couleursPossibles={"Coeur","Carreau","Trefle","Pique"};
vector<carte> jeu;
vector<carte> joueur1, joueur2;
srand(time(NULL));

iniJeu(&jeu, &couleursPossibles);
melanCarte(&jeu);



for (int i=0; i<5;i++){
	deplacerCarte(&jeu,&joueur1,i);
	deplacerCarte(&jeu,&joueur2,i);
}

bataille(&joueur1,&joueur2);


return 0;
}

