#include <iostream>

int main() {


	auto Parnost = [](int x) {return x % 2; };
	auto Mult = [](int x) {return x * 2; };
	auto Divide = [](int x) {return x / 2; };
	int Suma = 0;
	int Produkt = 1;
	auto Sum = [&](int x) { Suma += x; };
	auto Prod = [&](int x) { Produkt *= x; };
	int Prag = 3;
	auto Func = [Prag, &Suma](int x) {if (x > Prag) Suma += x; };
	
	int Niz[] = { 10, 15, 22, 31, 7 };

	auto Func1 = [&Parnost](int* Niz) {
		for (int i = 0; i < 5; ++i) {
			if (Parnost(Niz[i])) {
				Niz[i] *= 2;
			}
			else Niz[i] /= 2;
		}
		};
	
	auto Func2 = [&Sum, &Prod](int* Niz) {
		for (int i = 0; i < 5; ++i) {
			Sum(Niz[i]);
			Prod(Niz[i]);
		}
	};

	auto Func3 = [&Func](int* Niz) {
		for (int i = 0; i < 5; ++i) {
			Func(Niz[i]);
		}
	};

	Func1(Niz);
	Func2(Niz);
	Func3(Niz);

	return 0;
}