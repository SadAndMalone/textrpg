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

Command::Command(std::string input) {
	for(size_t i = 0; i < input.length(); ++i) {
		input[i] = std::tolower(input[i]);
	}
	fullCommand = input;
}

int Command::splitCommand() {
	std::cout << fullCommand;
	this->action = fullCommand.substr(0, fullCommand.find(" "));
	fullCommand.erase(0, fullCommand.find(" ") + 1);
	std::istringstream iss(fullCommand);
	std::copy(std::istream_iterator<std::string>(iss),
			  std::istream_iterator<std::string>(),
			  std::back_inserter(args));
	//int i;
	//for(i = 0; !fullCommand.empty(); ++i) {
	//	args.push(fullCommand.substr(0, fullCommand.find(" ")));
	//	fullCommand.erase(0, fullCommand.find(" ") + 1);
	//}	
	//return i; //Returns number of args in the command
	return 0;
}

std::string Command::parseAction() {
	std::cout << this->action << std::endl; 
	if(regex_match(this->action, look)) {
		return "Look";
	}
	if(regex_match(this->action, attack)) {
		return "Attack";
	}
	if(regex_match(this->action, exits)) {
		return "Exits";
	}
	if(regex_match(this->action, quit)) {
		return "Quit";
	}
	
	return "Unknown Command";
}
