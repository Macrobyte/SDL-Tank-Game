#include "SDL.h"
#include <iostream>
#include "Game.h"
#include "ConsoleUtilities.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

Game* GAME = nullptr;



int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;
	
	
	ConsoleUtilities::SetColour(ConsoleUtilities::Yellow);
	printf("Game init attempt...\n");
	ConsoleUtilities::SetColour(ConsoleUtilities::White);
	
	if (GAME->Instance()->InitializeSDL("SDL Tank Game", 100, 100, 640, 480, false))
	{
		ConsoleUtilities::SetColour(ConsoleUtilities::Green);
		printf("Game init success!\n");
		ConsoleUtilities::SetColour(ConsoleUtilities::White);
		
		while (GAME->Instance()->IsRunning())
		{
			frameStart = SDL_GetTicks();
			
			GAME->Instance()->HandleEvents();
			GAME->Instance()->Update();
			GAME->Instance()->Render();

			frameTime = SDL_GetTicks() - frameStart;
			
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
			
		}
	}
	else
	{
		ConsoleUtilities::SetColour(ConsoleUtilities::Red);
		printf("Game init failure - %s\n", SDL_GetError());
		ConsoleUtilities::SetColour(ConsoleUtilities::White);

		return -1;
	}

	ConsoleUtilities::LogText("Game closing...\n", ConsoleUtilities::Red);
	
	GAME->Instance()->Clean();

	return 0;
}

