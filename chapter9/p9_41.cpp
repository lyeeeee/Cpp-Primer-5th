#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;


int main() {
     vector<char> v{ 'h', 'e', 'l', 'l', 'o' };
    string str(v.cbegin(), v.cend());
    cout << str << endl;
}