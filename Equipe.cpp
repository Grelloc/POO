#include "Equipe.h"

    //_joueurs.size(); Pour savoir le nombre de joueurs dans l'equipe

Equipe::Equipe(const string n){
    _name = n;
    _victoires = 0;
    _defaites = 0;
    _nuls = 0;
    _butsMis = 0;
    _butsPris = 0;
}

void Equipe::free(){
    for (Joueur *j : _joueurs){
        delete j;
    }
}



int Equipe :: points(){
    return getvictoires()*3 + getnuls();
}

void Equipe :: add_player(Joueur * j){
    _joueurs.push_back(j);
}

const double Equipe::goalAverage(){
    return getbutsMis()/getbutsPris();
}


int Equipe::nmatch(){
    return getvictoires()+getdefaites()+getnuls();
}


const int Equipe::exist(string name){
    unsigned k=0;
    while (k<_joueurs.size() && name.compare(_joueurs[k]->getname()) ){
        k++;
    }
    return k<_joueurs.size();
}

void Equipe::aPris(int &n){
    _butsPris+=n;
}

void Equipe::aMis(int &n){
    _butsMis+=n;
}

void Equipe::victoire(){
    _victoires++;
}

void Equipe::defaite(){
    _defaites++;
}

void Equipe::nul(){
    _nuls++;
}

string Equipe::display() const{
    return _name;
}
