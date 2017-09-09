/* TextRPG - Jacob Malone
 * 2017
 */

#include <iostream>
#include <ncurses.h>
#include "engine.h"
#include <string>

int main(){

		Engine engine;
		while(engine.keepGoing()){
			engine.update();
		}
			
		return 0;
}
