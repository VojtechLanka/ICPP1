#include<stdio.h>
#include<stdlib.h>
#include <ctime>
#include "Object.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "Game.h"

using namespace std;

double getRandomDouble(double min, double max) {
	return min + ((double)rand() / RAND_MAX) * (max - min);
}

int main() {
	srand(time(0));
	Game* game = new Game(10);

	for (int i = 0; i < 10; i++) {
		game->addObject(new StaticObject(i, getRandomDouble(-1000.0, 1000.0), getRandomDouble(-1000.0, 1000.0), ObstacleType::Mountain));
		i++;
		game->addObject(new MovingObject(i, getRandomDouble(-1000.0, 1000.0), getRandomDouble(-1000.0, 1000.0), getRandomDouble(0.0, (2 * 3.1415))));
	}

	int* staticObjectsIds = game->findIdOfStatickObjects(-400.0, 700.0, -900.0, 600.0);
	MovingObject** movingObjects = game->findMovingObjectsInArea(0.0, 150.0, 750.0);
	MovingObject** movingObjectsRotatet = game->findMovingObjectsInArea(0.0, 150.0, 750.0, 0.0, 3.1415);

	delete staticObjectsIds;
	delete[] movingObjects;
	delete[] movingObjectsRotatet;
	delete game;

	system("pause");
	return 0;
}