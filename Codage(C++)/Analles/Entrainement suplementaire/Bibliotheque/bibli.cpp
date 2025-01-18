#include<iostream>
#include<vector>

using namespace std;

typedef struct{
	string auteur;
	string titre;
	int anne;
	bool emprun=false;
	}livre;

int main(){




}

void ajoute(vector<livre>* bibli){
	livre ajt;
	cout<<"ajouter le livre \n Auteur:";cin>>ajt.auteur;
	cout<<"\n Titre:";cin>>ajt.titre;
	cout<<"\n Anne:";cin>>ajt.anne;
	bibli->push_back(ajt);
}
void empunt(vector<livre>* bibli){
	string c;
	int nb=-1;
	cout<<"Nom du livre chercher: "<<endl;
	cin>>c;
	for(int i=0;i<(*bibli).size();i++){
		if ((*bibli)[i].titre==c){
			nb=i
		}
	}
	if(nb==-1){
		cout<<"livre introuver";
	}
	else if(nb!=-1){
		cout<<(*bibli)[nb].titre;
		if((*bibli)[nb].emprun!=false){
			(*bibli)[nb].emprun=true;
		}
		else{
			cout<<"livre indisponible"<<endl;
		}
	}

}

void coutlivre(livre L){
	cout<<"\n Auteur: "<<L.auteur<<"\n Titre: "<<L.titre<<"\n Anne: "<<L.anne<<"\n Emprun statue: "<<L.emprun<<endl;
}
