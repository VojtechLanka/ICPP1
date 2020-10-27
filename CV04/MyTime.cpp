#include "MyTime.h"
#include <iostream>

MyTime::~MyTime() {
	delete this;
}

int MyTime::compareTo(IComparable* obj) const {
	MyTime* time = dynamic_cast<MyTime*>(obj);
	if (time == nullptr) {
		throw std::exception("Passed pointer is not instance of MyTime");
	}

	int timeLeft = this->hours * 3600 + this->minutes * 60 + this->seconds;
	int timeRight = time->hours * 3600 + time->minutes * 60 + time->seconds;

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
