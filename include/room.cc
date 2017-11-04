#include "room.h"

const int MAX_MOBS = 8;

Room::Room(const char *name, const char *description) : 
			name(name), description(description) {
}

void Room::displayRoom(){
	engine.message("Generic Name \n\r Generic Description \n\r");	
}

void Room::createRoom() {
	std::srand(std::time(NULL));
	addMobs();
}

void Room::addMobs() {
	for(int i=0; i<std::rand() % MAX_MOBS + 1; ++i){
		engine.mobs.push(randomMob());
	}
}

Mob* Room::randomMob() {
	int roll = std::rand() % 100;
	if(roll < 30) {
		Mob *peon = new Mob;
		peon -> attacker = new Attacker();
		peon -> killable = new Killable();
		return peon;
	}
	else if(roll < 70) {
		Mob *rat = new Mob("Rat");
		rat -> attacker = new Attacker(2);
		rat -> killable = new Killable(1, 6);
		return rat;
	}
	else {
		Mob *beggar = new Mob("Beggar");
		beggar -> attacker = new Attacker(2);
		beggar -> killable = new Killable(2, 7);
		return beggar;
	}
}
