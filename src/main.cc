/* TextRPG - Jacob Malone
 * 2017
 */

#include <iostream>
#include <ncurses.h>
#include "engine.h"

int main(){
/*		
		int h, w;					//Height and width of stdscr
		int infoh, infow;
		int inputh, inputw;

		initscr();					//Initialize ncurses
		clear();
		noecho();
		cbreak();
		keypad(stdscr, TRUE);
		curs_set(0);
		getmaxyx(stdscr, h, w);

		infoh = 2.0/3.0 * h;
		infow = w;

		inputh = h - infoh - 1;
		inputw = w;
*/
		/* Initialize windows */
/*		WINDOW *info;
		WINDOW *input;
		info = newwin(infoh, infow, 0, 0);
		input = newwin(inputh, inputw, infoh+1, 0);
		wborder(info, '|', '|', '-', '-', '+', '+', '+', '+');
		wborder(input, '|', '|', '-', '-', '+', '+', '+', '+');


		printw("Welcome to [textrpg], Adventurer.\nPress any key to enter the world,or press \"q\" to quit.");

		int ch = getch();			//wait for user input

		erase();

		while(1){
			if(ch == 'q' || ch == 'Q')
					break;
			else{
					wrefresh(info);
					wrefresh(input);
					ch = wgetch(input);
			}
		}

		endwin();					//Exit ncurses
*/
		Engine engine;
		while(1){
				engine.update();
		}
			
}
