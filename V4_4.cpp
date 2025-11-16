#include <iostream>
#include <string>
#include <algorithm>

std::string word_to_pig_latin(const std::string& word) {
	char Vowels[] = {'a','e','i','o','u','A','E','I','O','U' };
	bool VowelFound = false;
	std::string NewWord = word;
	for(int i = 0 ; i < (NewWord.end() - NewWord.begin()); ++i) {
		if (Vowels[i] == word[0]) {
			NewWord.insert(NewWord.end() - NewWord.begin(), "hay");
			VowelFound = true;
			break;
		}
	}
	if (not VowelFound) {
		NewWord.erase(NewWord.begin());
		NewWord.push_back(word[0]);
		NewWord.insert(NewWord.end() - NewWord.begin(), "ay");
	}
	return NewWord;
}

int main() {
	std::string Word = "hello";
	std::string NewWord = word_to_pig_latin(Word);
	std::cout << NewWord;

	return 0;
}