#ifndef TeamManager_h
#define TeamManager_h

#include "../Team/Team.h"

class TeamManager {
private :
    vector<Team *> _equipes;
    static TeamManager *_instance;

    TeamManager();

    void _sort(const char &type);

public :
    ~TeamManager();

    TeamManager(TeamManager &other) = delete;

    void operator=(const TeamManager &other) = delete;

    static TeamManager *getInstance();

    void add_team(Team *e);

    string display(int nDefined, unsigned n, int eDefined, char sort);

    bool exist(const string &name) const;

    Team *get_team(const string &name) const;

    void update_players();
};

#endif