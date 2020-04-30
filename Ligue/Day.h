#ifndef Day_h
#define Day_h

#include "Match.h"

class Day {
private:
    int _number;
    vector<Match> _matches;

    void _sort();

public:

    Day(int n) : _number(n) {}

    void add_match(const Match &m);

    int getNumber() const;

    string display();
};

#endif