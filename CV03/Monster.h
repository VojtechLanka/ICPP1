#ifndef MONSTER_H
#define MONSTER_H

#include "MovingObject.h"

class Monster : public MovingObject {
private:
	int hp;
	int maxHp;
public:
	Monster(int id, double x, double y, double angle, int hp, int maxHp) : MovingObject(id, x, y, angle), hp(hp), maxHp(maxHp) {};
	int getHp() const;
	int getMaxHp() const;
	void setHp(int hp);
	void setMaxHp(int maxHp);
};

#endif // MONSTER_H
