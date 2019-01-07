#include "map.h"
#include "room.h"

Map::Map() : rooms(2) {
	this->buildMap();
}

void Map::buildMap() {
	rooms.addEdge(new Room("Welcome Area", "A bright courtyard filled with balloons"),
			new Room("Plains", "A vast plains just outside of the welcome area"));
}

void Map::displayRoom(int id) {
	rooms.vertices[id].data->displayRoom();
}

int Map::listRooms() {
	rooms.printAdjacent(rooms.vertices[engine.player->getLocation()]);
	return 1;
}
