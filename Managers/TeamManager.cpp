#include "TeamManager.h"

using namespace std;

TeamManager *TeamManager::_instance = nullptr;

TeamManager::TeamManager() = default;

TeamManager::~TeamManager() {
    for (Team *team : _equipes) {
        delete team;
    }
    _equipes.clear();
}

TeamManager *TeamManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new TeamManager();
    }
    return _instance;
}

void TeamManager::add_team(Team *e) {
    _equipes.push_back(e);
}

void TeamManager::_sort(const char &type) {
    switch (type) {
        case 'p':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->points() > T2->points();
            });
            break;
        case 'v':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->getvictoires() > T2->getvictoires();
            });
            break;
        case 'd':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->getdefaites() < T2->getdefaites();
            });
            break;
        case 'n':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->getnuls() > T2->getnuls();
            });
            break;
        case 'm':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->getbutsMis() > T2->getbutsMis();
            });
            break;
        case 'e':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->getbutsPris() < T2->getbutsPris();
            });
            break;
        case 'g':
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->goalAverage() > T2->goalAverage();
            });
            break;
        default:
            sort(_equipes.begin(), _equipes.end(), [](Team *T, Team *T2) {
                return T->getname() < T2->getname();
            });
            break;
    }
}

string TeamManager::display(int nDefined, unsigned n, int eDefined, char sort) {
    string message;
    _sort(sort);
    message.append("Liste des equipes :\n");
    if (nDefined == 0 || n > _equipes.size()) {
        for (Team *T : _equipes) {
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

void TeamManager::update_players() {
    for (Team *team : _equipes) {
        team->update_players();
    }
}

bool TeamManager::exist(const string &name) const {
    for (const Team *team : _equipes) {
        if (team->getname() == name) {
            return true;
        }
    }
    return false;
}

Team *TeamManager::get_team(const string &name) const {
    if (exist(name)) {
        for (Team *team : _equipes) {
            if (team->getname() == name) {
                return team;
            }
        }
    }
    auto *a = new Team(name);
    _instance->add_team(a);
    return a;
}