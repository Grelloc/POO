#ifndef PlayerManager_h
#define PlayerManager_h

#include "../Team/Player.h"
#include "TeamManager.h"

using namespace std;

class PlayerManager {
private :
    vector<Player *> _player;
    static PlayerManager *_instance;

    PlayerManager();

    static bool CSC(const string &name);

    void _sort(const char &sort);

public :

    ~PlayerManager();

    static PlayerManager *getInstance();

    void add_player(Player *j);

    bool exist(const string &name) const;

    string display(int nDefined, unsigned n, int jDefined, char sort);

    Player *get_player(const string &name, const string &team) const;
};


#endif