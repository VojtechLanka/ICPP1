#ifndef MYDATETIME_H
#define MYDATETIME_H

#include "IComparable.h"
#include "MyDate.h"
#include "MyTime.h"

class MyDateTime : public IComparable {
public:
	MyDateTime(MyDate* date, MyTime* time) : date(date), time(time) {};
	~MyDateTime();
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;
private:
	MyDate* date;
	MyTime* time;
};

#endif //MYDATETIME_H