#include "Equipe.h"

Equipe::Equipe(const string &name) {
    _name = name;
    _victoires = 0;
    _defaites = 0;
    _nuls = 0;
    _butsMis = 0;
    _butsPris = 0;
}

int Equipe::points() const {
    return getvictoires() * 3 + getnuls();
}

void Equipe::add_player(Joueur *j) {
    if (!exist(j->getname())) {
        _joueurs.push_back(j);
    }
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

int Equipe::get_nmatch() const {
    return _victoires + _defaites + _nuls;
}

void Equipe::update_players() {
    for (Joueur *j: _joueurs) {
        j->aJoue(get_nmatch());
    }
}

string Equipe::display() const {
    return _name;
}

double Equipe::get(const char &sort) const {
    switch (sort) {
        case 'p':
            return points();
        case 'v':
            return _victoires;
        case 'd':
            return _defaites;
        case 'n':
            return _nuls;
        case 'm':
            return _butsMis;
        case 'e':
            return _butsPris;
        case 'g':
            return goalAverage();
        default:
            break;
    }
    return 1;
}

bool Equipe::exist(const string &name) const {
    for (const Joueur *player : _joueurs) {
        if (player->getname() == name) {
            return true;
        }
    }
    return false;
}