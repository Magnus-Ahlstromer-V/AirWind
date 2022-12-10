#pragma once

struct Vector2f
{
	float x;
	float y;

	Vector2f(float x = 0.f, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

struct Vector2i
{
	int x;
	int y;

	Vector2i(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
};
