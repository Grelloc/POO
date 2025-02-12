#include "Team.h"

#include <string>

using namespace std;

Team::Team(const string &name) : _name(name) {
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

int Team::goalAverage() const {
    return getbutsMis() - getbutsPris();
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

string Team::display(const char &sort) const {
    string message(getname() + setSpace(10));

    switch (sort) {
        case 'p':
            message.append(to_string(points())).append(" points\n");
            break;
        case 'v':
            message.append(to_string(_victoires)).append(" victoires\n");
            break;
        case 'd':
            message.append(to_string(_defaites)).append(" defaites\n");
            break;
        case 'n':
            message.append(to_string(_nuls)).append(" match nuls\n");
            break;
        case 'm':
            message.append(to_string(_butsMis)).append(" buts mis\n");
            break;
        case 'e':
            message.append(to_string(_butsPris)).append(" buts pris\n");
            break;
        case 'g':
            message.append(to_string(goalAverage())).append(" goal average\n");
            break;

        default:
            throw string("Error, this shouldn't have happened\n");
    }
    return message;
}

string Team::setSpace(int n) const {
    string message;
    for (unsigned i = 0; i < n - ((getname().length() - 3) / 4); i++) {
        message.append("\t");
    }
    return message;
}

int Team::get(const char &sort) const {
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
    throw string("bad use of Team::get() function");
}

bool Team::exist(const string &name) const {
    for (const Player *player : _players) {
        if (player->get_name() == name) {
            return true;
        }
    }
    return false;
}