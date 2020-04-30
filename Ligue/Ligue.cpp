#include "Ligue.h"

void Ligue::add_journee(const Journee &j) {
    _journees.push_back(j);
}

void Ligue::_sort() {
    sort(_journees.begin(), _journees.end(), [](Journee &j, Journee &j2) {
        return j.getNumber() < j2.getNumber();
    });
}

string Ligue::display() {
    _sort();
    string message = "Liste des matchs :\n\n";
    for (Journee &j : _journees) {
        message.append(j.display()).append("\n");
    }
    return message;
}