#include "joueur.h"
using namespace std;

void Joueur::print(){
    cout << getname(); 
}

const string Joueur::getname(){
    return _name;
}

const int Joueur::buts(){
    return _buts;
}

const int Joueur::getmatch(){
    return _match;
}

void Joueur::aMarque(){
    _buts++;
}

void Joueur::aJoue(){
    _match++;
}

Joueur :: Joueur(const string & n){
    _name = n;
    _buts = 1;
    _match = 0;
}
