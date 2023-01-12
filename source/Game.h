#pragma once
#include "Entity/Player.h"
#include "Entity/Map.h"

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
	Map* m_map;
};
