#include "Person.h"

using namespace Entity;

Person::Person() {
	id = -1;
	phone = "";
	name = "";
}

Person::Person(int id, std::string name, std::string phone) {
	this->id = id;
	this->phone = phone;
	this->name = name;
}

int Person::getId() const {
	return id;
}

std::string Person::getName() const {
	return name;
}

std::string Person::getPhone() const {
	return phone;
}