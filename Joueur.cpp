#include "Joueur.h"
using namespace std;

string Joueur::display(){
    return getname(); 
}

const string Joueur::getname(){
    return _name;
}

const int Joueur::buts(){
    return _buts;
}

void Joueur::aMarque(){
    _buts++;
}

Joueur :: Joueur(const string & n){
    _name = n;
    _buts = 1;
}
