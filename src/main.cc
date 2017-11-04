/* TextRPG - Jacob Malone
 * 2017
 */

#include "engine.h"

Engine engine;

int main(){

		while(engine.keepGoing()){
			engine.update();
		}
			
		return 0;
}
