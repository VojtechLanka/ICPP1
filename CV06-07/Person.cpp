#include <iostream>
#include "Person.h"

Person::Person() {
	this->name = "";
	this->surname = "";
	this->address = Address();
	this->date = Date();
}

Person::Person(std::string name, std::string surname, Address address, Date date) {
	this->name = name;
	this->surname = surname;
	this->address = address;
	this->date = date;
}

Person::~Person() {}

std::ostream& operator<<(std::ostream& os, Person& person) {
	return os << person.name << " " << person.surname << " " << person.address << " " << person.date;
}

std::istream& operator>>(std::istream& is, Person& person) {
	is >> person.name;
	is >> person.surname;
	is >> person.address;
	is >> person.date;
	return is;
}