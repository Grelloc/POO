#ifndef buteur_h
#define buteur_h

using namespace std;

#include "joueur.h"

class Buteur{
    private:
        Joueur* _joueur;
        int _timer;
    public:
        Buteur(Joueur &j, int t);
        int getTimer();
        void print();
};


#endif