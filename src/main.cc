/* TextRPG - Jacob Malone
 * 2017
 */

#include <iostream>
#include <ncurses.h>
#include "engine.h"

int main(){

		int play = 1;
		Engine engine;
		while(play == 1){
			play = engine.update();
		}
			
		return 0;
}
