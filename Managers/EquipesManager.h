#ifndef equipesManager_h
#define equipesManager_h

#include "../Equipe/Equipe.h"

class EquipesManager {
private :
    vector<Equipe *> _equipes;
    static EquipesManager *_instance;

    EquipesManager();

public :
    static EquipesManager* getInstance();

    void trier(char sort);

    void add_team(Equipe *e);

    string display(int nDefined, unsigned n, char sort);

    int exist(string name) const;
};

#endif