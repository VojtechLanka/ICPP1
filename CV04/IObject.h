#ifndef IOBJECT_H
#define IOBJECT_H

#include <string>

class IObject {
public:
	IObject();
	virtual ~IObject() {};
	virtual std::string toString() const = 0;
};

#endif //IOBJECT_H