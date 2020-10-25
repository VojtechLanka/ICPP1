#ifndef MYDATE_H
#define MYDATE_H

#include "IComparable.h"

class MyDate : public IComparable {
public:
	MyDate(int day, int month, int year) : day(day), month(month), year(year) {};
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;
private:
	int day;
	int month;
	int year;
};

#endif //MYDATE_H