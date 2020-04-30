#ifndef joueursManager_h
#define joueursManager_h

#include "../Equipe/Joueur.h"
#include "EquipesManager.h"

using namespace std;

class JoueursManager {
private :
    vector<Joueur *> _joueurs;
    static JoueursManager *_instance;

    JoueursManager();

    static bool CSC(const string &name);

    void _sort(const char &sort);

public :

    ~JoueursManager();

    static JoueursManager *getInstance();

    void add_player(Joueur *j);

    bool exist(const string &name) const;

    string display(int nDefined, unsigned n, int jDefined, char sort);

    Joueur *get_player(const string &name) const;
};


#endif