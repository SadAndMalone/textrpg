#pragma once

class Mob;

class Attacker {
	public:
		Attacker(int attack = 1) : atk(attack){}
		int attack(Mob *self, Mob *target);
		int getAttack() {return atk;}
	private:
		int atk;
};
