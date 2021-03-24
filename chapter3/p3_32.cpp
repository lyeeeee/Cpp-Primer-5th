//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
//    int arr[10] = {};
//    for (int i = 0;i < 10; ++i) {
//        arr[i] = i;
//    }
//    int another[10] = {};
//    for (int i = 0;i < 10; ++i) {
//        another[i] = arr[i];
//    }
      vector<int> ivec(10);
      int idx = 0;
      for (auto i = ivec.begin(); i != ivec.end(); ++i) {
          *i = idx++;
      }
      vector<int> another(10);
      for (auto i = 0;i < ivec.size(); ++i) {
          another[i] = ivec[i];
      }
}
