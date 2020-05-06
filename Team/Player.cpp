#include "Player.h"

#include <utility>

using namespace std;

Player::Player(string n): _name(std::move(n)){}

int Player::get_goals() const {
    return _goals;
}

string Player::get_team() const{
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
    string message(get_name() + ' ' + get_team() + "\n\t\t\t\t\t\t");
    if (sort == 'b') {
        message.append(to_string(get_goals()));
    } else if (sort == 'm') {
        message.append(to_string(goalAverage()));

    }
 	 
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
