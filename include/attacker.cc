#include "attacker.h"

int Attacker::attack(Mob *self, Mob *target) {
	if(self->attacker->atk <= target->killable->defence) {
		engine.message(self->getName() + " attacks " + target->getName() + " in vain.\n\r");
		return 0;
	}
	else {
		int damage = self->attacker->atk - target->killable->defence;
		target->killable->hp -= damage;
		engine.message(self->getName() + " hit the " + target->getName() + ", dealing " + std::to_string(damage) + " damage.\n\r"); 
		return damage;
	}
}
