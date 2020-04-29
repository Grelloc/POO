#include "Match.h"

int Match::getNumber() const {
    return _number;
}


void Match::add_buteurA(const Buteur &b) {
    _buteursA.push_back(b);
}

void Match::add_buteurB(const Buteur &b) {
    _buteursB.push_back(b);
}

void Match::gagne() {
    if (_scoreA > _scoreB) {
        _equipeA->victoire();
        _equipeB->defaite();
    } else if (_scoreA < _scoreB) {
        _equipeA->defaite();
        _equipeB->victoire();
    } else {
        _equipeA->nul();
        _equipeB->nul();
    }
    majScore();
}

void Match::majScore() {
    _equipeA->aMis(_scoreA);
    _equipeA->aPris(_scoreB);
    _equipeB->aMis(_scoreB);
    _equipeB->aPris(_scoreA);
}

string Match::displayA() const {
    string message;
    if (!_buteursA.empty()) {
        message.append("\tButeur(s) ").append(_equipeA->display()).append(" :");
        for (Buteur B : _buteursA) {
            message.append(" ").append(B.display());
        }
        message.append("\n");
    }
    return message;
}

string Match::displayB() const {
    string message;
    if (!_buteursB.empty()) {
        message.append("\tButeur(s) ").append(_equipeB->display()).append(" :");
        for (Buteur B : _buteursB) {
            message.append(" ").append(B.display());
        }
        message.append("\n");
    }
    return message;
}

string Match::display() {
    return _equipeA->display() + " " + to_string(_scoreA) + " - " + to_string(_scoreB) + " " + _equipeB->display() +
           "\n" + displayA() + displayB();
}