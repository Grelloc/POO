#include "Ligue/League.h"
#include "Infra/Parser.h"


using namespace std;

#define USAGE() ( \
  cerr << "Usage: ./foot -d repertoire [-j buts|buts/match] [-e points|victoires|defaites|nuls|attaque|defense|goalaverage] [-n <nombre>]\n", \
  exit(1) \
)

char eArgument(string e) {
    if (e.compare("points")) {
        return 'p';
    }
    if (e.compare("victoires")) {
        return 'v';
    }
    if (e.compare("defaites")) {
        return 'd';
    }
    if (e.compare("nuls")) {
        return 'n';
    }
    if (e.compare("attaque")) {
        return 'm';
    }
    if (e.compare("defense")) {
        return 'e';
    }
    if (e.compare("goalaverage")) {
        return 'g';
    }
    USAGE();
}

char jArgument(string j) {
    if (j == "get_goals") {
        return 'b';
    }
    if (j == "buts/match") {
        return 'm';
    }
    USAGE();
}

int main(int argc, char *const argv[]) {
    League L;
    char opt, j, e;
    char *depository;
    unsigned n = 0;
    int temp = 0;
    bool dDefined = false, nDefined = false, jDefined = false, eDefined = false;
    while ((opt = getopt(argc, argv, "d:j:e:n:")) != -1) {
        switch (opt) {
            case 'd':
                dDefined = true;
                depository = optarg;
                break;
            case 'j':
                j = jArgument(optarg);
                jDefined = true;
                break;
            case 'e':
                e = eArgument(optarg);
                eDefined = true;
                break;
            case 'n':
                temp = atoi(optarg);
                if (temp < 0) {
                    USAGE();
                } else {
                    n = temp;
                }
                nDefined = true;
                break;
            default:
                USAGE();
                break;
        }
    }
    if (!dDefined) {
        USAGE();
    }
    L = Parser::parseAllFile(depository);
    cout << PlayerManager::getInstance()->display(nDefined, n, jDefined, j)
         << TeamManager::getInstance()->display(nDefined, n, eDefined, e) << L.display();
}