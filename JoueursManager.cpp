#include "JoueursManager.h"
using namespace std;


void JoueursManager :: add_player(Joueur * j){
    _joueurs.push_back(j);
}

void JoueursManager :: trier (char type){
    switch(type){
        case 'b':
            sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2){
                return P->buts()<P2->buts();
            });  
            break;
        default:
            sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2){
                return P->getname()<P2->getname();
            });  
            break;
    }
}

string JoueursManager :: display(int nDefined, unsigned n, char sort){
    string message;
    trier(sort);
    message.append("Liste des joueurs :\n");
    if (nDefined==0){  
        for (Joueur *P : _joueurs){
            message.append(" ").append(P->display());
        }
    }else{
        unsigned k = n<_joueurs.size()? n :  _joueurs.size();
        for (unsigned i=0; i<k; i++){
            message.append(" ").append(_joueurs[i]->display());
        }
    }
    message.append("\n");
    return message;
}

const int JoueursManager::exist(string name){
    unsigned k=0;
    while (k<_joueurs.size() && name.compare(_joueurs[k]->getname()) ){
        k++;
    }
    return k<_joueurs.size();
}

