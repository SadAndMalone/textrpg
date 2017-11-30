INCLUDE=./include/
OBJDIR=./objects/
TESTDIR=./tests/
OBJS=./objects/*.o
SRC=./src/
LIBS=-lncurses -ltinfo
CC=g++
CFLAGS=-c -w -g -I$(INCLUDE) -I$(SRC) $(LIBS)
LFLAGS=-w -I$(INCLUDE) -I$(SRC) $(LIBS)

tests: map
	$(CC) $(CFLAGS) $(TESTDIR)testmain.cc -o $(OBJDIR)test.o
	$(CC) $(LIBS) $(OBJS) -o test
	rm -r $(OBJDIR)

game: map
	$(CC) $(CFLAGS) $(SRC)main.cc -o $(OBJDIR)main.o
	$(CC) $(LIBS) $(OBJS) -o game
	rm -r $(OBJDIR)

map: mobs
	$(CC) $(CFLAGS) $(INCLUDE)room.cc -o $(OBJDIR)room.o

mobs: engine
	$(CC) $(CFLAGS) $(INCLUDE)killable.cc -o $(OBJDIR)killable.o

engine:
	mkdir $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE)engine.cc -o $(OBJDIR)engine.o

clean:
	rm game test
