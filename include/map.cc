#include "map.h"
#include "room.h"

Map::Map() : rooms(2) {
	this->buildMap();
}

void Map::buildMap() {
	rooms.addEdge(new Room("Welcome Area", "A bright courtyard filled with balloons"),
			new Room("Plains", "A vast plains just outsize of the welcome area"));
}

int Map::listRooms() {
	rooms.printAdjacent(rooms.vertices[0]);
	return 1;
}
