#include <iostream>
#include <vector>

void input_vector(std::vector<int>&v) {
	int Broj = 1;
	while (Broj != 0) {
		std::cout << "Unesi broj" << std::endl;
		std::cin >> Broj;
		if(Broj != 0) v.push_back(Broj);
	}
}

void print_vector(const std::vector<int>& v) {	for (auto i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << " ";
	}}

int main() {
	std::vector<int> Vektor;
	input_vector(Vektor);
	print_vector(Vektor);
	return 0;
}