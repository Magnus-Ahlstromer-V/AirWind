#pragma once
#include "../Render/RenderWindow.h"
#include "../Util/Types.h"

#include <SDL2/SDL.h>
#include <string>

enum Direction
{
	LEFT = -1,
	RIGHT = 1
};

class Entity
{
public:
	Entity(const std::string& id, int x, int y, int w, int h);
	virtual ~Entity();

	// Pure virtual functions
	virtual void Update() = 0;
	virtual void Render() = 0;

	// Getters
	inline float GetX() const { return m_position.x; }
	inline float GetY() const { return m_position.y; }
	inline int GetW() const { return m_size.x; }
	inline int GetH() const { return m_size.y; }
	inline float GetXVel() const { return m_velocity.x; }
	inline float GetYVel() const { return m_velocity.y; }
	inline uint8_t GetScale() const { return m_scale; }

	// Setters
	inline void SetScale(uint8_t scale) { m_scale = scale; }
	inline void SetFlip(SDL_RendererFlip flip) { m_flip = flip; }
	inline void SetVelocity(float xVel, float yVel) { m_velocity.x = xVel; m_velocity.y = yVel; }

protected:
	uint8_t m_scale;
	Vector2f m_position;
	Vector2i m_size;
	Vector2f m_velocity;
	std::string m_textureId;
	SDL_RendererFlip m_flip;
};
