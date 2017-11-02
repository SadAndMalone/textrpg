#include "main.h"

Killable::Killable(int defence, int maxhp, const char *corpseName):
			defence(defence), hp(maxhp), maxhp(maxhp), corpseName(corpseName){
}

int Killable::takeDamage(Mob *self, int damage){
	damage -= defence;
	if(damage > 0){
		hp -= damage;
		if(hp <= 0)
			die(self);
	}
	else
		damage = 0;
	return damage;
}

void Killable::die(Mob *self){
	self->getName() = corpseName;
}

PlayerKillable::PlayerKillable(int defence, int maxhp, const char *corpseName){
	Killable(defence, maxhp, corpseName);
}

void PlayerKillable::die(Mob *self){
	self->getName() = corpseName;
	engine.message("You died.\r\nPress Enter to exit.\r\n");
}	

EnemyKillable::EnemyKillable(int defence, int maxhp, const char *corpseName){
	Killable(defence, maxhp, corpseName);
}

void EnemyKillable::die(Mob *self){
	self->getName() = corpseName;
	std::string message = "The " + self->getName() + " dies.\r\n";
	char *cmessage = &message[0u];
	engine.message(cmessage);
}
