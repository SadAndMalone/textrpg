#pragma once

#include <list>
#include <cstdlib>
#include <ctime>
#include <string>

class Mob;

class Room {
	public:
		Room(const char *name = NULL , const char *description = NULL);
		void createRoom();
		void displayRoom();
		std::string getName() {return name;}
		std::list<Mob *> mobs;
	private:
		const char *name;
		const char *description;
		void addMobs();
		void randomMob();
};


std::ostringstream& operator<<(std::ostringstream &out, Room room);
