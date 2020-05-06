#include "Player.h"

#include <utility>

using namespace std;

Player::Player(const string &n, const string &team) : _name(n), _team(team) {}

int Player::get_goals() const {
    return _goals;
}

string Player::get_team() const {
    return _team;
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


string Player::display(const char &sort) const {
    string message(get_name() + " (" + get_team() + ")\n\t\t\t\t\t\t");
    switch (sort) {
        case 'b':
            message.append(to_string(get_goals())).append(" Buts");
            break;
        case 'm':
            message.append(to_string(goalAverage())).append(" Buts/Match");
            break;
        default:
            throw string("Error, this should not happened\n");
    }     
    return message;
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
