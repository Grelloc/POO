#include "joueurs.h"
#include "equipes.h"
#include "ligue.h"


using namespace std;

#define USAGE() ( \
  cerr << "Usage: ./foot -d repertoire [-j buts|buts/match] [-e points|victoires|defaites|nuls|attaque|defense|goalaverage] [-n <nombre>]\n", \
  exit(1) \
)

int main (int argc, char* const argv[]){
    char opt, c;
    string j, e, d;
    int n=0, jDefined=0, eDefined=0, dDefined=0, nDefined =0;
    while ((opt = getopt(argc, argv, "d:j:e:n:")) != -1) {
        switch (opt) {
            case 'd':
            dDefined = 1;
            d = optarg;
            break;
        case 'j':
            jDefined = 1;
            j = optarg;
            break;
        case 'e':
            eDefined = 1;
            e = optarg;
            break;
        case 'n':
            n = atoi(optarg);
            nDefined = 1;
            break;
        default:
            USAGE();
            break;
        }
    }
    if (dDefined ==0){
        USAGE();
    }
    cout << j << endl  << e << endl  << d<< endl << n << endl;
}