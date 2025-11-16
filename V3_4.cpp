#include <iostream>
#include <iomanip>
#include <string>


typedef struct {
	std::string Ime;
	int JBMAG;
	int GodinaStudija;
	int ECTS;
	float Prosjek;

}Student;

void Ispis(Student student) {
	std::cout << student.Ime << std::endl;
}

void Povecaj(Student student) {
	++student.GodinaStudija;
}

void Filter(Student Niz[],std::size_t BrojStudenata, void (*Akcija)(Student), bool (*Uvjet)(Student)) {
	for (int i = 0; i < BrojStudenata; ++i) {
		if (Uvjet(Niz[i])) {
			Akcija(Niz[i]);
		}
	}
}

int main() {
	auto Uvjet1 = [](Student student) {return student.ECTS > 0 and student.Prosjek > 1; };
	auto Uvjet2 = [](Student student) {return student.Prosjek > 3.5; };
	auto Uvjet3 = [](Student student) {return student.ECTS >= 45; };

	int const BrojStudenata = 2;
	Student NizStudenata[BrojStudenata];
	for (int i = 0; i < BrojStudenata ; ++i) {
		Student student;
		std::cout << "Unesi ime studenta" << std::endl;
		std::getline(std::cin, student.Ime);
		std::cout << "Unesi JBMAG" << std::endl;
		std::cin >> student.JBMAG;
		std::cout << "Unesi godinu studija" << std::endl;
		std::cin >> student.GodinaStudija;
		std::cout << "Unesi ECTS bodove" << std::endl;
		std::cin >> student.ECTS;
		std::cout << "Unesi Prosjek" << std::endl;
		std::cin >> student.Prosjek;
		std::cin.ignore();
		NizStudenata[i] = student;
	}
	bool (*Uvjet)(Student) = Uvjet1;
	Filter(NizStudenata, BrojStudenata, &Ispis, Uvjet);
	Uvjet = Uvjet2;
	Filter(NizStudenata, BrojStudenata, &Ispis, Uvjet);
	Uvjet = Uvjet3;
	Filter(NizStudenata, BrojStudenata, &Povecaj, Uvjet);
	return 0;
}