#include <iostream>

struct Vector {
	int LogVelicina = 3;
	int FizVelicina = 0;
	int* Niz = new int[3];
};

auto vector_new(int n) {
	Vector NoviVektor;
	int IndexNiza = 0;
	for (; IndexNiza < n; ++IndexNiza) {
		if (IndexNiza == NoviVektor.LogVelicina) {
			int *VeciNiz = new int[NoviVektor.LogVelicina * 2]();
			for (int i = 0; i < NoviVektor.LogVelicina; ++i) {
				VeciNiz[i] = NoviVektor.Niz[i];
			}
			delete[] NoviVektor.Niz;
			NoviVektor.Niz = VeciNiz;
			NoviVektor.LogVelicina *= 2;
			std::cout << "--Memorija Niza se povecala--" << std::endl;
		}
		std::cout << "Unesi clan niza : " << std::endl;
		std::cin >> NoviVektor.Niz[IndexNiza];
		std::cout << "Niz je trenutno: ";
		for (int i = 0; i < NoviVektor.LogVelicina; ++i) {
			std::cout << NoviVektor.Niz[i] << " ";
		}
		std::cout << std::endl;
	}
	NoviVektor.FizVelicina = IndexNiza;
	std::cout << NoviVektor.FizVelicina;
	return &NoviVektor;
}

void vector_delete(Vector Vektor) {
	delete[] Vektor.Niz;
	Vektor.FizVelicina = 0;
	Vektor.LogVelicina = 0;
}

void vector_push_back(Vector *Vektor, int element) {
	int IndexNiza = Vektor->FizVelicina;
	if (IndexNiza + 1 >= Vektor->LogVelicina) {
		int *VeciNiz = new int[Vektor->LogVelicina * 2]();
		for (int i = 0; i < Vektor->LogVelicina; ++i) {
			VeciNiz[i] = Vektor->Niz[i];
		}
		delete[] Vektor->Niz;
		Vektor->Niz = VeciNiz;
		Vektor->LogVelicina *= 2;
		std::cout << "--Memorija Niza se povecala--" << std::endl;
	}
	Vektor->Niz[IndexNiza] = element;
	++Vektor->FizVelicina;
}

void vector_pop_back(Vector *Vektor) {
	int IndexNiza = Vektor->FizVelicina;
	Vektor->Niz[IndexNiza] = NULL;
	--Vektor->FizVelicina;
}

int vector_front(Vector* Vektor) {
	int IndexNiza = 0;
	return Vektor->Niz[IndexNiza];
}

int vector_back(Vector* Vektor) {
	int IndexNiza = Vektor->FizVelicina - 1;
	return Vektor->Niz[IndexNiza];
}

int vector_size(Vector* Vektor) {
	return Vektor->LogVelicina;
}

void main() {
	Vector Vektor = *vector_new(6);
	for (int i = 0; i < Vektor.FizVelicina; ++i) {
		std::cout << Vektor.Niz[i] << " ";
	}
	std::cout << std::endl;
	int PushBack;
	std::cout << "Unesi pushback clan: " << std::endl;
	std::cin >> PushBack;
	vector_push_back(&Vektor, PushBack);
	for (int i = 0; i < Vektor.FizVelicina; ++i) {
		std::cout << Vektor.Niz[i] << " ";
	}
	std::cout << std::endl;
	vector_pop_back(&Vektor);
	for (int i = 0; i < Vektor.FizVelicina ; ++i) {
		std::cout << Vektor.Niz[i] << " ";
	}
	std::cout << std::endl;
	int PrviClan = vector_front(&Vektor);
	int ZadnjiClan = vector_back(&Vektor);
	int Size = vector_size(&Vektor);
	std::cout << "Prvi clan je " << PrviClan << " Zadnji clan je " << ZadnjiClan << " Logicka velicina je " << Size;
}