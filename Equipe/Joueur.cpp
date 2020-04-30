#include "Joueur.h"

using namespace std;

Joueur::Joueur(const string &n) {
    _name = n;
    _buts = 0;
    _match = 0;
}

int Joueur::buts() const {
    return _buts;
}

double Joueur::butsaverage() const {
    return _buts / double(_match);
}

string Joueur::getname() const {
    return _name;
}


void Joueur::aMarque() {
    _buts++;
}

void Joueur::aJoue(const int &n) {
    _match += n;
}


string Joueur::display() const {
    return getname();
}

double Joueur::get(const char &sort) const {
    switch (sort) {
        case 'b':
            return buts();
        case 'm':
            return butsaverage();
        default:
            break;
    }
    return 1;
}
