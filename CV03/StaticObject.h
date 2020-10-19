#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "Object.h"

enum class ObstacleType { Mountain, SmallFlower, LargeFlower };

class StaticObject : public Object {
private:
	ObstacleType obstacleType;
public:
	StaticObject(int id, double x, double y, ObstacleType obstacleType) : Object(id, x, y), obstacleType(obstacleType) {};
	ObstacleType getObstacleType() const;
};

#endif // STATIC_OBJECT_H
