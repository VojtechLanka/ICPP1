#include <iostream>
#include "Date.h"

Date::Date() {}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date() {}

std::ostream& operator<<(std::ostream& os, Date& date) {
	return os << date.day << " " << date.month << " " << date.year;
}

std::istream& operator>>(std::istream& is, Date& date) {
	is >> date.day;
	is >> date.month;
	is >> date.year;
	return is;
}