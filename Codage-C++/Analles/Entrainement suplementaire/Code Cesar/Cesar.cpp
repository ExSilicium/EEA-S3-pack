#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Pour les fonctions utilitaires
using namespace std;

// Fonction pour chiffrer le texte avec le chiffrement de César
void chiffreCesar(string* texte, int decalage) {
    for (int i = 0; i<texte->size(); i++) { // Parcourt chaque caractère de la chaîne
        if ((*texte)[i] >= 'A' && (*texte)[i] <= 'Z') { // Majuscules
        	(*texte)[i] = 'A' + ((*texte)[i] - 'A' + decalage) % 26;
        }
        else if ((*texte)[i] >= 'a' && (*texte)[i] <= 'z') { // Minuscules
        	(*texte)[i] = 'a' + ((*texte)[i] - 'a' + decalage) % 26;
        }
    }
}

int main() {
    string texte;
    int decalage;

    // Saisie utilisateur pour le texte (pas de getline ici)
    cout << "Entrez le texte à chiffrer : ";
    cin >> texte; // Lit une chaîne jusqu'à un espace ou retour à la ligne

    // Saisie utilisateur pour le décalage
    cout << "Entrez le décalage : ";
    cin >> decalage;

    // Chiffrement du texte
    chiffreCesar(&texte, decalage);

    // Affichage du texte chiffré
    cout << "Texte chiffré : " << texte << endl;

    return 0;
}
