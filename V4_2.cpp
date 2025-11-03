#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>&v) {
	int Broj = 1;
	while (Broj != 0) {
		std::cout << "Unesi broj" << std::endl;
		std::cin >> Broj;
		if (Broj != 0) v.push_back(Broj);
	}
}

void print_vector(const std::vector<int>&v) {	for (auto i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << " ";
	}}

std::vector<int> clearduplicates_vector(std::vector<int>&v) {
	std::vector<int> Noviv;
	std::sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		if (i == 0) {
			Noviv.push_back(v[i]);
		}
		else if(v[i] != v[i - 1]){
			Noviv.push_back(v[i]);
		}
	}
	return Noviv;
}

void SortNovi(std::vector<int>&v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i; j < v.size(); ++j) {
			if (v[i] > v[j]) {
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}

int main() {
	std::vector<int> Vektor;
	input_vector(Vektor);
	print_vector(Vektor);
	std::cout << std::endl;
	std::vector<int> NoviVektor = clearduplicates_vector(Vektor);
	print_vector(NoviVektor);
	SortNovi(NoviVektor);
	std::cout << std::endl;
	print_vector(NoviVektor);
	return 1;
}