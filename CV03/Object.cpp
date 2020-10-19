#include "Object.h"

int Object::getId() const {
	return this->id;
}
double Object::getX() const {
	return this->x;
}
double Object::getY() const {
	return this->y;
}
void Object::setX(double x) {
	this->x = x;
}
void Object::setY(double y) {
	this->y = y;
}