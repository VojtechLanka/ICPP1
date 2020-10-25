#include "MyDateTime.h"
#include <iostream>

int MyDateTime::compareTo(IComparable* obj) const {
	MyDateTime* dateTime = (MyDateTime*)obj;
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
