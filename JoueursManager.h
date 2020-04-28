#ifndef joueursManager_h
#define joueursManager_h
#include "Joueur.h"
using namespace std;

class JoueursManager{
    private :
        vector<Joueur*> _joueurs;
    public :
        void trier(char sort);
        void add_player(Joueur * j);
        const int exist(string name);
        string display(int nDefined, unsigned n, char sort);
};


#endif