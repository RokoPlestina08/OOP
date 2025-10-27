#include <iostream>
#include <cstddef>

void sortt(int Niz[], std::size_t n, bool(*cmp)(int x, int y)) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (cmp(Niz[i], Niz[j])) {
				int temp = Niz[i];
				Niz[i] = Niz[j];
				Niz[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << Niz[i] << " ";
	}
	std::cout << std::endl;
}

bool Ascending(int a, int b) {
	return a > b;
}

bool Descending(int a, int b) {
	return a < b;
}


int main() {
	int Niz[] = { 1, 5, 8, 12, 3, 20 };

	sortt(Niz, 6, Ascending);
	sortt(Niz, 6, Descending);

	return 0;
}