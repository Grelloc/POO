#ifndef journee_h
#define journee_h

#include "match.h"

class Journee{
    private:
        vector<Match> _matchs;
    public:
        void add_match(const Match & m);
        void print(int n);
};

#endif