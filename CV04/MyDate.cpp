#include "MyDate.h"
#include <iostream>
#include <string>

MyDate::~MyDate() {
	delete this;
}

int MyDate::compareTo(IComparable* obj) const {
	MyDate* date = dynamic_cast<MyDate*>(obj);
	if (date == nullptr) {
		throw std::exception("Passed pointer is not instance of MyDate");
	}

	std::string dateLeft = std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
	std::string dateRight = std::to_string(date->year) + "-" + std::to_string(date->month) + "-" + std::to_string(date->day);

	int result = strcmp(dateLeft.c_str(), dateRight.c_str());
	if (result == 0) {
		return 0;
	}
	else if (result < 0) {
		return -1;
	}
	return 1;
}

std::string MyDate::toString() const {
	return std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
}
