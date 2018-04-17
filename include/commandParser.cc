#include <regex>
#include <map>
#include "commandParser.h"

std::map<char, std::string> directions;	//
directions['n'] = "north";				// 
directions['e'] = "east";				// 	Constructs a map for the movement directions
directions['s'] = "south";				// 
directions['w'] = "west";				//

std::regex look("^l(ook)?");
std::regex attack("^att?(tac)?k?");
std::regex exits("^exits");

Command::Command(std::string input) {
	std::iterator<std::string> it = input.begin();
	while(it != input.end()){
		tolower(*it);
	}
	fullCommand = input;
}

int Command::splitCommand() {
	action = 	fullCommand.substr(0, fullCommand.find(" "));
	fullCommand.erase(0, fullCommand.find(" ") + 1);
	int i = 0;
	for(i; fullCommand.size() > 0; ++i) {
		args[i] = fullCommand.substr(0, fullCommand.find(" "));
		fullCommand.erase(0, fullCommand.find(" ") + 1);
	}
	return i; //Returns number of args in the command
}

std::string Command::parseAction() {
	if(regex_match(action, look)) {

		return "Look";
	}
	if(regex_match(action, attack)) {

		return "Attack";
	}
	if(regex_match(action, exits)) {

		return "Exits";
	}
	
	return "Unknown Command";
}
