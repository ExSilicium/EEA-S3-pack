#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// Fonction pour générer une clé répétée qui correspond à la longueur du texte
string genererCle(const string &texte, const string &cle) {
    string cleEtendue;
    int cleIndex = 0;

    for (size_t i = 0; i < texte.size(); ++i) {
        // Ignorer les espaces et les caractères spéciaux
        if (isalpha(texte[i])) {
            cleEtendue += cle[cleIndex % cle.size()];
            cleIndex++;
        } else {
            cleEtendue += texte[i];
        }
    }

    return cleEtendue;
}

// Fonction de chiffrement Vigenère
string chiffrerVigenere(const string &texte, const string &cle) {
    string texteChiffre;
    string cleEtendue = genererCle(texte, cle);

    for (size_t i = 0; i < texte.size(); ++i) {
        if (isalpha(texte[i])) {
            char base = isupper(texte[i]) ? 'A' : 'a';
            texteChiffre += (texte[i] - base + (cleEtendue[i] - base)) % 26 + base;
        } else {
            texteChiffre += texte[i];
        }
    }

    return texteChiffre;
}

// Fonction de déchiffrement Vigenère
string dechiffrerVigenere(const string &texteChiffre, const string &cle) {
    string texteDechiffre;
    string cleEtendue = genererCle(texteChiffre, cle);

    for (size_t i = 0; i < texteChiffre.size(); ++i) {
        if (isalpha(texteChiffre[i])) {
            char base = isupper(texteChiffre[i]) ? 'A' : 'a';
            texteDechiffre += (texteChiffre[i] - base - (cleEtendue[i] - base) + 26) % 26 + base;
        } else {
            texteDechiffre += texteChiffre[i];
        }
    }

    return texteDechiffre;
}

// Fonction principale
int main() {
    cout << "=== Chiffre de Vigenère ===" << endl;

    // Saisie du texte à chiffrer
    cout << "Entrez le texte : ";
    string texte;
    getline(cin, texte);

    // Saisie de la clé
    cout << "Entrez la clé : ";
    string cle;
    getline(cin, cle);

    // Vérifier si la clé contient uniquement des lettres
    for (char c : cle) {
        if (!isalpha(c)) {
            cout << "Erreur : La clé doit contenir uniquement des lettres." << endl;
            return 1;
        }
    }

    // Chiffrement
    string texteChiffre = chiffrerVigenere(texte, cle);
    cout << "Texte chiffré : " << texteChiffre << endl;

    // Déchiffrement
    string texteDechiffre = dechiffrerVigenere(texteChiffre, cle);
    cout << "Texte déchiffré : " << texteDechiffre << endl;

    return 0;
}
