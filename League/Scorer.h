#ifndef Scorer_h
#define Scorer_h

#include "../Team/Player.h"

using namespace std;

class Scorer {
private:
    Player *_players;
    int _timer;
public:
    Scorer(Player *j, int t);

    Player *get_player() const;

    string display() const;
};


#endif