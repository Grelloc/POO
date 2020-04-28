#ifndef equipe_h
#define equipe_h
#include "Joueur.h"
using namespace std;

#define GetMacro(name, type) public :\
                                    const type get##name(){ \
                                        return _##name; \
                                    }\
                                    private:\
                                        type _##name;

class Equipe{
    GetMacro(name, string)
    GetMacro(butsPris, int)
    GetMacro(butsMis, int)
    GetMacro(victoires, int)
    GetMacro(defaites, int)
    GetMacro(nuls, int)
    private :
        vector<Joueur*> _joueurs;
    public :
        Equipe(const string name);
        void free();
        void add_player(Joueur * j);
        int points();
        const double goalAverage();
        const int exist(string name);
        void aPris(int &n);
        void aMis(int &n);
        void victoire();
        void defaite();
        void nul();
        int nmatch();
        string display() const;
};

#endif