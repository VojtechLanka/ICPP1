#include <iostream>
#include <string.h>
#include <math.h>
#include "Game.h"

Game::~Game() {
	for (int i = 0; i < numOfObjects; i++)
	{
		delete objects[i];
	}
	delete[] objects;
}

void Game::addObject(Object* object) {
	this->objects[numOfObjects++] = object;
}

int* Game::findIdOfStatickObjects(double xmin, double xmax, double ymin, double ymax) {
	int* foundIds = nullptr;
	int n = 0;

	for (int i = 0; i < numOfObjects; i++) {
		if (dynamic_cast<StaticObject*>(this->objects[i]) != nullptr) {
			if (isBetween(objects[i]->getX(), objects[i]->getY(), xmin, xmax, ymin, ymax)) {
				foundIds = insertValueToPointerArray(foundIds, n, this->objects[i]->getId());
				n++;
			}
		}
	}
	return foundIds;
}

MovingObject** Game::findMovingObjectsInArea(double x, double y, double r) {
	MovingObject** foundMovingObjects = nullptr;
	int n = 0;

	for (int i = 0; i < numOfObjects; i++) {
		if (dynamic_cast<MovingObject*>(this->objects[i]) != nullptr) {
			double distanceOfObjects = distanceBetweenObjectAndPoint(this->objects[i]->getX(), this->objects[i]->getY(), x, y);
			if (distanceOfObjects <= r) {
				foundMovingObjects = (MovingObject**)insertObjectIntoArray((Object**)foundMovingObjects, n, this->objects[i]);
			}
		}
	}
	return foundMovingObjects;
}

MovingObject** Game::findMovingObjectsInArea(double x, double y, double r, double amin, double amax) {
	MovingObject** foundMovingObjects = nullptr;
	int n = 0;

	for (int i = 0; i < numOfObjects; i++) {
		if (dynamic_cast<MovingObject*>(this->objects[i]) != nullptr) {
			double vzdalenostObjektu = distanceBetweenObjectAndPoint(this->objects[i]->getX(),
				this->objects[i]->getY(), x, y);

			if (vzdalenostObjektu <= r) {
				MovingObject* curr = (MovingObject*)this->objects[i];
				if (isBeetweenAngles(amin, amax, curr->getAngle())) {
					foundMovingObjects = (MovingObject**)insertObjectIntoArray((Object**)foundMovingObjects, n, this->objects[i]);
					n++;
				}
			}
		}
	}
	return foundMovingObjects;
}

int* Game::insertValueToPointerArray(int* oldArray, size_t oldSize, int newValue) {
	int* newArr = new int[oldSize + 1];

	if (oldSize > 0) {
		memcpy(newArr, oldArray, (oldSize + 1) * sizeof(int));
	}
	delete[] oldArray;

	newArr[oldSize] = newValue;

	return newArr;
}

Object** Game::insertObjectIntoArray(Object** oldObject, size_t oldSize, Object* newObject) {
	Object** newArr = new Object * [oldSize + 1];

	if (oldSize > 0) {
		memcpy(newArr, oldObject, (oldSize + 1) * sizeof(Object*));
	}

	delete[] oldObject;
	newArr[oldSize] = newObject;

	return newArr;
}

double Game::distanceBetweenObjectAndPoint(double objX, double objY, double pointX, double pointY)
{
	return abs(sqrt((pointX - objX) * (pointX - objX) + (pointY - objY) * (pointY - objY)));
}

bool Game::isBetween(double objX, double objY, double xmin, double xmaxm, double ymin, double ymax)
{
	return (xmin <= objX && objX <= xmaxm) && (ymin <= objY && objY <= ymax);
}

bool Game::isBeetweenAngles(double umin, double umax, double objU)
{
	return objU <= umax && objU >= umin;
}
