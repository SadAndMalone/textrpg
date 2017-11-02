#ifndef KILLABLE_H
#define KILLABLE_H

class Killable {
	public:
		Killable(int defence = 1, int maxhp = 5, const char *corpseName = "A rotting carcass");
		bool isDead(){return hp <= 0;}
		int takeDamage(Mob *self, int damage);
		virtual void die(Mob *self);
		int getDefence(){return defence;}
		const char* getCorpseName(){return corpseName;}
	protected:
		int defence;
		int hp;
		int maxhp;
		const char *corpseName;
};

class PlayerKillable : public Killable {
	public:
		PlayerKillable(int defence = 1, int maxhp = 10, const char *corpseName = "Your corpse.");
		void die(Mob *self);
};

class EnemyKillable : public Killable  {
	public:
		EnemyKillable(int defence = 1, int maxhp = 5, const char *corpseName = "A rotting carcass");
		void die(Mob *self);
};
#endif

