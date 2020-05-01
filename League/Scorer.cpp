#include "Scorer.h"

Scorer::Scorer(Player &j, int t) :
        _player(j), _timer(t) {
    j.aMarque();
}

string Scorer::display() const {
    return _player.display().append("(").append(to_string(_timer)).append(")");
}

Player &Scorer::get_player() {
    return _player;
}
