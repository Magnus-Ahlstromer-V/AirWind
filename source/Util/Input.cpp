#include "Input.h"

bool IsKeyPressed(int key)
{
	return input.keys[key];
}

bool IsKeyReleased(int key)
{
	return !input.keys[key];
}


Input input;
