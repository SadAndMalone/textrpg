#ifndef MOB_H
#define MOD_H

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
