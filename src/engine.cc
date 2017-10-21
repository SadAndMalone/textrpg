#include "engine.h"
#include <string>

Engine::Engine() : gameStatus(STARTUP){
				
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

void Engine::update(){
	if(gameStatus == STARTUP){
		mvwprintw(welcomeContent, 0, 0, "Welcome to [textrpg], Adventurer.\n Press any key to enter the world\n or type \"quit\".");
		wrefresh(welcome);
		wrefresh(welcomeContent);
		wgetch(welcome);
		erase();
		wrefresh(info);
		wrefresh(input);
	}
	gameStatus = IDLE;
	userInput();
}

void Engine::exitGame(){
	endwin();
}

void Engine::userInput(){
	wmove(inputContent, screenHeight-2, 2);
	wrefresh(inputContent);
	echo();
	wgetnstr(inputContent, commandBuffer, 50);
	noecho();
	processInput(commandBuffer);
}

void Engine::message(char *commandBuffer){
	wprintw(infoContent, commandBuffer);
	wrefresh(infoContent);
}

void Engine::processInput(char *commandBuffer){
	std::string command = commandBuffer;
	if(command == "look"){
		message("You look around and see nothing.\n\r");
	}
	else if(command == "quit"){
		exitGame();
		keepPlaying = 0;
	}
	else{
		message("Your incessant babbling has done nothing but confuse.\n\r");
		wrefresh(infoContent);
	}
}
