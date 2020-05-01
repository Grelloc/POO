#include "PlayerManager.h"

using namespace std;

PlayerManager *PlayerManager::_instance = nullptr;


PlayerManager::PlayerManager() = default;

PlayerManager::~PlayerManager() {
    delete _instance;
}


PlayerManager *PlayerManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new PlayerManager();
    }
    return _instance;
}

void PlayerManager::add_player(const Player &j) {
    _players.push_back(j);
}

void PlayerManager::_sort(const char &type) {
    switch (type) {
        case 'b':
            sort(_players.begin(), _players.end(), [](Player &P, Player &P2) {
                return P.get_goals() > P2.get_goals();
            });
            break;
        case 'm':
            TeamManager::getInstance()->update_players();
            sort(_players.begin(), _players.end(), [](Player &P, Player &P2) {
                return P.goalAverage() > P2.goalAverage();
            });
            break;
        default:
            sort(_players.begin(), _players.end(), [](Player &P, Player &P2) {
                return P.get_name() < P2.get_name();
            });
            break;
    }
}

string PlayerManager::display(int nDefined, unsigned n, int jDefined, char sort) {
    string message;
    _sort(sort);
    message.append("Liste des joueurs :\n");
    if (nDefined == 0 || n > _players.size()) {
        for (const Player &p : _players) {
            if (CSC(p.get_name())) {
                message.append(" ").append(p.display());
            }
        }
    } else {
        unsigned i;
        for (i = 0; i < n; i++) {
            if (CSC(_players[i].get_name())) {
                message.append(" ").append(_players[i].display());
            }
        }
        if (jDefined) {
            while (i < _players.size() && _players[n - 1].get(sort) == _players[i].get(sort)) {
                if (CSC(_players[i].get_name())) {
                    message.append(" ").append(_players[i].display());
                }
                i++;
            }
        }
    }
    message.append("\n");
    return message;
}

bool PlayerManager::exist(const string &name) const {
    for (const Player &player : _players) {
        if (player.get_name() == name) {
            return true;
        }
    }
    return false;
}

Player &PlayerManager::get_player(const string &name) {
    for (Player &player : _players) {
        if (player.get_name() == name) {
            return player;
        }
    };
    throw string ("player doesn't exist");
}

bool PlayerManager::CSC(const string &name) {
    return name.compare(0, 3, "CSC");
}


