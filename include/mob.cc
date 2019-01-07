#include "mob.h"

Mob::~Mob() {
	if(attacker != NULL)
		delete attacker;
	if(killable != NULL)
		delete killable;
	delete this;
}

void Mob::display() {
	std::string newMessage;
	engine.message(this->name);
	newMessage = "Attack: " + std::to_string(this->attacker->getAttack());
	engine.message(newMessage);
	newMessage = "HP: " + std::to_string(this->killable->hp) + "/" + std::to_string(this->killable->maxhp);  
	engine.message(newMessage);
	engine.message("");
}	

int Mob::move(std::string location) {
	location[0] = std::toupper(location[0]);	
	engine.message(location);

	int newLocation = engine.getMap()->getRooms().isAdjacent(this->location, location);
	engine.message(std::to_string(newLocation));
	if(newLocation != -1) {
		setLocation(newLocation);
	}
	return newLocation;
}
