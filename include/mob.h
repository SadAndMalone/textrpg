#pragma once
#include <string>
#include "room.h"
#include "map.h"
#include "engine.h"
#include "attacker.h"
#include "killable.h"

class Mob {
	public:
		Mob(const char *name = "Worthless Peon"): name(name){;}
		~Mob();
		Attacker *attacker;
		Killable *killable;
		std::string getName(){return name;}
		int getLocation() {return location;}
		int move(std::string location);
		void setLocation(int newLocation) {location = newLocation;}
		void display();
	private:
		const char *name;
		int location;
};
