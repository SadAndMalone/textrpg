/* TextRPG - Jacob Malone
 * 2017
 */

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
				void message(std::string text);
				std::queue<Mob *> mobs;
		private:
				Mob *player;
				char *commandBuffer = new char[50];
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
