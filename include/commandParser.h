/*
 * This, surprisingly, parses the commands for the game.
 * Jacob Malone		2018
 */

#pragma once
#include <string>
#include <deque>

class Command {
	public:
		Command(std::string input);
		int splitCommand();
		std::string parseAction();

	private:
		std::string fullCommand;
		std::string action;
		std::deque<std::string> args;
};
