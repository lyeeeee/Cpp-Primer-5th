#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string& s) {
    return true;
}

string& format(string& s) {
    return s;
}

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (auto& p : people) {
        ostringstream formatted, badNums;
        for (string& s : p.phones) {
            if(!valid(s)) {
                badNums << " " << s;
            } else {
                formatted << " " << format(s);
            }
        }
        if (badNums.str().empty()) {
            cout << p.name << ":" << formatted.str() << endl;
        } else {
            cerr << "error:" << p.name << " invalid numbers:" << badNums.str() << endl;
        }
    }
}