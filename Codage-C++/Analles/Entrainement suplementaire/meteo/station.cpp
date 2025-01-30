#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct {
    string ville ;
    vector<vector<float>> temp ;
} station ;

void temperatures_aleatoires(station *s) {
    double valeur;
    double max=50;
    double min=-20;
    for(int i=0; i<(*s).temp.size(); i++) {
        for(int j=0; j<(*s).temp[i].size(); j++) {
            valeur = ((double)rand()) / RAND_MAX;
            s->temp[i][j]=min+(max-min)*valeur;
        }
    }
}

station initialise(string nom) {
    station ini;
    ini.ville=nom;
    ini.temp=vector<vector<float>>(7,vector<float>(3));
    temperatures_aleatoires(&ini);
return ini;
}



double temp_moy(station *s) {
    double moy=0;
    double stack=0;
    for(int i=0; i<(*s).temp.size(); i++) {
        for(int j=0; j<(*s).temp[i].size(); j++) {
            stack+=s->temp[i][j];
        }
    }

    moy=stack/(s->temp.size()*s->temp[0].size());

        return moy;
}


void afficher(station *s) {
    cout<< s->ville<<endl<<"Moyenne de la temp"<<temp_moy(s)<<endl;
    for(int j=0; j<(*s).temp[j].size(); j++) {
        for(int i=0; i<(*s).temp.size(); i++) {
            cout<<s->temp[i][j]<<" | ";
        }
        cout<<endl;


    }
}


int main(){
	vector<string> villes = {"Paris","Lyon","Marseille","Toulouse","Montpellier","Nimes",
			"Lille","Rennes","Clermont-Ferrand","Grenoble"};

	srand(time(NULL));

vector<station> nouv;
nouv.resize(villes.size());
	for(int i =0; i<nouv.size(); i++){
	nouv[i] = initialise(villes[i]);
	}


	for(int i =0; i<villes.size(); i++){
		afficher(&nouv[i]);
	}


return 0;
}

