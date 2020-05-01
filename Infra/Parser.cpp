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
            l.add_day(parseDay(depository + '/' + dp->d_name));
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
        try {
            int k = 0;
            while (getline(day, line)) {
                j.add_match(parseMatch(line, k));
                k++;
            }
        } catch (string s) {
            cerr << s;
            throw "fail to parse a team";
        }

        day.close();
        return j;
    }
    throw string("Fail to open file " + filename);
}

Match Parser::parseMatch(string &line, const int &i) {
    string tA, tB;
    try {
        tA = parseTeamAName(line);
    } catch (string s) {
        cerr << s;
        throw string("Fail to parse Team A" + tA);
    }
    try {
        tB = parseTeamBName(line);
    } catch (string s) {
        cerr << s;
        throw string("Fail to parse Team B" + tB);
    }
    Team *a = TeamManager::getInstance()->get_team(tA);
    Team *b = TeamManager::getInstance()->get_team(tB);
    int scoreA = parseTeamAScore(line), scoreB = parseTeamBScore(line);
    Match m(i, a, b, scoreA, scoreB);
    if (scoreA > 0 || scoreB > 0) {
        parseTeamPlayers(line, m, scoreA);
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

string Parser::parseTeamAName(const string &line) {
    regex e(R"(^\s*\w+(-?)\w+\s*:)");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (!cm.empty()) {
        string str = cm[0];
        recup.append(str.substr(0, str.size() - 1));
        noSpace(recup);
        return recup;
    }
    throw string("fail to take a Team name");
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
    throw string("fail to take a Team name");
}


string Parser::parseTeamBName(const string &line) {
    regex e(R"(:\s*\w+(-?)\w+\s*)");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (!cm.empty()) {
        string str = cm[0];
        recup.append(str.substr(0, str.size() - 1));
        noSpace(recup);
        return recup;
    }
    throw string("fail to take a Team name");
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
    throw string("fail to take a Team name");
}


void Parser::parseTeamPlayers(string recup, Match &m, const int &scoreA) {
    PlayerManager *pManager = PlayerManager::getInstance();
    regex e(R"([A-Z]{1,3}(-[A-Z])?.\s*[a-zA-Z]+-?\w*\s*\d+)");
    smatch sm;
    int i = 0;
    while (regex_search(recup, sm, e)) {
        string str = sm[0];
        regex e_timer("\\d+");
        smatch timer;
        regex_search(str, timer, e_timer);

        regex e_player(R"([A-Z]{1,3}(-[A-Z])?.\s*[a-zA-Z]+-?\w*)");
        smatch player;
        regex_search(str, player, e_player);
        string temp = player[0];
        temp = conventionName(temp);
        if (i < scoreA) {
            Player &p(temp);
            if (pManager->exist(temp)) {
                p = pManager->get_player(temp);
            }else{
                pManager->add_player(p);
            }
            m.add_scorerA(Scorer(p, stoi(timer[0])));
        } else {
            Player *p = pManager->get_player(temp);
            m.add_scorerB(Scorer(p, stoi(timer[0])));
        }
        recup = sm.suffix().str();
        i++;
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