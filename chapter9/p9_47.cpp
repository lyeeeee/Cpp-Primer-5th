#include <iostream>
#include <string.h>
using namespace std;


int main() {
    string s = "ab2c3d7R4E6";
    string digit("0123456789");
    string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string::size_type pos = 0;
    while ((pos = s.find_first_of(digit, pos)) != string::npos) {
        cout << s[pos++] << endl;
    }
    pos = 0;
    while ((pos = s.find_first_of(alpha, pos)) != string::npos) {
        cout << s[pos++] << endl;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(alpha, pos)) != string::npos) {
        cout << s[pos++] << endl;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(digit, pos)) != string::npos) {
        cout << s[pos++] << endl;
    }
    cout << s << endl;
}