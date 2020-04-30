#include "Buteur.h"

Buteur::Buteur(Joueur *j, int t) {
    _joueur = j;
    j->aMarque();
    _timer = t;
}

string Buteur::display() const {
    return _joueur->display().append("(").append(to_string(_timer)).append(")");
}

Joueur *Buteur::get_player() const {
    return _joueur;
}
