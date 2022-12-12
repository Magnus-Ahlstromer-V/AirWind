#include "Player.h"
#include "Util/Input.h"

#include <stdio.h>

Player::Player(const std::string& id, int x, int y, int w, int h) : Entity(id, x, y, w, h)
{
    SetScale(2);

    RenderWindow::Get().LoadTexture("player_idle", "assets/player/idle.png");
    RenderWindow::Get().LoadTexture("player_run", "assets/player/run.png");
    
    SetAnimation(&m_animation, m_textureId, 0, 11, 60);
}

Player::~Player()
{
    RenderWindow::Get().DropTexture("player_idle");
    RenderWindow::Get().DropTexture("player_run");
}

void Player::Update()
{
    UpdateAnimation(&m_animation);

    if (m_direction == RIGHT)
        SetAnimation(&m_animation, "player_idle", 0, 11, 60);
    else
        SetAnimation(&m_animation, "player_idle", 0, 11, 60, SDL_FLIP_HORIZONTAL);

    if (IsKeyPressed(SDL_SCANCODE_LEFT))
    {
        m_position.x -= 7;
        SetAnimation(&m_animation, "player_run", 0, 11, 50, SDL_FLIP_HORIZONTAL);
        SetDirection(LEFT);
    }
    if (IsKeyPressed(SDL_SCANCODE_RIGHT))
    {
        m_position.x += 7;
        SetAnimation(&m_animation, "player_run", 0, 11, 50);
        SetDirection(RIGHT);
    }

}

void Player::Render()
{
    DrawAnimation(&m_animation, m_position.x, m_position.y, m_size.x, m_size.y, m_scale);
}