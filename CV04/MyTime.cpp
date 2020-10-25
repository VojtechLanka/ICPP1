#include "MyTime.h"
#include <iostream>

int MyTime::compareTo(IComparable* obj) const {
	int timeLeft = this->hours * 3600 + this->minutes * 60 + this->seconds;
	int timeRight = ((MyTime*)obj)->hours * 3600 + ((MyTime*)obj)->minutes * 60 + ((MyTime*)obj)->seconds;

	if (timeLeft == timeRight) {
		return 0;
	}
	else if (timeLeft < timeRight) {
		return -1;
	}
	return 1;
}

std::string MyTime::toString() const {
	return std::to_string(this->hours) + ":" + std::to_string(this->minutes) + ":" + std::to_string(this->seconds);
}
