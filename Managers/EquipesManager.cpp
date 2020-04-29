#include "EquipesManager.h"

using namespace std;

EquipesManager *EquipesManager::_instance = nullptr;


EquipesManager::EquipesManager() = default;

EquipesManager::~EquipesManager() {
    for (Equipe *team : _equipes){
        delete team;
    }
}


EquipesManager *EquipesManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new EquipesManager();
    }
    return _instance;
}

void EquipesManager::add_team(Equipe *e) {
    _equipes.push_back(e);
}

void EquipesManager::_sort(const char &type) {
    switch (type) {
        case 'p':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->points() > T2->points();
            });
            break;
        case 'v':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->getvictoires() > T2->getvictoires();
            });
            break;
        case 'd':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->getdefaites() < T2->getdefaites();
            });
            break;
        case 'n':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->getnuls() > T2->getnuls();
            });
            break;
        case 'm':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->getbutsMis() > T2->getbutsMis();
            });
            break;
        case 'e':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->getbutsPris() < T2->getbutsPris();
            });
            break;
        case 'g':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->goalAverage() > T2->goalAverage();
            });
            break;
        default:
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2) {
                return T->getname() < T2->getname();
            });
            break;
    }
}

string EquipesManager::display(int nDefined, unsigned n, int eDefined, char sort) {
    string message;
    _sort(sort);
    message.append("Liste des equipes :\n");
    if (nDefined == 0 || n > _equipes.size()) {
        for (Equipe *T : _equipes) {
            message.append(" ").append(T->display());
        }
    } else {
        unsigned i;
        for (i = 0; i < n; i++) {
            message.append(" ").append(_equipes[i]->display());
        }
        if (eDefined) {
            while (i < _equipes.size() && _equipes[n - 1]->get(sort) == _equipes[i]->get(sort)) {
                message.append(" ").append(_equipes[i]->display());
                i++;
            }
        }
    }
    message.append("\n");
    return message;
}

bool EquipesManager::exist(const string &name) const {
    for (const Equipe *team : _equipes) {
        if (team->getname() == name) {
            return true;
        }
    }
    return false;
}

Equipe *EquipesManager::get_team(const string &name) const {
    if (exist(name)) {
        for (Equipe *team : _equipes) {
            if (team->getname() == name) {
                return team;
            }
        }
    } else {
        auto *a = new Equipe(name);
        _instance->add_team(a);
        return a;
    }
}
