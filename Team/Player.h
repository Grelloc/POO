#include <string>

#ifndef Player_h
#define Player_h

class Player {
private:
    std::string _name;
    std::string _team;
    int _goals;
    int _match;

public :
    Player(std::string name, std::string team);

    void aMarque();

    void havePlayed(const int &n);

    std::string get_team() const;

    int get_goals() const;

    int goalAverage() const;

    std::string get_name() const;

    std::string displayAv() const;

    std::string display(const char &sort) const;

    double get(const char &sort) const;
};


#endif