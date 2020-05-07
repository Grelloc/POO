#ifndef Parse_h
#define Parse_h

#include <dirent.h>
#include <fstream>
#include <regex>
#include "../Managers/TeamManager.h"
#include "../Managers/PlayerManager.h"
#include "../League/League.h"

using namespace std;

class Parser {
private:
    Parser() = default;

    static Day parseDay(const string &filename);

    static Match parseMatch(const string &toParse, const int &i);

    static string parseTeamAName(string &line);

    static int parseTeamAScore(const string &line);

    static string parseTeamBName(string &line);

    static int parseTeamBScore(string &line);

    static void parseTeamPlayers(string &line, Match &m, const int &scoreA, const int &scoreB);

    static void parseTeamAPlayers(string &scorerA, Match &m, const int &scoreA);

    static void parseTeamBPlayers(string &scorerB, Match &m, const int &scoreB);

    static void noSpace(string &s);

    static int toNumber(string s);

    static string conventionName(string &s);

public:

    static League parseAllFile(const string &depository);
};


#endif