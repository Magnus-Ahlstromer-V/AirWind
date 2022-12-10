#include "Entity.h"

#include <stdio.h>

Entity::Entity(const std::string& id, int x, int y, int w, int h) :
	m_position(Vector2f(x, y)), m_size(Vector2i(w, h)), m_textureId(id)
{
	m_scale = 1;
}

Entity::~Entity()
{
	RenderWindow::Get().DropTexture(m_textureId);
}