/* TextRPG - Jacob Malone
 * 2017
 */

#include <ncurses.h>

#ifndef ENGINE_H
#define ENGINE_H

class Engine{
		public:
				enum GameStatus{
						STARTUP,
						IDLE,
						NEW_TURN,
						DEFEAT
				} gameStatus;
				Engine();
				void update();

		private:
				int screenHeight, screenWidth;
				int inputw, inputh;
				int infow, infoh;
};
#endif
