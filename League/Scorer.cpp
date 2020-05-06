#include "Scorer.h"

Scorer::Scorer(Player *j, int t) {
    _players = j;
    j->aMarque();
    _timer = t;
}

string Scorer::display() const {
    return _players->get_name().append("(").append(to_string(_timer)).append(")");
}

Player *Scorer::get_player() const {
    return _players;
}
