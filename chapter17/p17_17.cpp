#include <iostream>
#include <regex>
#include <string>

int main()
{
	const std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
	std::regex re(pattern, std::regex::icase);

	std::smatch match;

	std::cout << "input some text:";
	std::string word;
	getline(std::cin, word);
	if (std::cin) {
		for (std::sregex_iterator it(word.begin(), word.end(), re), end_it; it != end_it; ++it) {
			std::cout << it->str() << std::endl;
		}
	}
	return 0;
}