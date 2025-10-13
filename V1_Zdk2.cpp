#include <iostream>

int Function(int High, int Low, int Broj) {
	if (Broj < Low) {
		return Low;
	}
	else if (Broj > High) {
		return High;
	}
	else
		return Broj;
}

double Function(int High, int Low, double Broj) {
	if (Broj < Low) {
		return Low;
	}
	else if (Broj > High) {
		return High;
	}
	else
		return Broj;
}

int main() {
	int Broj1 = 25;
	double Broj2 = 4.4845;
	int High = 35;
	int Low = 5;
	std::cout << "Int funkcija: " << Function(High, Low, Broj1) << std::endl;
	std::cout << "Double funkcija: " << Function(High, Low, Broj2) << std::endl;

}