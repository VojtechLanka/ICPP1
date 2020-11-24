#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include "Person.h"
#include "Address.h"
#include "Date.h"

using namespace std;

int getNumberOfItemsInFile(string filename) {
	ifstream txtFile{ filename };

	int n = 0;
	string text;

	while (!txtFile.eof()) {
		getline(txtFile, text);
		n++;
	}
	txtFile.close();

	return n;
}

void save(string filename, Person persons[], int arrayLenght) {
	ofstream txtFile{ filename };
	for (int i = 0; i < arrayLenght; i++) {
		txtFile << persons[i] << endl;
	}
	txtFile.close();
}

Person* load(string filename, int arrayLenght) {
	ifstream txtFile{ filename };
	int n = arrayLenght > 0 ? arrayLenght : getNumberOfItemsInFile(filename);

	Person* persons = new Person[n];

	for (int i = 0; i < arrayLenght; i++) {
		txtFile >> persons[i];
	}
	txtFile.close();
	
	return persons;
}

void saveBin(string filename, Person persons[], int arrayLenght) {
	ofstream file{ filename, ios_base::out | ios_base::binary };

	for (int i = 0; i < arrayLenght; i++) {
		file.write((char*)&persons[i], sizeof Person);
	}
	file.close();
}

Person* loadBin(string filename, int arrayLenght) {
	ifstream file{ filename, ios_base::in | ios_base::binary };
	Person* persons = new Person[arrayLenght];

	for (int i = 0; i < arrayLenght; i++) {
		file.read((char*)&persons[i], sizeof Person);
	}
	file.close();

	return persons;
}

int main() {
	Person personsToSave[] = {
		{ "Milan", "Dolezal", Address("Hajecka", "Zlonice", 27371), Date(10, 2, 2018) },
		{ "Karel", "Vaculik", Address("Halkova", "Mimon", 47124), Date(12, 7, 2015) },
		{ "Erik", "Kana", Address("Bedricha Smetany ", "Cesky Brod", 28201), Date(1, 12, 2020) },
	};

	Person* personsTxt;
	Person* personsDat;

	cout << "Saving persons.txt" << endl;
	save("persons.txt", personsToSave, 3);

	personsTxt = load("persons.txt", 3);
	cout << "Loaded from persons.txt:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << personsTxt[i] << endl;
	}

	cout << endl << "-------------------------------" << endl << endl;

	cout << "Saving persons.dat" << endl;
	saveBin("persons.dat", personsToSave, 3);
	personsDat = loadBin("persons.dat", 3);
	cout << "Loaded from persons.dat:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << personsDat[i] << endl;
	}

	return 0;
}