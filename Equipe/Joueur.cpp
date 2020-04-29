#include "Joueur.h"

using namespace std;

Joueur::Joueur(const string &n) {
    _name = n;
    _buts = 1;
}

string Joueur::display() const {
    return getname();
}

string Joueur::getname() const {
    return _name;
}

int Joueur::buts() const {
    return _buts;
}

void Joueur::aMarque() {
    _buts++;
}


