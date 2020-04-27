#ifndef equipesManager_h
#define equipesManager_h
#include "equipe.h"

class EquipesManager{
    private :
        vector<Equipe*> _equipes;
    public :
        void trier(char sort);
        void add_player(Equipe & e);
        void print();
        const int exist(string name);
};

#endif