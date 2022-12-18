#pragma once
#include <cstdint>
#include <string>

struct Input
{
	const uint8_t* keys; 
	int mouseX;
	int mouseY;
};

bool IsKeyPressed(int key);
bool IsKeyReleased(int key);
int8_t GetInputAxis(const std::string& axis);

extern Input input;
