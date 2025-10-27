#include <iostream>

int main() {


	auto Parnost = [](int x) {return x % 2; };
	auto Mult = [](int x) {return x * 2; };
	auto Divide = [](int x) {return x / 2; };
	auto Sum = [&](int Suma, int x) { Suma += x; };
	auto Prod = [&](int Prod, int x) {Prod *= x; };
	int s = 15;
	int Prag = 3;
	auto Func = [Prag, &s](int x) {if (x > Prag) s += x; };
	
	int Niz[] = { 10, 15, 22, 31, 7 };
	int Suma = 0;
	int Prod = 0;
	for (int i = 0; i < 5; ++i) {
		if(Parnost(Niz[i])) {
			Niz[i] *= 2;
		}
		else Niz[i] /= 2;
	}

	return 0;
}