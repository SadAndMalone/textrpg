#include "engine.h"
#include "mob.h"
#include "map.h"

Engine::Engine() : gameStatus(STARTUP) { 
				
	initscr();									//initialize ncurses
	erase();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	idlok(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	getmaxyx(stdscr, screenHeight, screenWidth);

	infoh = 2.0/3.0 * screenHeight;				/*Set Dimensions for windows*/
	infow = screenWidth;
	inputh = screenHeight - infoh - 1;
	inputw = screenWidth;
	
	/* Initialize windows here */
	info = newwin(infoh, infow, 0, 0);
	infoContent = newwin(infoh-2, infow-2, 1, 1);
	input = newwin(inputh, inputw, infoh+1, 0);
	inputContent = newwin(inputh-2, inputw-2, infoh+2, 1);
	welcome = newwin(10, 80, 15, 20);
	welcomeContent = newwin(8, 78, 16, 21);
	idlok(infoContent, TRUE);
	idlok(inputContent, TRUE);
	scrollok(infoContent, TRUE);
	scrollok(inputContent, TRUE);
	wborder(info, '|', '|', '~', '~', '+', '+', '+', '+');
	wborder(input, '|', '|', '~', '~', '+', '+', '+', '+');
	wborder(welcome, '|', '|', '~', '~', '+', '+', '+', '+');
}

void Engine::createPlayer() {
	player = new Mob("Player");
	player->attacker = new Attacker(3);
	player->killable = new PlayerKillable();
}

void Engine::update(){
	if(gameStatus == STARTUP){
		mvwprintw(welcomeContent, 0, 0, "Welcome to [textrpg], Adventurer.\n Press any key to enter the world\n or type \"quit\".");
		wrefresh(welcome);
		wrefresh(welcomeContent);
		wgetch(welcome);
		erase();
		wrefresh(info);
		wrefresh(input);
		mainMap = new Map;
		mainMap->listRooms();
	}
	gameStatus = IDLE;
	userInput();
}

void Engine::exitGame(){
	endwin();
}

/*void Engine::combat(Mob *player, Mob *enemy) {
	int lastDamage;
	while(player->killable->hp <= 0 && enemy->killable->hp <= 0) {
		lastDamage = player->attacker->attack(player, enemy);
		lastDamage = enemy->attacker->attack(enemy, player);
	}	
}
*/

void Engine::userInput(){
	wmove(inputContent, screenHeight-2, 2);
	wrefresh(inputContent);
	echo();
	wgetnstr(inputContent, commandBuffer, 50);
	noecho();
	processInput(commandBuffer);
}

std::string Engine::message(std::string text){
	char *cmessage = &text[0u];
	wprintw(infoContent, cmessage);
	wprintw(infoContent, "\n\r");
	wrefresh(infoContent);
	std::string retText = cmessage;
	return retText;
}

std::string Engine::processInput(char *commandBuffer) {
	std::string commandString = commandBuffer;
	std::string command = commandString.substr(0, commandString.find(" "));
	commandString.erase(0, commandString.find(" "));
	std::string target = commandString.substr(0, commandString.find('\0'));
		
	if(command == "look") {
	//	room->displayRoom();
	}
	else if(command == "rooms") {
		mainMap->listRooms();
	}
	else if(command == "quit") {
		exitGame();
		keepPlaying = 0;
	}
	else if(command == "attack") {
		message("Entering combat with " + target + ".\n\r");
	}
	else{
		message("Your incessant babbling has done nothing but confuse.\n\r");
	}
	return command + target;
}
