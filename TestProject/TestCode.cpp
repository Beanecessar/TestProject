#include "TestedClass.h"
#include <iostream>
#include <SDL.h>
#include <Windows.h>

int main(int argc, char* args[]) {
	SDL_Joystick *stick = NULL;
	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_JoystickEventState(SDL_ENABLE);
	if (SDL_NumJoysticks() >= 1)
	{
		std::cout << "Controller connected." << std::endl;
		stick = SDL_JoystickOpen(0);
	}

	int x = 0, y = 0;
	while (true)
	{
		while (SDL_PollEvent(&event))
		{
			/*if (event.type == SDL_JOYAXISMOTION)
			{
				if (event.jaxis.axis == 0)
				{
					x = event.jaxis.value;
				}
				if (event.jaxis.axis == 1)
				{
					y = event.jaxis.value;
				}
			}*/
			if (event.type == SDL_JOYBUTTONDOWN)
				/*std::cout << event.jbutton.button << std::endl;*/
				x = event.jbutton.button;
			system("cls");
			std::cout << "x:" << x;
		}
	}
	

	system("pause");

	SDL_Quit();

	return 0;
}

