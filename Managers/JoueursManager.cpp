#include "JoueursManager.h"

using namespace std;

JoueursManager *JoueursManager::_instance = nullptr;


JoueursManager::JoueursManager() = default;

JoueursManager::~JoueursManager(){
    for (Joueur *player : _joueurs){
        delete player;
    }
    delete _instance;
}


JoueursManager *JoueursManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new JoueursManager();
    }
    return _instance;
}

void JoueursManager::add_player(Joueur *j) {
    _joueurs.push_back(j);
}

void JoueursManager::_sort(const char &type) {
    if (type == 'b') {
        sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2) {
            return P->buts() > P2->buts();
        });
    } else {
        sort(_joueurs.begin(), _joueurs.end(), [](Joueur *P, Joueur *P2) {
            return P->getname() < P2->getname();
        });
    }
}

string JoueursManager::display(int nDefined, unsigned n,int jDefined , char sort) {
    string message;
    _sort(sort);
    message.append("Liste des joueurs :\n");
    if (nDefined == 0 || n > _joueurs.size()) {
        for (Joueur *p : _joueurs) {
            message.append(" ").append(p->display());
        }
    } else {
        unsigned i;
        for (i = 0; i < n; i++) {
            message.append(" ").append(_joueurs[i]->display());
        }
        if (jDefined) {
            while (i < _joueurs.size() && _joueurs[n - 1]->get(sort) == _joueurs[i]->get(sort)) {
                message.append(" ").append(_joueurs[i]->display());
                i++;
            }
        }
    }
    message.append("\n");
    return message;
}

bool JoueursManager::exist(const string &name) const {
    for (const Joueur *player : _joueurs) {
        if (player->getname() == name) {
            return true;
        }
    }
    return false;
}

Joueur *JoueursManager::get_player(const string &name) const {
    if (exist(name)) {
        for (Joueur *player : _joueurs) {
            if (player->getname() == name) {
                return player;
            }
        }
    } else {
        auto *j = new Joueur(name);
        if (CSC(name)) {
            _instance->add_player(j);
        }
        return j;
    }
}

bool JoueursManager::CSC(const string &name) {
    return name.compare(0, 3, "CSC");
}
