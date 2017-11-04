#ifndef ROOM_H
#define ROOM_H

#include "mob.h"
#include "engine.h"
#include <cstdlib>
#include <ctime>
#include <string>

class Room {
	public:
		Room(const char *name = "default", const char *description = "defaultdesc");
		void createRoom();
		void displayRoom();
	private:
		const char *name;
		const char *description;
		void addMobs();
		Mob* randomMob();
};
#endif
