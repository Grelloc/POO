#ifndef match_h
#define match_h
#include "equipe.h"
#include "buteur.h"

class Match{
    private:
        Equipe _equipeA;
        Equipe _equipeB;
        vector<Buteur> _buteursA;
        vector<Buteur> _buteursB;
        int _scoreA;
        int _scoreB;
        void printA();
        void printB();
    public:
        void gagne();
        void majScore();
        void add_playerA(Joueur & j, int t);
        void add_playerB(Joueur & j, int t);
        void print();
};

#endif