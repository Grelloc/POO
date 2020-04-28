#include "Journee.h"

void Journee::free(){
    for (Match m : _matchs){
        m.free();
    }
}

void Journee::add_match(const Match & m){
    _matchs.push_back(m);
}

int Journee::getNumber() const{
    return _number;
}

string Journee::display() const {
    string message;
    for (Match m : _matchs) {
        message.append("Math ");
        int idJournee = getNumber();
        if (idJournee <= 9) {
            message.append("0");
        }
        message.append(to_string(idJournee)).append("_");

        int idMatch = m.getNumber();
        if (idMatch <= 9) {
            message.append("0");
        }
        message.append(to_string(idMatch + 1)).append(" : ");
        message.append(m.display());
    }
    return message;
}