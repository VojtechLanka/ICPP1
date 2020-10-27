#include "MyDateTime.h"
#include <iostream>

MyDateTime::~MyDateTime() {
	delete this;
}

int MyDateTime::compareTo(IComparable* obj) const {
	MyDateTime* dateTime = dynamic_cast<MyDateTime*>(obj);
	if (dateTime == nullptr) {
		throw std::exception("Passed pointer is not instance of MyDateTime");
	}

	int resultTime = this->time->compareTo(dateTime->time);
	int resultDate = this->date->compareTo(dateTime->date);
	
	if (resultTime == 0 && resultDate == 0) {
		return 0;
	}
	else if ((resultDate == 0 && resultTime < 0) || resultDate < 0) {
		return -1;
	}
	return 1;
}

std::string MyDateTime::toString() const {
	return date->toString() + " " + time->toString();
}
