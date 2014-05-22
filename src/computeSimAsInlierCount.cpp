#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


unsigned int FileRead( istream & is, vector <char> & buff ) {
    is.read( &buff[0], buff.size() );
    return is.gcount();
}

unsigned int CountLines( const vector <char> & buff, int sz ) {
    int newlines = 0;
    const char * p = &buff[0];
    for ( int i = 0; i < sz; i++ ) {
        if ( p[i] == '\n' ) {
            newlines++;
        }
    }
    return newlines;
}

unsigned int lineCount(string fname) {
    const int SZ = 1024;
    vector<char> buff(SZ);
    ifstream fin(fname);
    if (!fin) {
        return 0;
    }
    int n = 0;
    while (int cc = FileRead(fin, buff)) {
        n += CountLines(buff, cc);
    }
    fin.close();
    return n;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Use : ./prog <dir> <file with list of imgs> <output fpath>" << endl;
        return -1;
    }
    string dir = argv[1];
    string fpath = argv[2];
    string opath = argv[3];
    string line;
    vector<string> imgs_list;
    ifstream fin(fpath);
    while (getline(fin, line)) {
        imgs_list.push_back(line);
    }
    fin.close();
    int N = imgs_list.size();

    float **res = new float*[N]();
    for (int i = 0; i < N; i++) {
        res[i] = new float[N]();
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            res[i][j] = lineCount(dir + "/" + imgs_list[i] + "/matches_" + imgs_list[j] + ".txt");
        }
        cout << i << endl;
    }

    ofstream fout(opath.c_str(), ios::out);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fout << res[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}
