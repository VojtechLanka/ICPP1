#include "Monster.h"
#include <iostream>

int Monster::getHp() const {
	return this->hp;
}
int Monster::getMaxHp() const {
	return this->maxHp;
}
void Monster::setHp(int hp) {
	this->hp = hp;
}
void Monster::setMaxHp(int maxHp) {
	if (maxHp < 0) {
		std::cout << "Invalid max hp. Max hp must be more than 0.";
		return;
	}
	this->maxHp = maxHp;
}