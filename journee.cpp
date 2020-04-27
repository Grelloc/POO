#include "journee.h"

void Journee::add_match(const Match& m){
    _matchs.push_back(m);
}

void Journee::print(int n){
    for (unsigned i=0; i<_matchs.size(); i++){
        cout << "Match ";
        n>9? cout << n : cout << "0"<<n;
        cout << "_";
        i+1>9? cout << i+1 : cout << "0" << i+1;
        cout << " : ";
        _matchs[i].print();
    }
}