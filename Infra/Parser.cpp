#include "Parser.h"

League Parser::parseAllFile(const string &depository) {
    vector<string> files;
    League l;
    DIR *dirp = opendir(depository.c_str());
    dirent *dp;
    int i = 0;
    while ((dp = readdir(dirp)) != nullptr) {
        string temp(dp->d_name);
        if (temp.substr(temp.find_last_of('.') + 1) == "txt") {
            try {
                l.add_day(parseDay(depository + '/' + dp->d_name));
            }
            catch (string s) {
                throw s;
            }
        }
        i++;
    }
    (void) closedir(dirp);
    return l;
}

Day Parser::parseDay(const string &filename) {
    ifstream day(filename);
    if (day.is_open()) {
        Day j(stoi(filename.substr(filename.size() - 6, filename.size() - 4)));
        string line;

        int k = 0;
        while (getline(day, line)) {
            try {
                j.add_match(parseMatch(line, k));
                k++;
            } catch (string s) {
                throw string(s + " in " + to_string(j.getNumber()) + "-" + to_string(k + 1) + '\n' + line);
            }
        }
        day.close();
        return j;
    }
    throw string("Fail to open file " + filename);
}

Match Parser::parseMatch(const string &toParse, const int &i) {
    string tA, tB, line = toParse;
    regex e(R"(^ *[a-zA-Z-]+ *: *[a-zA-Z-]+ *\d+ *- *\d+ *(([a-zA-Z-]+ *\. *[a-zA-Z-]+ *\d+ *\/?) *)*:? *(([a-zA-Z-]+ *\. *[a-zA-Z-]+ *\d+ *\/?) *)*$)");
    if (!regex_match(line, e)) {
        throw string("Forbidden line format");
    }
    try {
        tA = parseTeamAName(line);
    } catch (string s) {
        throw string(s);
    }
    try {
        tB = parseTeamBName(line);
    } catch (string s) {
        throw string(s);
    }
    Team *a = TeamManager::getInstance()->get_team(tA);
    Team *b = TeamManager::getInstance()->get_team(tB);
    int scoreA = parseTeamAScore(line), scoreB = parseTeamBScore(line);
    Match m(i, a, b, scoreA, scoreB);
    if (scoreA > 0 || scoreB > 0) {
        parseTeamPlayers(line, m, scoreA, scoreB);
    }
    return m;
}

void Parser::noSpace(string &s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    s.erase(remove(s.begin(), s.end(), ':'), s.end());
}

int Parser::toNumber(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    return stoi(s);
}

string Parser::parseTeamAName(string &line) {
    regex e(R"(:)");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (!cm.empty()) {
        recup = cm.prefix();
        noSpace(recup);
        line = cm.suffix();
        return recup;
    }
    throw string("Failed to take Team A name");
}

int Parser::parseTeamAScore(const string &line) {
    regex e("\\d+\\s*-");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (cm.size() != 0) {
        string str = cm[0];
        recup.append(str.substr(0, str.size() - 1));
        return toNumber(recup);
    }
    throw string("Failed to take Team A score");
}


string Parser::parseTeamBName(string &line) {
    regex e(R"(\w+(-?)\w+)");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (!cm.empty()) {
        string str = cm[0];
        recup.append(str);
        noSpace(recup);
        line = cm.suffix();
        return recup;
    }
    throw string("Failed to take Team B name");
}

int Parser::parseTeamBScore(string &line) {
    regex e("-\\s*\\d+");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (!cm.empty()) {
        string str = cm[0];
        recup.append(str.substr(1, str.size()));
        line = cm.suffix().str();
        return toNumber(recup);
    }
    throw string("Failed to take Team B score");
}


void Parser::parseTeamPlayers(string &line, Match &m, const int &scoreA, const int &scoreB) {
    if (scoreA > 0 || scoreB > 0) {
        regex e(R"(:)");
        smatch sm;
        regex_search(line, sm, e);
        if (sm.empty()) {
            throw string("Forbidden line format");
        } else {
            string scorerA(sm.prefix()), scorerB(sm.suffix());
            parseTeamAPlayers(scorerA, m, scoreA);
            parseTeamBPlayers(scorerB, m, scoreB);
        }
    }
}

void Parser::parseTeamAPlayers(string &scorerA, Match &m, const int &scoreA) {
    regex e(R"([A-Z]{1,3}(-[A-Z])?.\s*[a-zA-Z]+-?[a-zA-Z]*\s*\d+)");
    smatch sm;
    int i = 0;
    while (regex_search(scorerA, sm, e)) {
        string str = sm[0];
        regex e_timer("\\d+");
        smatch timer;
        regex_search(str, timer, e_timer);

        regex e_player(R"([A-Z]{1,3}(-[A-Z])?.\s*[a-zA-Z]+-?\w*)");
        smatch player;
        regex_search(str, player, e_player);
        string temp = player[0];
        temp = conventionName(temp);
        Player *p = PlayerManager::getInstance()->get_player(temp, m.getTeamA().getname());
        m.add_scorerA(Scorer(p, stoi(timer[0])));
        scorerA = sm.suffix().str();
        i++;
    }
    if (i != scoreA) {
        throw string("Bad number of player in team A");
    }
}

void Parser::parseTeamBPlayers(string &scorerB, Match &m, const int &scoreB) {
    regex e(R"([A-Z]{1,3}(-[A-Z])?.\s*[a-zA-Z]+-?[a-zA-Z]*\s*\d+)");
    smatch sm;
    int i = 0;
    while (regex_search(scorerB, sm, e)) {
        string str = sm[0];
        regex e_timer("\\d+");
        smatch timer;
        regex_search(str, timer, e_timer);

        regex e_player(R"([A-Z]{1,3}(-[A-Z])?.\s*[a-zA-Z]+-?\w*)");
        smatch player;
        regex_search(str, player, e_player);
        string temp = player[0];
        temp = conventionName(temp);
        Player *p = PlayerManager::getInstance()->get_player(temp, m.getTeamB().getname());
        m.add_scorerB(Scorer(p, stoi(timer[0])));
        scorerB = sm.suffix().str();
        i++;
    }
    if (i != scoreB) {
        throw string("Bad number of player in team B");
    }
}

string Parser::conventionName(string &s) {
    noSpace(s);
    unsigned i = 0;
    while (i < s.size() - 1 && s[i] != '.') {
        i++;
    }
    s.insert(i + 1, " ");
    return s;
}