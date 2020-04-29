#ifndef joueur_h
#define joueur_h

#include <unistd.h>
#include <stdio.h>
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

public :
    Joueur(const string &n);

    void aMarque();

    string getname() const;

    int buts() const;

    string display() const;
};


#endif