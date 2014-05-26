/**
 * Note: The output is 0 indexed
 * Removes outliers
 */

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include "NVMUtils.hpp"

using namespace std;

void help() {
    cerr << "Usage: ./prog <sim file> <K> <output_file>" << endl;
}

void print_set(set<int> C, string output_file) {
    ofstream fout(output_file.c_str(), ios::out);
    for (auto iter = C.begin(); iter != C.end(); ++iter) {
        fout << *iter << endl;
    }
    fout.close();
}

set<int> greedySelect(vector<vector<float> > &sim, int K) {
    int N = sim.size();
    vector<float> cur(N, 0.0f);
    set<int> C;
    int is_in_set[1000000] = {0};

    float min_improvement = 999999999.0f;
    int min_improv_i = 0;
    for (int i = 0; i < K; i++) {
        min_improvement = 999999999.0f;
        for (int j = 0; j < N; j++) {
            if (is_in_set[j]) continue;
            float improv = 0;
            for (int k = 0; k < N; k++) {
                if (k == j) continue;
                if (is_in_set[k]) { // from the C set itself
        //            improv += sim[j][k];
                } else {
                    if (sim[j][k] - cur[k] > 0) {
                        improv += sim[j][k] - cur[k];
                    }
                }
            }
            if (improv < min_improvement) {
                min_improvement = improv;
                min_improv_i = j;
            }
        }
        C.insert(min_improv_i);
        is_in_set[min_improv_i] = 1;
        for (int k = 0; k < N; k++) {
            cur[k] = max(cur[k], sim[k][min_improv_i]);
        }
        cerr << "i = " << i << " Min Improv: " << min_improvement << endl;
        cerr << "removed: " << min_improv_i << endl;
    }
    return C;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        help();
        return -1;
    }
    string simFile = argv[1];
    int K = stoi(argv[2]);
    vector<vector<float> > sim = readSimFile(simFile);
    cout << "Read sims file " << endl;
    int N = sim.size();
    set<int> C = greedySelect(sim, N - K);
    set<int> antiC;
    for (int i = 0; i < N; i++) {
        if (!C.count(i)) antiC.insert(i);
    }
    print_set(antiC, argv[3]);
    return 0;
}
