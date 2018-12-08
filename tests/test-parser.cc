#include "../include/catch.hpp"
#include "../include/commandParser.h"
#include <string>

TEST_CASE("One-word command is tested", "[testContructor]") {
	Command testCommand1("Look");
	REQUIRE(testCommand1.parseAction() == "Look");
	Command testCommand2("attack");
	REQUIRE(testCommand2.parseAction() == "Attack");
	Command testCommand3("eXiTs");
	REQUIRE(testCommand3.parseAction() == "Exits");
	Command testCommand4("aslkdjff");
	REQUIRE(testCommand4.parseAction() == "Unknown Command");
}
