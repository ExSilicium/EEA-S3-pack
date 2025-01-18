
# include < vector >
# include < iostream >
using namespace std ;

typedef struct
{
    vector<vector<char>>grille ;
    int difficulte ;

} p4 ;

p4 initialise (int largeur, int hauteur )
{
    /* a completer */

}

void place_pion ( int x, p4 *p, char symbole )
{
    /* a completer */
}

void f1 (p4 p)
{
    int x, y ;
    for ( y=0; y < p.grille.size() ; y++)
    {
        for ( x=0; x<p.grille[y].size() ;x++)
        {
            cout << p.grille[y][x] << " | " ;
        }
        cout << " \ n " ;
    }
}

int nb_cases_vides ( p4 *p )
{
    /* a completer */
}

int main ()
{   int x, tour =0;
    char pion, pionX = 'X', pionO = 'O ';
    p4 jeu = initialise (7,5) ;
    /* a completer */
}
