#include "mob.h"

Mob::~Mob() {
	if(attacker != NULL)
		delete attacker;
	if(killable != NULL)
		delete killable;
	delete this;
}

void Mob::display() {
	engine.message(this->name + "\n");
	engine.message("Attack: " + this->attacker->getAttack() + "\n");
	engine.message("HP: " + this->killable->hp + "/" + this->killable->maxhp + "\n");
	engine.message("\n");
}	
