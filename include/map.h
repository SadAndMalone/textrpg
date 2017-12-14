#pragma once

#include "graph.h"

class Room;

class Map {
	public:
		Map();
		Graph<Room> buildMap();
		int listRooms();
	private:
		Graph<Room> rooms;
};

