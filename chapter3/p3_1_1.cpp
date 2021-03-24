#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	for (int val = 1; val <= 10; ++val) {
        sum += val;
    } 

	cout << sum << endl;
	
	return 0;
}