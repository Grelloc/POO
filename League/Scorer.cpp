#include "Scorer.h"

Scorer::Scorer(Player *j, int t) {
    _players = j;
    j->aMarque();
    _timer = t;
}

string Scorer::display() const {
    return _players->display().append("(").append(to_string(_timer)).append(")");
}

Player *Scorer::get_player() const {
    return _players;
}
