#include "JoueursManager.h"

using namespace std;

JoueursManager *JoueursManager::_instance = nullptr;


JoueursManager::JoueursManager() = default;


JoueursManager *JoueursManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new JoueursManager();
    }
    return _instance;
}

void JoueursManager::add_player(Joueur *j) {
    _joueurs.push_back(j);
}

void JoueursManager::trier(char type) {
    if (type == 'b') {
        sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2) {
            return P->buts() < P2->buts();
        });
    } else {
        sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2) {
            return P->getname() < P2->getname();
        });
    }
}

string JoueursManager::display(int nDefined, unsigned n, char sort) {
    string message;
    trier(sort);
    message.append("Liste des joueurs :\n");
    if (nDefined == 0) {
        for (Joueur *P : _joueurs) {
            message.append(" ").append(P->display());
        }
    } else {
        unsigned k = n < _joueurs.size() ? n : _joueurs.size();
        for (unsigned i = 0; i < k; i++) {
            message.append(" ").append(_joueurs[i]->display());
        }
    }
    message.append("\n");
    return message;
}

bool JoueursManager::exist(const string &name) const {
    for (const Joueur *j : _joueurs) {
        if (j->getname() == name) {
            return true;
        }
    }
    return false;
}

