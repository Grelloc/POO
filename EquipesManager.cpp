#include "EquipesManager.h"

using namespace std;

EquipesManager* EquipesManager::_instance=nullptr;


EquipesManager::EquipesManager(){}

EquipesManager EquipesManagers::getInstance(){

}

void EquipesManager :: add_team(Equipe * e){
    _equipes.push_back(e);
}

void EquipesManager :: trier (char type){
    switch(type){
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
            sort(_equipes.begin(), _equipes.end(), [](Equipe *T, Equipe *T2){
                return T->getname()<T2->getname();
            }); 
            break;
    }
}

string EquipesManager :: display(int nDefined, unsigned n, char sort){
    string message;
    trier(sort); 
    message.append("Liste des equipes :\n");
    if (nDefined==0){
        for (Equipe *T : _equipes){
            message.append(" ").append(T->display());
        }
    }
    else{
        unsigned k = n<_equipes.size()? n : _equipes.size();
        for (unsigned i=0; i<k; i++){
            message.append(" ").append(_equipes[i]->display());
        }
    }
    message.append("\n");
    return message;
}

const int EquipesManager::exist(string name){
    unsigned k=0;
    while (k<_equipes.size() && name.compare(_equipes[k]->getname()) ){
        k++;
    }
    return k<_equipes.size();
}

