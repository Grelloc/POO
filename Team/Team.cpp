#include "Team.h"

Team::Team(const string &name) {
    _name = name;
    _victoires = 0;
    _defaites = 0;
    _nuls = 0;
    _butsMis = 0;
    _butsPris = 0;
}

int Team::points() const {
    return getvictoires() * 3 + getnuls();
}

void Team::add_player(Player *j) {
    if (!exist(j->get_name())) {
        _players.push_back(j);
    }
}

double Team::goalAverage() const {
    return getbutsMis() / getbutsPris();
}

void Team::aPris(int &n) {
    _butsPris += n;
}

void Team::aMis(int &n) {
    _butsMis += n;
}

void Team::victory() {
    _victoires++;
}

void Team::defeat() {
    _defaites++;
}

void Team::nul() {
    _nuls++;
}

int Team::get_nMatch() const {
    return _victoires + _defaites + _nuls;
}

void Team::update_players() {
    for (Player *j: _players) {
        j->havePlayed(get_nMatch());
    }
}

string Team::display() const {
    return _name;
}

double Team::get(const char &sort) const {
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

bool Team::exist(const string &name) const {
    for (const Player *player : _players) {
        if (player->get_name() == name) {
            return true;
        }
    }
    return false;
}