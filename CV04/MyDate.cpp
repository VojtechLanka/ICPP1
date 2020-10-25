#include "MyDate.h"
#include <iostream>
#include <string>

int MyDate::compareTo(IComparable* obj) const {
	std::string dateLeft = std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
	std::string dateRight = std::to_string(((MyDate*)obj)->year) + "-" + std::to_string(((MyDate*)obj)->month) + "-" + std::to_string(((MyDate*)obj)->day);

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
