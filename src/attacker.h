
#ifndef ATTACKER_H
#define ATTACKER_H

class Attacker {
	public:
		Attacker(int attack = 1) : atk(attack){}
		void attack(Mob *target);
	private:
		int atk;
};

#endif
