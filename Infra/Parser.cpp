#include "Parser.h"

void Parser::parseAllFile(const string &repertory) {
    Ligue l;
    DIR *dirp = opendir(repertory.c_str());
    dirent *dp;
    while ((dp = readdir(dirp)) != nullptr) {
        l.add_journee(parseJournee(repertory+'/'+dp->d_name));
    }
    (void) closedir(dirp);
}

Match Parser::parseMatch(const string &line) {
    regex e("^\\w+ :");
    string recup;
    cmatch cm;
    regex_search(line.c_str(), cm, e);
    if (cm.size()!=0) {
        string str = cm[0];
        recup.append(str.substr(0, str.size()-1));
        
        Equipe *a = new Equipe(recup), *b = new Equipe("jsp");
        cout << a->display();
        return Match(0, a, b, 2, 1);
    }
    throw string ("fail to parse a team");

}

Journee Parser::parseJournee(const string &filename) {
    ifstream day(filename);
    if (day.is_open()) {
        Journee j (std::atoi(filename.substr(1,2).c_str()));
        string line;
        try {
            while (getline(day, line)) {
                j.add_match(parseMatch(line));
            }
        }catch(string){
            throw "fail to parse a team";
        }

        day.close();
        return j;
    }
    throw string ("Fail to open file " + filename);
}