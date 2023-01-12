#pragma once
#include "Entity.h"
#include "../Render/Animation.h"

class Player : public Entity
{
public:
    Player(const std::string& id, int x, int y, int w, int h);
    ~Player();

    void Update();
    void Render();

private:
    void CycleAnimations(int8_t direction);

private:
    bool m_jumping;
    Animation m_animation;
};
