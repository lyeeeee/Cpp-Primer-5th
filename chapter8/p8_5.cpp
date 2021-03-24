#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

istream& func(string& fileName, vector<string>& v) {
    ifstream in(fileName);
    if (in) {
        string buf;
        while (in >> buf) {
            v.push_back(buf);
        }
    }
}

int main() {
    string fileName = "./p8_1.cpp";
    vector<string> v;
    func(fileName, v);
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }
}