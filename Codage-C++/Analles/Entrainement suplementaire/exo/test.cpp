#include <iostream>
#include <vector>

using namespace std;

struct Joueur {
    int positionX;
    int positionY;
};

struct Labyrinthe {
    vector<vector<char>> disposition;
};

void initialiserLabyrinthe(Labyrinthe* labyrinthe) {
    (*labyrinthe).disposition = {
        {'#', 'S', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' '},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', 'E', '#'},
    };
}

void afficherLabyrinthe(Labyrinthe labyrinthe, Joueur joueur) {
    for (unsigned long i = 0; i < labyrinthe.disposition.size(); i++) {
        for (unsigned long j = 0; j < labyrinthe.disposition[i].size(); j++) {
            if (i == joueur.positionX && j == joueur.positionY) {
                cout << "J "; // Affiche le joueur à sa position
            } else {
                cout << labyrinthe.disposition[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int DeplacementPasseMuraille(Labyrinthe* labyrinthe, Joueur* J, int deltaX, int deltaY) {
    int nouvelleX = (*J).positionX + deltaX;
    int nouvelleY = (*J).positionY + deltaY;

    // Vérifier si le déplacement reste dans les limites du labyrinthe
    if (nouvelleX >= 0 && nouvelleX < (int)(*labyrinthe).disposition.size() &&
        nouvelleY >= 0 && nouvelleY < (int)(*labyrinthe).disposition[0].size()&&(*labyrinthe).disposition[nouvelleX][nouvelleY]!='#') {
    	J->positionX+=deltaX;
    	J->positionY+=deltaY;
    	afficherLabyrinthe(*labyrinthe,*J);
    	return 1; // Déplacement réussi
    }

    else{
    	return 0; // Déplacement impossible
        }



}

int main() {
    Joueur joueur1;
    joueur1.positionX = 7; // Position initiale du joueur
    joueur1.positionY = 7;

    int x=0;
    int y=0;
    char mov;

    Labyrinthe labyrinthe;
    initialiserLabyrinthe(&labyrinthe);

    cout << "Labyrinthe initial :\n";
    afficherLabyrinthe(labyrinthe, joueur1);
while(!(joueur1.positionX==0 && joueur1.positionY==1)){
	//commandes
	cout<<"deplacer vous(zqsd)"<<endl;cin>>mov;


	switch(mov) {

		case'Z':
		case'z':
			x=-1;
			y=0;
			break;

		case 'Q':
		case 'q':
			y=-1;
			x=0;
			break;

		case 'S':
		case 's':
			x=1;
			y=0;
			break;

		case 'D':
		case 'd':
			y=1;
			x=0;
			break;

	}

    // Exemple de déplacement
    cout << "\nTentative de déplacement vers le haut :\n";
    if (DeplacementPasseMuraille(&labyrinthe, &joueur1, x, y)) {
        cout << "Déplacement réussi !"<<endl;
    } else{
        cout << "Aie ca fait mal!\n"<<endl;;
    }
}
    return 0;
}
