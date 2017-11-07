#include "room.h"

const int MAX_MOBS = 8;

Room::Room(const char *name, const char *description) : 
			name(name), description(description) {
	createRoom();
}

void Room::displayRoom(){
	engine.message(name);
	engine.message(description);
	engine.message(std::to_string(mobs.size()));
	std::list<Mob *>::iterator it;
	for(it=mobs.begin(); it != mobs.end(); ++it){
			Mob *mob = *it;
			engine.message(mob->getName());
	}
}

void Room::createRoom() {
	std::srand(std::time(NULL));
	addMobs();
}

void Room::addMobs() {
	int count = std::rand() % MAX_MOBS + 1;
	for(int i=0; i < count; ++i){
		randomMob();
	}
}

void Room::randomMob() {
	int roll = std::rand() % 100;
	if(roll < 30) {
		Mob *peon = new Mob;
		peon -> attacker = new Attacker();
		peon -> killable = new Killable();
		mobs.push_back(peon);
		return;
	}
	else if(roll < 70) {
		Mob *rat = new Mob("Rat");
		rat -> attacker = new Attacker(2);
		rat -> killable = new Killable(1, 6);
		mobs.push_back(rat);
		return;
	}
	else {
		Mob *beggar = new Mob("Beggar");
		beggar -> attacker = new Attacker(2);
		beggar -> killable = new Killable(2, 7);
		mobs.push_back(beggar);
		return;
	}
}
