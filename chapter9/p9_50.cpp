#include <iostream>
#include <string>
#include <vector>
using namespace std;


int sum_int(vector<string>& v) {
    int i = 0;
    for (const string&s : v) {
        i += stoi(s);
    }
    return i;
}
int sum_float(vector<string>& v) {
    float i = 0;
    for (const string&s : v) {
        i += stof(s);
    }
    return i;
}
int main() {
    vector<std::string> v = { "1", "2", "3", "4.5" };
    cout << sum_int(v) << endl;
    cout << sum_float(v) << endl;
    return 0;
}