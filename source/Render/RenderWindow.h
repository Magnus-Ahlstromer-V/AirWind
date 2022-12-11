#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <unordered_map>
#include <cstdint>

class RenderWindow
{
public:
	static inline RenderWindow& Get() { static RenderWindow instance; return instance; }

	// Window methods
	void HandleEvents();
	inline bool ShouldClose() const { return m_closed; }
		
	// Main render methods
	void LoadTexture(const std::string& id, const char* path);
	void DropTexture(const std::string& id);
	void Draw(const std::string& id, int x, int y, uint8_t scale = 1);
	void DrawFrame(const std::string& id, int x, int y, int w, int h, int frame, uint8_t scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE); 
	void DrawFrame(const std::string& id, int x, int y, int w, int h, int row, int frame, uint8_t scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE); 

	// Util render methods
	void SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void Clear();
	void Display();
	void Clean();

	// Getter methods
	inline SDL_Window* GetHandle() const { return m_window; }
	inline SDL_Renderer* GetRenderer() const { return m_renderer; }

private:
	RenderWindow();
	~RenderWindow();

private:
	// Window attributes
	bool m_closed;
	int m_width;
	int m_height;
	const char* m_title;

	// Window and renderer related members
	std::unordered_map<std::string, SDL_Texture*> m_textureMap;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
