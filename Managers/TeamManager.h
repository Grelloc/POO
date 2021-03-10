#ifndef TeamManager_h
#define TeamManager_h

#include "../Team/Team.h"

class TeamManager {
private :
    std::vector<Team *> _equipes;
    static TeamManager *_instance;

    TeamManager();

    void _sort(const char &type);

public :
    ~TeamManager();

    TeamManager(TeamManager &other) = delete;

    void operator=(const TeamManager &other) = delete;

    static TeamManager *getInstance();

    void add_team(Team *e);

    std::string display(unsigned n, const char &sort);

    bool exist(const std::string &name) const;

    Team *get_team(const std::string &name) const;

    void update_players();
};

#endif