#ifndef joueursManager_h
#define joueursManager_h

#include "../Equipe/Joueur.h"

using namespace std;

class JoueursManager {
private :
    vector<Joueur *> _joueurs;
    static JoueursManager *_instance;

    JoueursManager();

public :
    static JoueursManager *getInstance();

    void trier(char sort);

    void add_player(Joueur *j);

    bool exist(const string &name) const;

    string display(int nDefined, unsigned n, char sort);
};


#endif