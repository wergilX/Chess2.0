#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

#include "Game.h"

int main(int argc, char* args[])
{
	Game game;

	bool quit = false;
	while (!quit)
	{
		game.Update();
		game.Render();
		// The event data
		SDL_Event e;
		// Get event data
		//while (SDL_PollEvent(&e))
		while (SDL_PollEvent(&e))
		{
			// If event is quit type
			if (e.type == SDL_EVENT_QUIT)
			{
				// End the main loop
				quit = true;
			}
			if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
			{
				game.HandleInput(e.button.x, e.button.y);
			}
		}
	}

	return 0;
}