#include "Input.h"
#include <SDL2/SDL.h>

bool IsKeyPressed(int key)
{
	return input.keys[key];
}

bool IsKeyReleased(int key)
{
	return !input.keys[key];
}

int8_t GetInputAxis(const std::string& axis)
{
	if (axis == "Horizontal")
		return IsKeyPressed(SDL_SCANCODE_RIGHT) - IsKeyPressed(SDL_SCANCODE_LEFT);
	else if (axis == "Vertical")
		return IsKeyPressed(SDL_SCANCODE_UP) - IsKeyPressed(SDL_SCANCODE_DOWN);
	else
		return 0;
}

Input input;
