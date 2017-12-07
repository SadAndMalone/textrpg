#include "room.h"
#include "graph.h"

class Map {
	public:
		Map();
		int listRooms();
	private:
		Graph<Room *> rooms;
};
