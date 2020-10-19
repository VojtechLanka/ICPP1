#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "Object.h"

class MovingObject : public Object {
private:
	double angle;
public:
	MovingObject(int id, double x, double y, double angle) : Object(id, x, y), angle(angle) {};
	void setAngle(double angle);
	double getAngle() const;
};

#endif // MOVING_OBJECT_H
