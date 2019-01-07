#include <regex>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include "commandParser.h"

std::map<char, std::string> directions {	//
	{'n',"north"},							// 
	{'e',"east"},							// 	Constructs a map for the movement directions
	{'s',"south"},							// 
	{'w',"west"}							//
};

std::regex look("^[Ll](ook)?");
std::regex attack("^[Aa]tt?(tac)?k?");
std::regex exits("^[Ee]xits?");
std::regex quit("^[Qq](uit)?");
std::regex status("^[Ss]tat(us)?");
std::regex move("^[Mm](ove?)?");

Command::Command(std::string input) {
	for(size_t i = 0; i < input.length(); ++i) {
		input[i] = std::tolower(input[i]);
	}
	fullCommand = input;
}

int Command::splitCommand() {
	this->action = fullCommand.substr(0, fullCommand.find(" "));
	fullCommand.erase(0, fullCommand.find(" ") + 1);
	std::istringstream iss(fullCommand);
	std::copy(std::istream_iterator<std::string>(iss),
			  std::istream_iterator<std::string>(),
			  std::back_inserter(args));
	return 0;
}

std::string Command::parseAction() {
	if(regex_match(this->action, look)) {
		return "Look";
	}
	if(regex_match(this->action, status)) {
		return "Status";
	}
	if(regex_match(this->action, attack)) {
		return "Attack";
	}
	if(regex_match(this->action, exits)) {
		return "Exits";
	}
	if(regex_match(this->action, move)) {
		return "Move";
	}
	if(regex_match(this->action, quit)) {
		return "Quit";
	}
	
	return "Unknown Command";
}
