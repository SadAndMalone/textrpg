#include "../include/catch.hpp"
#include "../include/engine.h"
#include <cstring>

TEST_CASE("Message Function is tested.", "[collectInput]") {
	REQUIRE(engine.message("the quick brown fox jumps over the tall fence") == "the quick brown fox jumps over the tall fence");
	REQUIRE(engine.message("1234567890") == "1234567890");
	REQUIRE(engine.message("!@#$%^&*()_+~") == "!@#$%^&*()_+~");
	REQUIRE(engine.message("") == "");
	REQUIRE(engine.message("look") == "look");
	REQUIRE(engine.message("quit") == "quit");
	REQUIRE(engine.message("\n") == "\n");
	endwin();
}

TEST_CASE("processInput is tested.", "[processInput]") {
	char *command = new char[100];

	SECTION("Single word commands are tested") {
		strcpy(command, "look");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "123456");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "!@#$\n\t!@#$^&~.");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "kill");
		REQUIRE(engine.processInput(command) == command);
		endwin();
	}

	SECTION("2+ word commands are tested") {
		strcpy(command, "look around");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "attack worthless peon");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "look           around");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "look \taround");
		REQUIRE(engine.processInput(command) == command);
		strcpy(command, "look \n\r\\0around");
		REQUIRE(engine.processInput(command) == command);
		endwin();
	}
}
