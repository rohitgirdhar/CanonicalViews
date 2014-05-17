#include <iostream>
#include <string>
#include <map>
#include <set>
#include "NVMUtils.hpp"
using namespace std;

void help() {
    cout << "Usage ./prog <NVM fpath>" << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        help();
        return -1;
    }
    string nvm_fname = argv[1];
    map<int, set<int> > vecs = readImgVecsFromNVM(nvm_fname);
    return 0;
}
