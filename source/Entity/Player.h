#pragma once
#include "Entity.h"
#include "Render/Animation.h"

class Player : public Entity
{
public:
    Player(const std::string& id, int x, int y, int w, int h);
    ~Player();

    void Update();
    void Render();

private:

    Animation m_animation;
};