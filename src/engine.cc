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
	WINDOW *info;								//This will be the main game window. All actions displayed here.
	WINDOW *input;								//This window will be for user input.
	info = newwin(infoh, infow, 0, 0);
	input = newwin(inputh, inputw, infoh+1, 0);
	wborder(info, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(input, '|', '|', '-', '-', '+', '+', '+', '+');
}

void Engine::update(){
	if(gameStatus == STARTUP){
		printw("Welcome to [textrpg], Adventurer.\nPress any key to enter the world\nor press \"q\" to quit.");
	}
}
