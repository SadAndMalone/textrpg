#pragma once

#include "graph.h"
#include "room.h"

class Map {
	public:
		Map();
		void buildMap();
		int listRooms();
	private:
		Graph<Room*> rooms;
};

