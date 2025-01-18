#include<vector>
#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


vector<vector<int> > creerGrille(unsigned int N) ;
void effacerGrille(vector<vector<int >>* G) ;
int estAligne(int joueur,int x0,int y0,int nb,int dx, int dy,vector<vector<int >> G);
int grillePleine(vector<vector<int >> G) ;
void afficherGrille(vector<vector<int >> G);
int placePion(int x,int y,int joueur,vector<vector<int >>* G);
int aGagne(int joueur,vector<vector<int >> G);
int partieTerminee(vector<vector<int >> G);
void joueurIA(int joueur,vector<vector<int >>* G);



// programme principal
int main() {

    srand( time( NULL ) );

    vector<vector<int >> grille = creerGrille(3);
    effacerGrille(&grille);

    int x,y,joueur=1;
    int fini = 0;
    while(fini == 0)
    {
        afficherGrille(grille);
        joueur= 1;
        cout << "# C'est a Joueur "<< joueur << "\n";
        int place = 0;
        while(place != 1) {
            cout << "ou jouez vous ? (x,y) \nx : ";
            cin >> x;
            cout << "y : ";
            cin >> y;
            place = placePion(x,y,joueur,&grille);
            if(place==0)
            {
                cout <<"\n("<<x<<","<<y<<") est deja pris. Proposez autre chose.";
            }
        }

        fini = partieTerminee(grille);
        afficherGrille(grille);
        if(fini==0)
        {
            joueur = 2;
            cout << "# C'est a Joueur "<< joueur << "\n";
            joueurIA(joueur,&grille);
            fini = partieTerminee(grille);
        }
    }
    cout <<"Jeu Termine\n";
    afficherGrille(grille);
    return 0;
}





// Partie du code qui gere la grille
vector<vector<int> > creerGrille(unsigned int N) {
    vector<vector<int> > G;
    G.resize(N);
    for(unsigned int k=0; k<N; k++) {
        G[k].resize(N);
    }
    return G;
}

void effacerGrille(vector<vector<int >>* G) {
    for(unsigned int y=0; y<G->size(); y++) {
        for(unsigned int x=0; x<(*G)[y].size(); x++) {
            (*G)[y][x]=0;
        }
    }
}



int estAligne(int joueur,int x0,int y0,int nb,int dx, int dy,vector<vector<int >> G) {

    for(int k=0; k<nb; k++)
    {
        if(G[y0+k*dy][x0+k*dx]!=joueur)
        {   return 0;
        }
    }

    return 1;
}


int grillePleine(vector<vector<int >> G) {
    for(unsigned int y=0; y<G.size(); y++) {
        for(unsigned int x=0; x<G[y].size(); x++) {
            if(G[y][x]==0) return 0;
        }
    }
    return 1;
}



// partie du code qui gere le jeu
void afficherGrille(vector<vector<int >> G) {
    cout <<"\n";
    for(unsigned int y=0; y<G.size(); y++) {
        for(unsigned int x=0; x<G[y].size(); x++) {
            cout << " ";
            if(G[y][x]==0) {
                cout << " ";
            }
            if(G[y][x]==1) {
                cout << "X";
            }
            if(G[y][x]==2) {
                cout << "O";
            }
            if(x!=G[y].size() -1) {
                cout <<" |";
            }

        }
        if(y!=G.size()-1)
        {   cout << "\n";
            for(unsigned int x=0; x<G[y].size()*3+2; x++) {
                cout <<"-";
            }
        }
        cout <<"\n";
    }
    cout << "\n";
}



int placePion(int x, int y,int joueur,vector<vector<int >>* G)
{
    if((*G)[y][x]==0)
    {
        (*G)[y][x] = joueur;
        return 1;
    }
    else return 0;
}



int aGagne(int joueur,vector<vector<int >> G)
{   // test diagonales, puis lignes, puis colonnes
    int diags =  estAligne(joueur,0,0,3,1,1,G)==1  || estAligne(joueur,2,0,3,-1,1,G)==1 ;
    int lines = 0;
    int cols = 0;
    for(unsigned int i=0; i<3; i++)
    {   lines = lines || estAligne(joueur,i,0,3,0,1,G);
        cols = cols || estAligne(joueur,0,i,3,1,0,G);
    }
    if(  diags || lines || cols) {
        return 1;
    }

    return 0;
}

int partieTerminee(vector<vector<int >> G)
{
    if(aGagne(1,G)==1) {
        cout <<"\nJoueur 1 a gagne !\n";
        return 1;
    }
    if(aGagne(2,G)==1) {
        cout <<"\nJoueur 2 a gagne !\n";
        return  1;
    }

    if(grillePleine(G)==1) {
        cout<<"Aucun joueur n'a gagne.\n";
        return 1;
    }
    return 0;
}

// une IA idiote qui joue au hasard
void joueurIA(int joueur,vector<vector<int >>* G) {
    vector<int> X,Y;
    X.resize((*G).size() * (*G)[0].size());
    Y.resize((*G).size() * (*G)[0].size());
    int k=0;
    for(unsigned int y=0; y<(*G).size(); y++) {
        for(unsigned int x=0; x<(*G)[y].size(); x++) {
            if((*G)[y][x] == 0)
            {   X[k] = x;
                Y[k] = y;
                k++;
            }
        }
    }
    int IA = rand() % k;
    (*G)[Y[IA]][X[IA]] = joueur;

}


