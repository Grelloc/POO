#include "League.h"

void League::add_day(const Day &j) {
    _days.push_back(j);
}

void League::_sort() {
    sort(_days.begin(), _days.end(), [](Day &j, Day &j2) {
        return j.getNumber() < j2.getNumber();
    });
}

string League::display() {
    _sort();
    string message = "Liste des matchs :\n\n";
    for (Day &j : _days) {
        message.append(j.display()).append("\n");
    }
    return message;
}