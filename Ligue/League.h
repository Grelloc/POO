#ifndef League_h
#define League_h

#include "Day.h"

class League {
private:
    vector<Day> _days;

    void _sort();

public:

    void add_day(const Day &j);

    string display();
};


#endif