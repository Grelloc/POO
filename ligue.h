#ifndef ligue_h
#define ligue_h
#include "journee.h"

class Ligue{
    private:
        vector<Journee> _journees;
    public:
        void add_journee(const Journee & j);
        void print();
};


#endif