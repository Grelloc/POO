#ifndef joueur_h
#define joueur_h

#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Joueur {
private:
    string _name;
    int _buts;
    int _match;

public :
    Joueur(const string &n);

    void aMarque();

    void aJoue(const int &n);

    int buts() const;

    double butsaverage() const;

    string getname() const;

    string display() const;

    double get(const char &sort) const;
};


#endif