INCLUDE=./include/
OBJDIR=./objects/
TESTDIR=./tests/
MAINOBJ=./objects/main.o
TESTOBJ=./objects/test.o
ENGINEOBJS=./objects/commandParser.o ./objects/engine.o ./objects/killable.o
MAPOBJS=./objects/room.o ./objects/map.o
SRC=./src/
LIBS=-lncurses -ltinfo
CC=g++
CFLAGS=-c -w -g -I$(INCLUDE) -I$(SRC) $(LIBS)
LFLAGS=-w -I$(INCLUDE) -I$(SRC) $(LIBS)

tests: map
	$(CC) $(CFLAGS) $(TESTDIR)testmain.cc -o $(OBJDIR)test.o
	$(CC) $(LIBS) $(ENGINEOBJS) $(MAPOBJS) $(TESTOBJ) -o test
	rm -r $(OBJDIR)

game: map
	$(CC) $(CFLAGS) $(SRC)main.cc -o $(OBJDIR)main.o
	$(CC) $(LIBS) $(ENGINEOBJS) $(MAPOBJS) $(MAINOBJ) -o game
	rm -r $(OBJDIR)

map: mobs
	$(CC) $(CFLAGS) $(INCLUDE)room.cc -o $(OBJDIR)room.o
	$(CC) $(CFLAGS) $(INCLUDE)map.cc -o $(OBJDIR)map.o

mobs: engine
	$(CC) $(CFLAGS) $(INCLUDE)killable.cc -o $(OBJDIR)killable.o

engine: parser
	$(CC) $(CFLAGS) $(INCLUDE)engine.cc -o $(OBJDIR)engine.o

parser:
	mkdir $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE)commandParser.cc -o $(OBJDIR)commandParser.o


clean:
	rm game test
