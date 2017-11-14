#ifndef ATTACKER_H
#define ATTACKER_H
class Mob;

#include "mob.h"

class Attacker {
	public:
		Attacker(int attack = 1) : atk(attack){}
		int attack(Mob *self, Mob *target);
	private:
		int atk;
};
#endif
