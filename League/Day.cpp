#include <algorithm>
#include "Day.h"


void Day::add_match(const Match &m) {
    _matches.push_back(m);
}

int Day::getNumber() const {
    return _number;
}

void Day::_sort() {
    sort(_matches.begin(), _matches.end(), [](Match &M, Match &M2) {
        return M.getNumber() < M2.getNumber();
    });
}

string Day::display() {
    string message;
    _sort();
    for (Match m : _matches) {
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