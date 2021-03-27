#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "p12_27.h"
#include <cstring>

using namespace std;

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream ifs("D:/develop/clionprojects/c++primer/chapter12/p12_27.h");
	runQueries(ifs);
	return 0;
}