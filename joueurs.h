#ifndef joueursManager_h
#define joueursManager_h
#include "joueur.h"
using namespace std;

class JoueursManager{
    private :
        vector<Joueur*> _joueurs;
    public :
        void trier(char sort);
        void add_player(Joueur & j);
        void print();
        const int exist(string name);
};


#endif