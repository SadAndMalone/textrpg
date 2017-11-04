INCLUDE=./include/
OBJDIR=./objects/
OBJS=./objects/*.o
SRC=./src/
LIBS=-lncurses -ltinfo
CC=g++
CFLAGS=-c -w -I$(INCLUDE) -I$(SRC) $(LIBS)
LFLAGS=-w -I$(INCLUDE) -I$(SRC) $(LIBS)

game: map
	$(CC) $(CFLAGS) $(SRC)main.cc -o $(OBJDIR)main.o
	$(CC) $(LIBS) $(OBJS) -o game

map: mobs
	$(CC) $(CFLAGS) $(INCLUDE)room.cc -o $(OBJDIR)room.o

mobs: engine
	$(CC) $(CFLAGS) $(INCLUDE)killable.cc -o $(OBJDIR)killable.o

engine:
	$(CC) $(CFLAGS) $(INCLUDE)engine.cc -o $(OBJDIR)engine.o
clean:
	rm $(OBJS) game
