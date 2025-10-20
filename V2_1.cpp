#include <iostream>

int* Func(int &n) {
	int* niz = new int[n] {1, 1};
	for (int i = 2; i < n; ++i) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

void main() {
	std::cout << "Unesi n: " << std::endl;
	int n;
	std::cin >> n;
	int* niz = Func(n);
	for (int i = 0; i < n; ++i) {
		std::cout << niz[i] << " ";
	}
	delete[] niz;
}