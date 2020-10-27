#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovingObject.h"
#include "StaticObject.h"

class Game {
private:
	Object** objects;
	int numOfObjects = 0;
	Object** insertObjectIntoArray(Object** oldObject, size_t oldSize, Object* newObject);
	int* insertValueToPointerArray(int* oldArray, size_t oldSize, int newValue);
	static double distanceBetweenObjectAndPoint(double objX, double objY, double pointX, double pointY);
	static bool isBetween(double objX, double objY, double xmin, double xmax, double ymin, double ymax);
	static bool isBeetweenAngles(double umin, double umax, double objU);
public:
	Game(int arrayLength): objects(new Object* [arrayLength]) {};
	~Game();
	void addObject(Object* o);
	int* findIdOfStatickObjects(double xmin, double xmax, double ymin, double ymax);
	MovingObject** findMovingObjectsInArea(double x, double y, double r);
	MovingObject** findMovingObjectsInArea(double x, double y, double r, double amin, double amax);
};

#endif // GAME_H