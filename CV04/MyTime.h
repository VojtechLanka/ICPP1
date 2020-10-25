#ifndef MYTIME_H
#define MYTIME_H

#include "IComparable.h"

class MyTime : public IComparable {
public:
	MyTime(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {};
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;
private:
	int hours;
	int minutes;
	int seconds;
};

#endif //MYTIME_H