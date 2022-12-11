#include "Game.h"
#include "Render/RenderWindow.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	m_player = new Player("player_idle", 200, 512 - 64, 32, 32);
}

Game::~Game()
{
	delete m_player;

	RenderWindow::Get().Clean();

	IMG_Quit();
	SDL_Quit();
}

void Game::Update()
{
	RenderWindow::Get().HandleEvents();

	m_player->Update();
}

void Game::Render()
{
	RenderWindow::Get().SetDrawColor(0x21, 0x13, 0x4D, 0xFF);
	RenderWindow::Get().Clear();
	
	m_player->Render();

	RenderWindow::Get().Display();
}

void Game::Run()
{
	const int FPS = 60;
	const int frameDelay = 1000 / 60;
	uint32_t frameStart;
	int frameTime;

	while (!RenderWindow::Get().ShouldClose())
	{
		frameStart = SDL_GetTicks();

		Update();
		Render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}
}
