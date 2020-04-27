#include "equipes.h"

using namespace std;


void EquipesManager :: add_player(Equipe & e){
    _equipes.push_back(&e);
}

void EquipesManager :: trier (char type){
    switch(type){
        case 'a':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getname()<T2->getname();
            });  
            break;
        case 'p':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->points()<T2->points();
            });  
            break;
        case 'v':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getvictoires()<T2->getvictoires();
            });  
            break;
        case 'd':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getdefaites()<T2->getdefaites();
            });  
            break;
        case 'n':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getnuls()<T2->getnuls();
            });  
            break;
        case 'm':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getbutsMis()<T2->getbutsMis();
            });  
            break;
        case 'e':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getbutsPris()<T2->getbutsPris();
            });  
            break;
        case 'g':
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->goalAverage()<T2->goalAverage();
            });  
            break;
        default:
            break;
    }
}

void EquipesManager :: print(){
    trier('a'); 
    cout << "Liste des equipes :" << endl;
    for (Equipe *T : _equipes){
        cout << " ";
        T->print();
    }
    cout << endl;
}

const int EquipesManager::exist(string name){
    unsigned k=0;
    while (k<_equipes.size() && name.compare(_equipes[k]->getname()) ){
        k++;
    }
    return k<_equipes.size();
}

