#ifndef match_h
#define match_h

#include "../Equipe/Equipe.h"
#include "Buteur.h"

class Match {
private:
    int _number;
    Equipe *_equipeA;
    Equipe *_equipeB;
    vector<Buteur> _buteursA;
    vector<Buteur> _buteursB;
    int _scoreA;
    int _scoreB;

    string displayA() const;

    string displayB() const;

public:
    Match(int number, Equipe *equipeA, Equipe *equipeB, int scoreA, int scoreB) :
            _number(number), _equipeA(equipeA), _equipeB(equipeB), _scoreA(scoreA), _scoreB(scoreB) { gagne(); }

    void free();

    int getNumber() const;

    void gagne();

    void majScore();

    void add_buteurA(const Buteur &b);

    void add_buteurB(const Buteur &b);

    string display();
};

#endif