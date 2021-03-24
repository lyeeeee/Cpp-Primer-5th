#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream in("./inputfile");
    if (!in.good()) {
        return -1;
    }
    string tmp;
    vector<string> vec;
    while (getline(in, tmp)) {
        vec.push_back(tmp);
    }
    
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        istringstream ins(*i);
        string tmp;
        while (ins >> tmp) {
            cout << tmp << endl;
        }
    }
}