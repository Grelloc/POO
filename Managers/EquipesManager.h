#ifndef equipesManager_h
#define equipesManager_h

#include "../Equipe/Equipe.h"

class EquipesManager {
private :
    vector<Equipe *> _equipes;
    static EquipesManager *_instance;

    EquipesManager();

    void _sort(const char &type);
public :
    ~EquipesManager();

    static EquipesManager *getInstance();

    void add_team(Equipe *e);

    string display(int nDefined, unsigned n, int eDefined, char sort);

    bool exist(const string &name) const;
    Equipe* get_team(const string &name) const;
};

#endif