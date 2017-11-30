/* TextRPG - Jacob Malone
 * 2017
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <ncurses.h>
#include <list>
#include <string>
#include "mob.h"
#include "room.h"

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
				std::string processInput(char *commandBuffer);
				std::string message(std::string text);
				void createPlayer();
//				void combat(Mob *player, Mob *enemy);
		private:
				Mob *player;
				char *commandBuffer = new char[100];
				std::string text;
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

extern Engine engine;
#endif
