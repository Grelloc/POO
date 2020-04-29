#include "Joueur.h"

using namespace std;

Joueur::Joueur(const string &n) {
    _name = n;
    _buts = 0;
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

double Joueur::get(const char &sort) const{
    switch (sort) {
        case 'b':
            return buts();
        default:
            break;
    }
    return 1;
}
