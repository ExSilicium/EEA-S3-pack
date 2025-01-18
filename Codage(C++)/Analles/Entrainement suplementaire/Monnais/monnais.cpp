#include <vector>
#include <iostream>
using namespace std;

typedef struct {
    double valeur;
    int nombre;
} monnaie;

void affcaisse (vector<monnaie> caisse);
void total (vector<monnaie> caisse);
vector<monnaie> rendreMonnaie(double donne, double prix,vector<monnaie>* caisse);

int main() {
    vector<monnaie> caisse =  {{500,3},{100,7},{50,12},{20,22},{10,15},
        {5,25},{2,15},{1,25},{0.5,20}
    };

    affcaisse(caisse);
    total(caisse);
    double prix, donne;
    cout << "\nEntrez le prix de l'article : ";
    cin >> prix;
    cout << "Entrez le montant donné par le client : ";
    cin >> donne;

    vector<monnaie> monnaieRendue = rendreMonnaie(donne, prix, &caisse);


   cout << "\nA rendre :\n";
 	affcaisse(monnaieRendue);
    cout << "\nÉtat final de la caisse :\n";
    affcaisse(caisse);
    total(caisse);



    return 0;
}
void affcaisse (vector<monnaie> caisse) {

    for(int i = 0; i<caisse.size(); i++) {
    	if(caisse[i].nombre !=0){
        cout<<"Monais de:"<<caisse[i].valeur;
        cout<<" --> "<<caisse[i].nombre<<endl;
    	}

    }
}

void total (vector<monnaie> caisse) {

    int T=0;
    for(int i= 0; i<caisse.size(); i++) {
        T+=caisse[i].valeur*caisse[i].nombre;
    }

    cout<<"Totale de la caisse: "<<T<<endl;

}

vector<monnaie> rendreMonnaie(double donne, double prix,vector<monnaie>* caisse) {
    double rendu = donne-prix;
vector<monnaie> rendreMonnaie ;

    for (int i= 0 ; i<caisse->size();i++){
    	rendreMonnaie.push_back({(*caisse)[i].valeur,0});
    }








    for(int i=0; i<(*caisse).size(); i++) {

        while ((*caisse)[i].valeur<=rendu && (*caisse)[i].nombre>0) {
            rendreMonnaie[i].nombre+=1;
            (*caisse)[i].nombre-=1;
            rendu-=(*caisse)[i].valeur;
        }



        if(rendu==0.0) {
            break;
        }


    }
    return rendreMonnaie;
}
