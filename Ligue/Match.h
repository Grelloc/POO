#ifndef match_h
#define match_h

#include "../Equipe/Team.h"
#include "Scorer.h"

class Match {
private:
    int _number;
    Team *_teamA;
    Team *_teamB;
    vector<Scorer> _scorerA;
    vector<Scorer> _scorerB;
    int _scoreA;
    int _scoreB;

    string displayA() const;

    string displayB() const;

public:
    Match(int number, Team *teamA, Team *teamB, int scoreA, int scoreB) :
            _number(number), _teamA(teamA), _teamB(teamB), _scoreA(scoreA), _scoreB(scoreB) { Won(); }

    int getNumber() const;

    void Won();

    void updateScores();

    void add_scorerA(const Scorer &b);

    void add_scorerB(const Scorer &b);

    string display();
};

#endif