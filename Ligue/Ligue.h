#ifndef ligue_h
#define ligue_h

#include "Journee.h"

class Ligue {
private:
    vector<Journee> _journees;

    void _sort();

public:

    void add_journee(const Journee &j);

    string display();
};


#endif