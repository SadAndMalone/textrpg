#include "mob.h"

Mob::~Mob() {
	if(attacker != NULL)
		delete attacker;
	if(killable != NULL)
		delete killable;
	delete this;
}

void Mob:display() {
	
