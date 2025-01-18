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
		{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ''},
		{' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
		{'#', '#', '#', '#', '#', '#', '#', ' ', '#'},
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
		{'#', '#', '#', '#', '#', '#', '#', ' ', '#'},
		{'#', '#', '#', '#', '#', '#', '#', 'E', '#'},
	};
}

void afficherLabyrinthe(Labyrinthe labyrinthe) {
	for (unsigned long i = 0; i < labyrinthe.disposition.size(); i++) {
		for (unsigned long j = 0; j < labyrinthe.disposition[i].size(); j++) {
			cout << labyrinthe.disposition[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	Joueur joueur1;
	joueur1.positionX = 0;
	joueur1.positionY = 0;
	

	Labyrinthe labyrinthe;
	initialiserLabyrinthe(&labyrinthe);

	cout << "\nLabyrinthe Initial:" << "\n";
	afficherLabyrinthe(labyrinthe);


	return 0;
}