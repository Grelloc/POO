#ifndef Parse_h
#define Parse_h

#include "../Managers/EquipesManager.h"
#include "../Managers/JoueursManager.h"
#include "../Ligue/Ligue.h"

class Parser {
private:
    Ligue _ligue;
    EquipesManager _equipes;
    JoueursManager _joueurs;

    Parser();

    static void parse();

public:
    static Parser parseAllFile(string repertory) {
        parse();
    }

    Ligue getLigue();

    EquipesManager getEquipes();

    JoueursManager getJoueurs();

};


#endif