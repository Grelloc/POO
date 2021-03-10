#include "Player.h"
#include <vector>

#ifndef Team_h
#define Team_h


#define GetMacro(name, type) public :\
                                    type get##name() const{ \
                                        return _##name; \
                                    }\
                                    private:\
                                        type _##name;

class Team {
GetMacro(name, std::string)
GetMacro(butsPris, int)
GetMacro(butsMis, int)
GetMacro(victoires, int)
GetMacro(defaites, int)
GetMacro(nuls, int)
private :
    std::vector<Player *> _players;
public :
    Team(const std::string &name);

    void add_player(Player *j);

    int points() const;

    int goalAverage() const;

    void aPris(int &n);

    void aMis(int &n);

    void victory();

    void defeat();

    void nul();

    int get_nMatch() const;

    void update_players();

    std::string display(const char &sort) const;

    std::string setSpace(int n) const;

    int get(const char &sort) const;

    bool exist(const std::string &name) const;

};

#endif