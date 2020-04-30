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
    Parser() = default;

    static Journee parseJournee(const string &filename);

    static Match parseMatch(const string &line, const int &i);

    static string parseTeamAName(const string &line);

    static int parseTeamAScore(const string &line);

    static string parseTeamBName(const string &line);

    static int parseTeamBScore(string &line);

    static void parseTeamPlayers(string line, Match &m, const int &scoreA);

    static void noSpace(string &s);

    static int toNumber(string s);

    static string conventionName(string &s);

public:

    static Ligue parseAllFile(const string &depository);
};


#endif