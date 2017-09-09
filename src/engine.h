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
				void exitGame();
				void userInput();
				bool keepGoing(){return keepPlaying;}
				void processInput(char *commandBuffer);

		private:
				char *commandBuffer = new char[50];
				WINDOW *info;
				WINDOW *infoContent;
				WINDOW *input;
				WINDOW *inputContent;
				WINDOW *welcome;
				WINDOW *welcomeContent;
				int screenHeight, screenWidth;
				int inputw, inputh;
				int infow, infoh;
				int welcomew, welcomeh;
				bool keepPlaying = 1;
				int infoLine = 1;
				int inputLine = 1;
};
#endif
