#include "RenderWindow.h"
#include "Util/Input.h"

#include <assert.h>

#define CENTER SDL_WINDOWPOS_CENTERED

RenderWindow::RenderWindow()
{
	m_closed = false;
	m_width = 1024;
	m_height = 512;
	m_title = "Air Wind";
	
	m_window = SDL_CreateWindow(m_title, CENTER, CENTER, m_width, m_height, 0);	
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

RenderWindow::~RenderWindow()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void RenderWindow::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	input.keys = SDL_GetKeyboardState(nullptr);
	SDL_GetMouseState(&input.mouseX, &input.mouseY);

	if (event.type == SDL_QUIT || IsKeyPressed(SDL_SCANCODE_ESCAPE)) m_closed = true; 
}

void RenderWindow::LoadTexture(const std::string &id, const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	assert(surface);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	assert(texture);

	m_textureMap[id] = texture;

}

void RenderWindow::DropTexture(const std::string& id)
{
	if (m_textureMap[id])
		SDL_DestroyTexture(m_textureMap[id]);
	
	m_textureMap.erase(id);
}

void RenderWindow::SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(m_renderer);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(m_renderer);
}

void RenderWindow::Draw(const std::string& id, int x, int y, uint8_t scale)
{
	SDL_Rect source, dest;
	source.x = 0;
	source.y = 0;
	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &source.w, &source.h);

	dest.x = x;
	dest.y = y;
	dest.w = source.w * scale;
	dest.h = source.h * scale;

	SDL_RenderCopy(m_renderer, m_textureMap[id], &source, &dest);
}

void RenderWindow::DrawFrame(const std::string& id, int x, int y, int w, int h, int frame, uint8_t scale, SDL_RendererFlip flip)
{
	SDL_Rect source, dest;
	source.x = w * frame;
	source.y = h;
	source.w = w;
	source.h = h;

	dest.x = x;
	dest.y = y;
	dest.w = source.w * scale;
	dest.h = source.h * scale;

	SDL_RenderCopyEx(m_renderer, m_textureMap[id], &source, &dest, 0, NULL, flip);
}

void RenderWindow::DrawFrame(const std::string& id, int x, int y, int w, int h, int row, int frame, uint8_t scale, SDL_RendererFlip flip)
{
	SDL_Rect source, dest;
	source.x = w * frame;
	source.y = h * row;
	source.w = w;
	source.h = h;

	dest.x = x;
	dest.y = y;
	dest.w = source.w * scale;
	dest.h = source.h * scale;

	SDL_RenderCopyEx(m_renderer, m_textureMap[id], &source, &dest, 0, NULL, flip);
}


void RenderWindow::Clean()
{
	std::unordered_map<std::string, SDL_Texture*>::iterator it;

	for (it = m_textureMap.begin(); it != m_textureMap.end(); it++)
		SDL_DestroyTexture(it->second);

	m_textureMap.clear();
}
