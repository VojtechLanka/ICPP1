#include <iostream>
#include "Address.h"

Address::Address() {
	street = "";
	town = "";
	zipCode = -1;
}

Address::Address(std::string street, std::string town, int zipCode) {
	this->street = street;
	this->town = town;
	this->zipCode = zipCode;
}

Address::~Address() {}

std::string Address::getStreet() {
	return street;
}

std::string Address::getTown() {
	return town;
}

std::ostream& operator<<(std::ostream& os, const Address& address) {
	return os << address.street << " " << address.town << " " << address.zipCode;
}

std::istream& operator>>(std::istream& is, Address& address) {
	is >> address.street;
	is >> address.town;
	is >> address.zipCode;
	return is;
}