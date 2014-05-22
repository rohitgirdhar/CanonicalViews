/**
 * Note: The output is 0 indexed
 */

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

void help() {
    cerr << "Usage: ./prog <sim file> <K> <output_file>" << endl;
}

vector<vector<float> >
readSimFile(string fname) {
    vector<vector<float> > res;
    ifstream fin(fname.c_str());
    string line;
    float val;
    while (getline(fin, line)) {
        istringstream iss(line);
        vector<float> row;
        while (iss >> val) {
            row.push_back(val);
        }
        res.push_back(row);
    }
    fin.close();
    return res;
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

    float max_improvement = 0.0f;
    int max_improv_i = 0;
    for (int i = 0; i < K; i++) {
        max_improvement = 0.0f;
        for (int j = 0; j < N; j++) {
            if (C.count(j)) continue;
            float improv = 0;
            for (int k = 0; k < N; k++) {
                if (sim[j][k] - cur[k] > 0) {
                    improv += sim[j][k] - cur[k];
                }
            }
            if (improv > max_improvement) {
                max_improvement = improv;
                max_improv_i = j;
            }
        }
        if (max_improvement == 0) return C;
        C.insert(max_improv_i);
        for (int k = 0; k < N; k++) {
            cur[k] = max(cur[k], sim[max_improv_i][k]);
        }
        cerr << "i = " << i << " Improv: " << max_improvement << endl;
        cerr << "selected: " << max_improv_i << endl;
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
    set<int> C = greedySelect(sim, K);
    print_set(C, argv[3]);
    return 0;
}
