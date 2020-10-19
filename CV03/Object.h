#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
	int id;
	double x;
	double y;
public:
	Object(int id, double x, double y) : id(id), x(x), y(y) {};
	virtual ~Object() {};

	int getId() const;
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
};

#endif // OBJECT_H
