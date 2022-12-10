#pragma once
#include "Entity/Player.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

private:
	void Update();
	void Render();

private:
	Player* m_player;
};
