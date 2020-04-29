#include "Equipe.h"

Equipe::Equipe(const string &name) {
    _name = name;
    _victoires = 0;
    _defaites = 0;
    _nuls = 0;
    _butsMis = 0;
    _butsPris = 0;
}

void Equipe::free() {
    for (Joueur *j : _joueurs) {
        delete j;
    }
}


int Equipe::points() {
    return getvictoires() * 3 + getnuls();
}

void Equipe::add_player(Joueur *j) {
    _joueurs.push_back(j);
}

double Equipe::goalAverage() const {
    return getbutsMis() / getbutsPris();
}

void Equipe::aPris(int &n) {
    _butsPris += n;
}

void Equipe::aMis(int &n) {
    _butsMis += n;
}

void Equipe::victoire() {
    _victoires++;
}

void Equipe::defaite() {
    _defaites++;
}

void Equipe::nul() {
    _nuls++;
}

string Equipe::display() const {
    return _name;
}
