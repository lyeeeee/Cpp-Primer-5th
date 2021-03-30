#include <iostream>
#include <regex>
#include <string>

int main()
{
	const std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
	std::regex re(pattern);

	std::smatch match;

	std::cout << "input some word:";
	std::string word;
	std::cin >> word;
	if (std::cin) {
		if (std::regex_search(word, match, re))
			std::cout << word <<  ": error" << std::endl;
		else {
			std::cout << word <<  ": correct" << std::endl;
		}

	}
	return 0;
}