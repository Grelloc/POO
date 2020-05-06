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
    string _team; //TODO
    int _goals=0;
    int _match=0;

public :
    Player(string n);

    void aMarque();

    void havePlayed(const int &n);

    string get_team() const; //TODO

    int get_goals() const;

    double goalAverage() const;

    string get_name() const;

    string display(const char &sort) const;

    double get(const char &sort) const;
};


#endif