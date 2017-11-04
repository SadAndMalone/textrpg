#ifndef ROOM_H
#define ROOM_H

class Room {
	public:
		Room(const char *name, const char *description);
		void createRoom();
	private:
		const char *name;
		const char *description;
		void addMobs();
}:
#endif
