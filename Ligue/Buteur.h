#ifndef buteur_h
#define buteur_h

using namespace std;

#include "../Equipe/Joueur.h"

class Buteur {
private:
    Joueur *_joueur;
    int _timer;
public:
    Buteur(Joueur *j, int t);

    string display() const;
};


#endif