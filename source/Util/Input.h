#pragma once
#include <cstdint>

struct Input
{
	const uint8_t* keys; 
	int mouseX;
	int mouseY;
};

bool IsKeyPressed(int key);
bool IsKeyReleased(int key);

extern Input input;
