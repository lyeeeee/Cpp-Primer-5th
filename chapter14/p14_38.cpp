#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

class InRange {
public:
    InRange(int t): threshold(t){}
    bool operator()(const string& s) {
        return s.size() == threshold;
    }

    size_t get_threshold() const { return threshold; }
private:
    size_t threshold;
};
int main(int argc, char* argv[]) {
    vector<InRange> comparator;

    vector<unsigned int> lens = {1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u};

    for_each(lens.begin(), lens.end(), [&comparator](unsigned int i) {comparator.push_back(InRange(i));});

    map<size_t, size_t> m;

    ifstream fin("./p14_16StrBlob.h");
    string s;
    while (fin) {
        fin >> s;
        for (auto c = comparator.begin(); c != comparator.end(); c++) {
            if ((*c)(s)) {
                if (m.find(c->get_threshold()) == m.end()) {
                    m[c->get_threshold()] = 0;
                }
                m[c->get_threshold()]++;
            }
        }
    }

    for (auto pair : m) {
        cout << pair.first << " " << pair.second << endl;
    }
}