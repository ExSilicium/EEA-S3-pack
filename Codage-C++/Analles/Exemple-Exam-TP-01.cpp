#include<vector>
using namespace std;

typedef struct {
    double coeff;
    double exp;
} terme;


int main()
{

    int n=1;
    vector<terme> Polynome1;

    Polynome1.resize(10);
    Polynome1[0].coeff = 1.0;
    Polynome1[0].exp = 1.0;

// creation d'un polynome 
    den = 1.0;
    while(n<100) {
        den = den*(2*n+1.0)*(2*n)*(-1.0)
        Polynome1[n].coeff = 1/den;
        Polynome1[n].exp   = 2.0*n+1.0;
        n = n + 1;
    }

// affichage du polynome
    for(n = 0; n < size() ; n++) {
        cout << Polynome1[n].coeff << "*x^"<<Polynome1[n].exp << " + ";
    }

    return 0;
}