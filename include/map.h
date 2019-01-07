#pragma once

#include "graph.h"
#include "room.h"
#include "engine.h"

class Map {
	public:
		Map();
		void buildMap();
		void displayRoom(int id);
		Graph<Room*> getRooms() {return rooms;}
		int listRooms();
	private:
		Graph<Room*> rooms;
};

