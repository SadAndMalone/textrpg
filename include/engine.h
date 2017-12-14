/* TextRPG - Jacob Malone
 * 2017
 */

#pragma once

#include <ncurses.h>
#include <list>
#include <string>

class Mob;
class Room;
class Map;

class Engine {
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
				Map *mainMap;
};

extern Engine engine;
