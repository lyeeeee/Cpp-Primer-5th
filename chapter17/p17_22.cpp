#include <iostream>
#include <regex>
#include <string>

using namespace std;
bool valid(const smatch &m) {
	if (m[1].matched) {
		return m[3].matched && (m[4].matched || m[4].str() == " ");
	} else {
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

int main()
{
	string phone = "(\\()?(\\d{3})([ _.])?([ ]*)?(\\d{3})([ _.])?([ ]*)?(\\d{4})";
	regex re(phone, regex::icase);

	string temp;
	while (getline(cin, temp)) {
		for (sregex_iterator it(temp.begin(), temp.end(), re), end_it; it != end_it; ++it) {
			if (valid(*it)) {
				cout << "valid:" << it->str() << endl;
			} else {
				cout << "valid:" << it->str() << endl;
			}
		}
	}
}