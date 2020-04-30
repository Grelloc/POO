#ifndef Player_h
#define Player_h

#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Player {
private:
    string _name;
    int _goals;
    int _match;

public :
    Player(const string &n);

    void aMarque();

    void havePlayed(const int &n);

    int get_goals() const;

    double goalAverage() const;

    string get_name() const;

    string display() const;

    double get(const char &sort) const;
};


#endif