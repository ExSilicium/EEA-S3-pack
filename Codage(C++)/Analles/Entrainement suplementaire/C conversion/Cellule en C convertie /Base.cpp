 #include <vector>
#include <iostream>
using namespace std;


typedef struct {
    vector<int> avant;
    int resultat;
} regle;


regle init(vector<int> a, int r);
vector<regle> toutesRegles();
void affLigne(vector<int> m);
int appliquerRegles(vector<int> m, int position, vector<regle> regles);
vector<int> calcLigne(vector<int> m,vector<regle> r) ;



// fonction principale
int main()
{
    vector<regle> regles = toutesRegles();

    vector<int> ligne;
    ligne.resize(80);
    int k;
    for( k=0; k<ligne.size(); k++)
    {
        ligne[k]=0;
    }
    ligne[40]=1;

    int l;
    for(l=0; l<32; l++) {
        affLigne(ligne);
        ligne = calcLigne(ligne,regles);
    }

    return 0;
}


// gestion des regles
regle init(vector<int> a, int r)
{

    regle R;
    R.avant = a;
    R.resultat = r;

    return R;
}

vector<regle> toutesRegles()
{
    vector<regle> T;
    T.resize(8);
    T[0] = init({0,0,0},0);
    T[1] = init({0,0,1},1);
    T[2] = init({0,1,0},1);
    T[3] = init({0,1,1},1);
    T[4] = init({1,0,0},1);
    T[5] = init({1,0,1},1);
    T[6] = init({1,1,0},1);
    T[7] = init({1,1,1},0);

    return T;
}


// gestion du calcul
void affLigne(vector<int> m) {
    int k;
    for(k=0; k<m.size(); k++)
    {
        if(m[k]==0) {
            cout << " ";
        }
        else {
            cout << "*";
        }

    }
    cout <<"\n";
}


int appliquerRegles(vector<int> m, int position, vector<regle> regles) {
    for(unsigned int r=0; r<regles.size(); r++) {
        if ( m[position-1] == regles[r].avant[0]
                &&  m[position] == regles[r].avant[1]
                &&  m[position+1]==regles[r].avant[2]
           )
        {
            return regles[r].resultat;
        }
    }
    return -1; // ne devrait jamais arriver
}

vector<int> calcLigne(vector<int> m,vector<regle> r) {

    vector<int> n;
    n.resize(m.size());

    for(unsigned int k=1; k<n.size()-1; k++)
    {
        n[k] = appliquerRegles(m,k,r);
    }

    n[0]=0;
    n[n.size()-1]=0;

    return n;
}

