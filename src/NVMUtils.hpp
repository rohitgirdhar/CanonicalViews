#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

map<int, set<int> >
readImgVecsFromNVM(string fpath) {
    map<int, set<int> > res;
    ifstream fin(fpath.c_str());
    string line;
    getline(fin, line); getline(fin, line); // ignore
    getline(fin, line);
    int nimgs = stoi(line);
    while(nimgs--) getline(fin, line);
    getline(fin, line);
    
    getline(fin, line);
    int npts = stoi(line);
    cerr << npts << " total feature points" << endl;
    float temp;
    for (int ftrID = 0; ftrID < npts; ftrID++) {
        fin >> temp >> temp >> temp;
        fin >> temp >> temp >> temp;
        int num_imgs;
        fin >> num_imgs;
        while (num_imgs--) {
            int img_idx;
            fin >> img_idx >> temp >> temp >> temp;
            if (res.count(img_idx) <= 0) {
                res[img_idx] = set<int>();
            }
            res[img_idx].insert(ftrID);
        }
    }
    fin.close();
    return res;
}

void printVecs(map<int, set<int> > vecs) {
    for (auto iter = vecs.begin(); iter != vecs.end(); ++iter) {
        cout << "Image ID: " << iter->first << endl;
        set<int> ftr_pts = iter->second;
        for (auto iter2 = ftr_pts.begin(); iter2 != ftr_pts.end(); ++iter2) {
            cout << " " << *iter2 << endl;
        }
    }
}
