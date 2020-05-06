#ifndef Team_h
#define Team_h

#include "Player.h"


using namespace std;

#define GetMacro(name, type) public :\
                                    type get##name() const{ \
                                        return _##name; \
                                    }\
                                    private:\
                                        type _##name;

class Team {
GetMacro(name, string)
GetMacro(butsPris, int)
GetMacro(butsMis, int)
GetMacro(victoires, int)
GetMacro(defaites, int)
GetMacro(nuls, int)
private :
    vector<Player *> _players;
public :
    explicit Team(const string &name);

    void add_player(Player *j);

    int points() const;

    double goalAverage() const;

    void aPris(int &n);

    void aMis(int &n);

    void victory();

    void defeat();

    void nul();

    int get_nMatch() const;

    void update_players();

    string display() const;

    double get(const char &sort) const;

    bool exist(const string &name) const;
};

#endif