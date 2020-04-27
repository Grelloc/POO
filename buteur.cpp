#include "buteur.h"

Buteur::Buteur(Joueur &j, int t){
    _joueur = &j;
    _timer = t;
}

int Buteur::getTimer(){
    return _timer;
}

void Buteur::print(){
    _joueur->print();
    cout << " (" << getTimer() << ')';
}