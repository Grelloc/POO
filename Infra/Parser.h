#ifndef Parse_h
#define Parse_h

#include <dirent.h>
#include <fstream>
#include <regex>
#include "../Managers/EquipesManager.h"
#include "../Managers/JoueursManager.h"
#include "../Ligue/Ligue.h"

using namespace std;

class Parser {
private:
    Ligue _ligue;

    Parser()=default;

    static Journee parseJournee(const string &filename);
    static Match parseMatch (const string &line);

public:
    static void parseAllFile(const string &repertory);
};


#endif