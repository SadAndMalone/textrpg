#include "map.h"
#include "room.h"

Map::Map() :  rooms(10) {
}

Graph<Room> Map::buildMap() {
	for(int i=0; i<rooms.size(); ++i) {
		rooms.addEdge(Room("Welcome Area", "A bright courtyard filled with balloons"), 0,
				Room("Plains", "A vast plains just outsize of the welcome area"), 1);
	}
	return rooms;
}

int Map::listRooms() {
	rooms.printGraph();
	return 0;
}
