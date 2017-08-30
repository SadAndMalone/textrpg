#include "engine.h"

Engine::Engine() : gameStatus(STARTUP){
				
	initscr();									//initialize ncurses
	erase();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, screenHeight, screenWidth);

	infoh = 2.0/3.0 * screenHeight;				/*Set Dimensions for windows*/
	infow = screenWidth;
	inputh = screenHeight - infoh - 1;
	inputw = screenWidth;
	
	/* Initialize windows here */
	info = newwin(infoh, infow, 0, 0);
	input = newwin(inputh, inputw, infoh+1, 0);
	welcome = newwin(10, 80, 15, 20);
	wborder(info, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(input, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(welcome, '|', '|', '-', '-', '+', '+', '+', '+');
}

void Engine::update(){
	if(gameStatus == STARTUP){
		mvwprintw(welcome, 1, 1, "Welcome to [textrpg], Adventurer.\nPress any key to enter the world\nor press \"q\" to quit.");
		wrefresh(welcome);
		wgetch(welcome);
		erase();
		wrefresh(info);
		wrefresh(input);
	}
	gameStatus = IDLE;
	echo();
	wgetnstr(input, commandBuffer, 50);
	noecho();
	if(!strncmp(commandBuffer, "quit", 4)){
			//exit function goes here;
	}
	else{
			wgetnstr(input, commandBuffer, 50);
			wrefresh(info);
			wrefresh(input);
	}
}
