#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void reverse_strings(std::vector<std::string>& Words) {
	for (auto it = Words.begin(); it != Words.end(); ++it) {
		std::reverse((*it).begin(), (*it).end());
	}
}

int main() {
	std::vector<std::string> Words = { "hello","world","c++" };
	for (auto it = Words.begin(); it != Words.end(); ++it) {
		std::string Word = *it;
		for (int i = 0; i < Word.length(); ++i) {
			std::cout << Word[i];
		}
		std::cout << std::endl;
	}
	reverse_strings(Words);
	for (auto it = Words.begin(); it != Words.end(); ++it) {
		std::string Word = *it;
		for (int i = 0; i < Word.length(); ++i) {
			std::cout << Word[i];
		}
		std::cout << std::endl;
	}
	return 0;
}