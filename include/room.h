#ifndef ROOM_H
#define ROOM_H

#include "mob.h"
#include "engine.h"
#include <cstdlib>
#include <ctime>
#include <string>

class Room {
	public:
		Room(const char *name = NULL , const char *description = NULL);
		void createRoom();
		void displayRoom();
		std::list<Mob *> mobs;
	private:
		const char *name;
		const char *description;
		void addMobs();
		void randomMob();
};

#endif
