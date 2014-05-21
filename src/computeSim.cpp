#include <iostream>
#include <string>
#include <map>
#include <set>
#include "NVMUtils.hpp"
using namespace std;

void help() {
    cout << "Usage ./prog <NVM fpath> <N> <outputfile>" << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        help();
        return -1;
    }
    string nvm_fname = argv[1];
    int N = stoi(argv[2]);
    string output_fname = argv[3];
    map<int, set<int> > vecs = readImgVecsFromNVM(nvm_fname);
    ofstream fout(output_fname.c_str(), ios::out);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float sim = computeSimilarity(vecs, i, j);
//            cout << i << " " << j << " " << sim << endl;
            fout << sim << " ";
        }
        fout << endl;
    }
    fout.close();
    return 0;
}
