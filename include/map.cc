#include "map.h"
#include "room.h"

Map::Map() : rooms(2) {
	this->buildMap();
}

void Map::buildMap() {
	rooms.addEdge(new Room("Welcome Area", "A bright courtyard filled with balloons"), 0,
			new Room("Plains", "A vast plains just outsize of the welcome area"), 1);
}

int Map::listRooms() {
	rooms.printGraph();
	return 1;
}
