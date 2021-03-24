//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    const vector<string> scores = {"F","D","C","B","A","A++"};
    unsigned int score = 0;
    cin >> score;
    string grade;
    if (score < 60) {
        grade = scores[0];
    } else {
        grade = scores[(score-60)/10 + 1];
        if (score != 100) {
            int left = score/10;
            if (left < 3) {
                grade += "-";
            }
            if (left > 7) {
                grade += "+";
            }
        }
    }
    cout << grade << endl;
}
