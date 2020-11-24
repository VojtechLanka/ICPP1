#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include "Person.h"
#include "Address.h"
#include "Date.h"

using namespace std;

void save() {
	Address address1 = Address("Hajecka", "Zlonice", 27371);
	Address address2 = Address("Halkova", "Mimon", 47124);
	Address address3 = Address("Bedricha Smetany ", "Cesky Brod", 28201);
	Date date1 = Date(10, 2, 2018);
	Date date2 = Date(12, 7, 2015);
	Date date3 = Date(1, 12, 2020);
	Person persons[] = {
		{ "Milan", "Dolezal", address1, date1 },
		{ "Karel", "Vaculik", address2, date2 },
		{ "Erik", "Kana", address3, date3 },
	};
	ofstream txtFile{ "persons.txt" };
	for (int i = 0; i < 3; i++) {
		txtFile << persons[i] << endl;
	}
	txtFile.close();
}

void load() {
	ifstream txtFile{ "persons.txt" };
	char newLine = '.';
	int n = 0;
	string text;

	while (!txtFile.eof()) {
		getline(txtFile, text);
		n++;
	}

	Person* persons = new Person[n];

	for (int i = 0; i < 3; i++) {
		txtFile >> persons[i];
	}
	txtFile.close();

	for (int i = 0; i < 3; i++) {
		cout << persons[i] << endl;
	}

	delete[] persons;
}

void saveBin() {
	Address address1 = Address("Fibichova", "Drisy", 27714);
	Address address2 = Address("Tylova", "Brezova nad Svitavou", 56902);
	Address address3 = Address("Slunecni ", "Melc", 74784);
	Date date1 = Date(8, 6, 2010);
	Date date2 = Date(22, 9, 2016);
	Date date3 = Date(1, 12, 2200);
	Person persons[] = {
		{ "Vasyl", "Sevcik", address1, date1 },
		{ "Natasa", "Horvathova", address2, date2 },
		{ "Lenka", "Chmelarova", address3, date3 },
	};

	ofstream file{ "persons.dat", ios_base::out | ios_base::binary };

	for (int i = 0; i < 3; i++) {
		file.write((char*)&persons[i], sizeof Person);
	}
	file.close();
}

void loadBin() {
	ifstream file{ "persons.dat", ios_base::in | ios_base::binary };
	Person persons[3];

	for (int i = 0; i < 3; i++) {
		file.read((char*)&persons[i], sizeof Person);
	}
	file.close();

	for (int i = 0; i < 3; i++) {
		cout << persons[i] << endl;
	}
}

int main() {
	save();
	load();

	saveBin();
	loadBin();
	system("pause");
	return 0;
}