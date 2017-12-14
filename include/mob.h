#pragma once
#include <string>
#include "attacker.h"
#include "killable.h"

class Mob {
	public:
		Mob(const char *name = "Worthless Peon"): name(name){;}
		~Mob();
		Attacker *attacker;
		Killable *killable;
		std::string getName(){return name;}
		void display();
	private:
		const char *name;
};
