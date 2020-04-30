#include "Player.h"

using namespace std;

Player::Player(const string &n) {
    _name = n;
    _goals = 0;
    _match = 0;
}

int Player::get_goals() const {
    return _goals;
}

double Player::goalAverage() const {
    return _goals / double(_match);
}

string Player::get_name() const {
    return _name;
}


void Player::aMarque() {
    _goals++;
}

void Player::havePlayed(const int &n) {
    _match += n;
}


string Player::display() const {
    return get_name();
}

double Player::get(const char &sort) const {
    switch (sort) {
        case 'b':
            return get_goals();
        case 'm':
            return goalAverage();
        default:
            break;
    }
    return 1;
}
