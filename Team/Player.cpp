#include "Player.h"

#include <utility>
#include <string>

using namespace std;

Player::Player(string n, string team) : _name(std::move(n)), _team(std::move(team)) {
    _match = 0;
    _goals = 0;
}

int Player::get_goals() const {
    return _goals;
}

string Player::get_team() const {
    return _team;
}

int Player::goalAverage() const {
    return (_goals * 100) / _match;
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

string Player::displayAv() const {
    string message;
    int Av = goalAverage();
    if (Av < 100) {
        if (Av < 10) {
            return message.append("0.0").append(to_string(Av));
        } else {
            return message.append("0.").append(to_string(Av));
        }
    }
    return message.append(to_string(goalAverage()).insert(message.size() - 2, "."));
}


string Player::display(const char &sort) const {
    string message(get_name() + " (" + get_team() + ")\n\t\t\t\t\t\t\t");
    switch (sort) {
        case 'b':
            return message.append(to_string(get_goals())).append(" buts");
        case 'm':
            return message.append(displayAv()).append(" buts/match");
        default :
            throw string("Error, this shouldn't have happened\n");
    }
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
