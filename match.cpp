#include "match.h"


void Match :: add_playerA(Joueur & j, int t){
    Buteur b (j, t);
    _buteursA.push_back(b);
}

void Match :: add_playerB(Joueur & j, int t){
    Buteur b (j, t);
    _buteursB.push_back(b);
}

void Match::gagne(){
    if(_scoreA > _scoreB){
        _equipeA.victoire();
        _equipeB.defaite();
    }
    else if (_scoreA < _scoreB){
        _equipeA.defaite();
        _equipeB.victoire();
    }
    else{
        _equipeA.nul();
        _equipeB.nul();
    }
}

void Match::majScore(){
    _equipeA.aMis(_scoreA);
    _equipeA.aPris(_scoreB);
    _equipeB.aMis(_scoreB);
    _equipeB.aPris(_scoreA);
}

void Match::printA(){
    if (_buteursA.size()>0){
        cout << "\tButeur(s) ";
        _equipeA.print() ;
        cout << " :";
        for (Buteur B : _buteursA){
            cout << " ";
            B.print();
        }
        cout << endl;
    }
}

void Match::printB(){
    if (_buteursB.size()>0){
        cout << "\tButeur(s) ";
        _equipeB.print() ;
        cout << " :";
        for (Buteur B : _buteursB){
            cout << " ";
            B.print();
        }
        cout << endl;
    }
}

void Match::print(){
    _equipeA.print();
    cout << " " << _scoreA << " - " << _scoreB << " ";
    _equipeB.print();
    cout << endl;
    printA();
    printB();
}