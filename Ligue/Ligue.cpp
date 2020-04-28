#include "Ligue.h"

void Ligue::free() {
    for (Journee j : _journees) {
        j.free();
    }
}

void Ligue::add_journee(const Journee &j) {
    _journees.push_back(j);
}

string Ligue::display() const {
    string message = "Liste des matchs :\n\n";
    for (Journee j : _journees) {
        message.append(j.display());
    }
    return message;
}