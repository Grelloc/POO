#include "Match.h"

int Match::getNumber() const {
    return _number;
}


void Match::add_scorerA(const Scorer &b) {
    _scorerA.push_back(b);
    _teamA->add_player(b.get_player());
}

void Match::add_scorerB(const Scorer &b) {
    _scorerB.push_back(b);
    _teamB->add_player(b.get_player());
}

void Match::Won() {
    if (_scoreA > _scoreB) {
        _teamA->victory();
        _teamB->defeat();
    } else if (_scoreA < _scoreB) {
        _teamA->defeat();
        _teamB->victory();
    } else {
        _teamA->nul();
        _teamB->nul();
    }
    updateScores();
}

void Match::updateScores() {
    _teamA->aMis(_scoreA);
    _teamA->aPris(_scoreB);
    _teamB->aMis(_scoreB);
    _teamB->aPris(_scoreA);
}

string Match::displayA() const {
    string message;
    if (!_scorerA.empty()) {
        message.append("\tButeur(s) ").append(_teamA->display()).append(" :");
        for (Scorer B : _scorerA) {
            message.append(" ").append(B.display());
        }
        message.append("\n");
    }
    return message;
}

string Match::displayB() const {
    string message;
    if (!_scorerB.empty()) {
        message.append("\tButeur(s) ").append(_teamB->display()).append(" :");
        for (Scorer B : _scorerB) {
            message.append(" ").append(B.display());
        }
        message.append("\n");
    }
    return message;
}

string Match::display() {
    return _teamA->display() + " " + to_string(_scoreA) + " - " + to_string(_scoreB) + " " + _teamB->display() +
           "\n" + displayA() + displayB();
}