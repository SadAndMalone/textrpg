#ifndef MOB_H
#define MOB_H

class Attacker;
class Killable;

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
	private:
		const char *name;
};
#endif
