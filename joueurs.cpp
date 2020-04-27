#include "joueurs.h"
using namespace std;


void JoueursManager :: add_player(Joueur & j){
    _joueurs.push_back(&j);
}

void JoueursManager :: trier (char type){
    switch(type){
        case 'a':
            sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2){
                return P->getname()<P2->getname();
            });  
            break;
        case 'b':
            sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2){
                return P->buts()<P2->buts();
            });  
            break;
        case 'm':
            sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2){
                return P->buts()/P->getmatch()<P2->buts()/P2->getmatch();
            });  
            break;
        default:
            break;
    }
}

void JoueursManager :: print(){
    trier('a'); 
    cout << "Liste des joueurs :" << endl;
    for (Joueur *P : _joueurs){
        cout << " ";
        P->print();
    }
    cout << endl;
}

const int JoueursManager::exist(string name){
    unsigned k=0;
    while (k<_joueurs.size() && name.compare(_joueurs[k]->getname()) ){
        k++;
    }
    return k<_joueurs.size();
}

