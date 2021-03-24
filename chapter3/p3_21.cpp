//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v3(10,42);
    vector<int> v2(10);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10,"hi"};
    cout << endl;
    for (auto i = v1.begin(); i != v1.end(); ++i) {
        cout << *i << endl;
    }
    cout << v1.size();
    cout << endl;
    for (auto i = v2.begin(); i != v2.end(); ++i) {
        cout << *i << endl;
    }
    cout << v2.size();
    cout << endl;
    for (auto i = v3.begin(); i != v3.end(); ++i) {
        cout << *i << endl;
    }
    cout << v3.size();
    cout << endl;
    for (auto i = v4.begin(); i != v4.end(); ++i) {
        cout << *i << endl;
    }
    cout << v4.size();
    cout << endl;
    for (auto i = v5.begin(); i != v5.end(); ++i) {
        cout << *i << endl;
    }
    cout << v5.size();
    cout << endl;
    for (auto i = v6.begin(); i != v6.end(); ++i) {
        cout << *i << endl;
    }
    cout << v6.size();
    cout << endl;
    for (auto i = v7.begin(); i != v7.end(); ++i) {
        cout << *i << endl;
    }
    cout << v7.size();
    cout << endl;
}
