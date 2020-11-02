#include "Person.h"

using namespace Entity;

Person::Person() {
	this->id = -1;
	this->phone = "";
	this->name = "";
}

Person::Person(int id, std::string name, std::string phone) {
	this->id = id;
	this->phone = phone;
	this->name = name;
}

int Person::getId() const {
	return this->id;
}

std::string Person::getName() const {
	return this->name;
}

std::string Person::getPhone() const {
	return this->phone;
}