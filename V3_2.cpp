#include <iostream>
#include <cstddef>

template<typename Type>
void sortt(Type Niz[], std::size_t n, bool(*cmp)(Type x, Type y)) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (cmp(Niz[i], Niz[j])) {
				Type temp = Niz[i];
				Niz[i] = Niz[j];
				Niz[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << std::fixed <<Niz[i] << " ";
	}
	std::cout << std::endl;
}

template<typename Type>
bool Ascending(Type a, Type b) {
	return a > b;
}

template<typename Type>
bool Descending(Type a, Type b) {
	return a < b;
}


int main() {
	int Niz[] = { 1, 5, 8, 12, 3, 20 };

	sortt(Niz, 6, Ascending);
	sortt(Niz, 6, Descending);

	double Niz2[] = { 2.45, 3.67 ,9.52 ,1.25 ,4.97 ,3.21 };
	sortt(Niz2, 6, Ascending);
	sortt(Niz2, 6, Descending);

	return 0;
}