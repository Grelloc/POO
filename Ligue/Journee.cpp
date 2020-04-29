#include "Journee.h"


void Journee::add_match(const Match &m) {
    _matchs.push_back(m);
}

int Journee::getNumber() const {
    return _number;
}

void Journee::_sort() {
    sort(_matchs.begin(), _matchs.end(), [](Match &M, Match &M2) {
        return M.getNumber() < M2.getNumber();
    });
}

string Journee::display() {
    string message;
    _sort();
    for (Match m : _matchs) {
        message.append("Math ");
        int idJournee = getNumber();
        if (idJournee < 9) {
            message.append("0");
        }
        message.append(to_string(idJournee)).append("_");

        int idMatch = m.getNumber();
        if (idMatch < 9) {
            message.append("0");
        }
        message.append(to_string(idMatch + 1)).append(" : ");
        message.append(m.display()).append("\n");
    }
    return message;
}