/* TextRPG - Jacob Malone
 * 2017
 */

#include <ncurses.h>
#include <string.h>

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
				char *commandBuffer = new char[50];
				WINDOW *info;
				WINDOW *input;
				WINDOW *welcome;
				int screenHeight, screenWidth;
				int inputw, inputh;
				int infow, infoh;
				int welcomew, welcomeh;
};
#endif
