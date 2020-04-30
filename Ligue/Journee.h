#ifndef journee_h
#define journee_h

#include "Match.h"

class Journee {
private:
    int _number;
    vector<Match> _matchs;

    void _sort();

public:

    Journee(int n) : _number(n) {}

    void add_match(const Match &m);

    int getNumber() const;

    string display();
};

#endif