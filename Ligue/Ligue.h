#ifndef ligue_h
#define ligue_h

#include "Journee.h"

class Ligue {
private:
    vector<Journee> _journees;
public:
    void free();

    void add_journee(const Journee &j);

    string display() const;
};


#endif