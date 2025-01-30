#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> tab = {1,8,5,6,2,12,15,21,3,7,-1,17,19,20};
    int k = 0;
    cout << "tableau non trie : \n";
    while (k < tab.size()) {
    cout << tab[k] << "\n";
    k=k+1;
    }
    
    // calculer le maximum de tab
    int maximum = tab[0];
    k = 1;
    while (k < tab.size()) {
        if (maximum < tab[k]) {
            maximum = tab[k];
        }
        k=k+1;
    }
    // creation du tableau a remplir par l'algorithme de tri
    vector<int> tabt;
    tabt.resize(tab.size());
    
    // algorithme de tri
    k=0;
    while(k<tabt.size())
    {
        int posmin = 0;     	// calcul de la position du minimum dans tab
        int minimum = tab[0];
        int l = 1;
        while (l < tab.size()) {
            if (minimum > tab[l]) {
                minimum = tab[l];
                posmin = l;
            }
            l=l+1;
        }
        tabt[k] = minimum; // on met le minimum a la bonne position dans tabt
        tab[posmin] = maximum; // on remplace le minimum par le max dans tab
        k=k+1;
    }
    

    cout << "\ntableau trie : \n";
    k = 0;
    while (k < tab.size()) {
    cout << tabt[k] << "\n";
    k=k+1;
    }   

    return 0;
}
