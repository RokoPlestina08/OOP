#include <iostream>
#include <algorithm>
#include <string>

void fix_spaces(std::string& text) {
	auto Search = text.begin();
	for (int i = 0; i < text.size(); ++i) {
		auto Find = std::find(Search, text.end(), ' ');
		if (Find != text.end()) {
			if (*(Find - 1) == ' ') {
				text.erase(Find);
				--Find;
			}
			else Search = Find + 1;
		}
		else break;
	}
	Search = text.begin();
	for (int i = 0; i < text.size(); ++i) {
		auto Find = std::find(Search, text.end(), ',');
		if (Find != text.end() && (Find + 1) != text.end()) {
			if (*(Find + 1) != ' ') {
				text.insert(Find - text.begin() + 1, " ");
				Search = Find + 1;
			}
			else Search = Find + 1;
		}
		else break;
	}
	Search = text.begin();
	for (int i = 0; i < text.size(); ++i) {
		auto Find = std::find(Search, text.end(), '.');
		if (Find != text.end()) {
			if (*(Find - 1) == ' ') {
				text.erase(Find - 1);
			}
			else Search = Find + 1;
		}
		else break;
	}
	for (int i = 0; i < text.size(); ++i) {
		std::cout << text[i];
	}
}

int main() {
	std::string Recenica = "Puno    razmaka    ,i tocka .";
	fix_spaces(Recenica);
	return 0;
}