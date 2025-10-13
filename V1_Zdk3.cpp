#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string s;
	std::cout << "Unesi string:" << std::endl;
	std::getline(std::cin, s);
	std::cout << "String je " << s << std::endl;
	for (char& i : s) {
		i = toupper(i);
		if (isdigit(i)) {
			i = '*';
		}
		if (i == '	')
			i = '_';
	}
	std::cout << s << std::endl;
}
