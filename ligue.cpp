#include "ligue.h"

void Ligue::add_journee(const Journee & j){
    _journees.push_back(j);
}

void Ligue::print(){
    cout << "Liste des matchs :" << endl << endl;
    for (unsigned i=0; i<_journees.size(); i++){
        _journees[i].print(i+1);
    }
}