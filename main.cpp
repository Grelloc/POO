#include "Managers/JoueursManager.h"
#include "Managers/EquipesManager.h"
#include "Ligue/Ligue.h"
#include "Infra/Parser.h"


using namespace std;

#define USAGE() ( \
  cerr << "Usage: ./foot -d repertoire [-j buts] [-e points|victoires|defaites|nuls|attaque|defense|goalaverage] [-n <nombre>]\n", \
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
    if (j.compare("buts")) {
        return 'b';
    }
    USAGE();
}


Ligue pourLesTest(int n) {
    Joueur *j1 = new Joueur("didier"), *j2 = new Joueur("le"), *j3 = new Joueur("le"), *j4 = new Joueur("luck");
    Buteur b1(j1, 10), b2(j2, 20), b3(j3, 30), b4(j4, 30);
    Equipe *A = new Equipe("Monaco"), *B = new Equipe("OM");
    Match m(1, A, B, 3, 1);
    Journee J(n);
    Ligue L;
    m.add_buteurA(b1);
    m.add_buteurA(b2);
    m.add_buteurB(b3);
    m.add_buteurA(b4);
    A->add_player(j1);
    A->add_player(j2);
    A->add_player(j4);
    B->add_player(j3);
    JoueursManager::getInstance()->add_player(j1);
    JoueursManager::getInstance()->add_player(j2);
    JoueursManager::getInstance()->add_player(j3);
    JoueursManager::getInstance()->add_player(j4);
    J.add_match(m);
    L.add_journee(J);
    EquipesManager::getInstance()->add_team(A);
    EquipesManager::getInstance()->add_team(B);
    return L;
}

int main(int argc, char *const argv[]) {
    Ligue L;
    char opt, c, j, e;
    string d;
    unsigned n = 0;
    int temp = 0, dDefined = 0, nDefined = 0;
    while ((opt = getopt(argc, argv, "d:j:e:n:")) != -1) {
        switch (opt) {
            case 'd':
                dDefined = 1;
                d = optarg;
                break;
            case 'j':
                j = jArgument(optarg);
                break;
            case 'e':
                e = eArgument(optarg);
                break;
            case 'n':
                temp = atoi(optarg);
                if (temp < 0) {
                    USAGE();
                } else {
                    n = temp;
                }
                nDefined = 1;
                break;
            default:
                USAGE();
                break;
        }
    }
    if (dDefined == 0) {
        USAGE();
    }
    //lance le parse avec d
    //recup les resultats
    //et les traite
    L = pourLesTest(10);
    cout << L.display() << endl << EquipesManager::getInstance()->display(nDefined, n, e) << endl << JoueursManager::getInstance()->display(nDefined, n, j);
    L.free();
}