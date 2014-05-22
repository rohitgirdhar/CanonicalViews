/**
 * Note: The output is 0 indexed
 */

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

float alpha;

using namespace std;

void help() {
    cerr << "Usage: ./prog <sim file> <alpha> <output_file>" << endl;
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

float computeQ(set<int> &C, vector<vector<float> > &sim) {
    float mx_sum = 0;
    for (int img = 0; img < sim.size(); img++) {
        float mx = -9999.0f;
        for (auto iter = C.begin(); iter != C.end(); ++iter) {
            mx = max(sim[img][*iter], mx);
        }
        mx_sum += mx;
    }
    return mx_sum - alpha * C.size();
}

void print_set(set<int> C, string output_file) {
    ofstream fout(output_file.c_str(), ios::out);
    for (auto iter = C.begin(); iter != C.end(); ++iter) {
        fout << *iter << endl;
    }
    fout.close();
}

set<int> greedySelect(vector<vector<float> > &sim) {
    set<int> C; 
    float Q_v = 0;
    float cur_Q = 0;
    float Q_v_max = 0; 
    int Q_v_max_i = 0;
    do {
//        print_set(C);
        cout << Q_v_max << endl;
        Q_v_max = -9999.0f;
        for (int i = 0; i < sim.size(); i++) {
            if (C.count(i)) continue;
            set<int> temp = C;
            temp.insert(i);
            Q_v = computeQ(temp, sim) - cur_Q;
            if (Q_v > Q_v_max) {
                Q_v_max = Q_v;
                Q_v_max_i = i;
            }
        }
        if (Q_v_max > 0) {
            cur_Q += Q_v_max;
            C.insert(Q_v_max_i);
        }
    } while(Q_v_max > 0);
    return C;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        help();
        return -1;
    }
    string simFile = argv[1];
    alpha = stof(argv[2]);
    vector<vector<float> > sim = readSimFile(simFile);
    cout << "Read sims file " << endl;
    set<int> C = greedySelect(sim);
    print_set(C, argv[3]);
    return 0;
}
