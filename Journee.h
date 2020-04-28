#ifndef journee_h
#define journee_h

#include "Match.h"

class Journee{
    private:
        vector<Match> _matchs;
        int _number;
    public:
        Journee(int n):_number(n){}
        void free();
        void add_match(const Match & m);
        int getNumber() const;
        string display() const;
};

#endif