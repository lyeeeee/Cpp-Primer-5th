#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "../chapter7/p7_41.h"
using namespace std;




int main () {
    int i = 10;
	auto f = [&i](){
		if(i <= 0) 
			return true; 
		else {
			i--; 
			return false;
		}
	};
	while (f());
	return 0;
}