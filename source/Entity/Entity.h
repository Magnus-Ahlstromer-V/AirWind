#pragma once
#include "Render/RenderWindow.h"
#include "Util/Types.h"

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

	virtual void Update() = 0;
	virtual void Render() = 0;

	inline float GetX() const { return m_position.x; }
	inline float GetY() const { return m_position.y; }
	inline int GetW() const { return m_size.x; }
	inline int GetH() const { return m_size.y; }
	inline uint8_t GetScale() const { return m_scale; }

	inline void SetScale(uint8_t scale) { m_scale = scale; }
	inline void SetDirection(uint8_t direction) { m_direction = direction; }

protected:
	uint8_t m_direction;
	uint8_t m_scale;
	Vector2f m_position;
	Vector2i m_size;
	std::string m_textureId;
};
