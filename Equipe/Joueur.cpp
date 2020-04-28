#include "Joueur.h"

using namespace std;

string Joueur::display() {
    return getname();
}

string Joueur::getname() const{
    return _name;
}

int Joueur::buts() const{
    return _buts;
}

void Joueur::aMarque() {
    _buts++;
}

Joueur::Joueur(const string &n) {
    _name = n;
    _buts = 1;
}
