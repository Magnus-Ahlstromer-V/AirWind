#include "Player.h"
#include "Util/Input.h"

Player::Player(const std::string& id, int x, int y, int w, int h) : Entity(id, x, y, w, h)
{
    SetScale(2);
    RenderWindow::Get().LoadTexture(m_textureId, "assets/Player/player_idle.png");
    SetAnimationProperties(&m_animation, m_textureId, 0, 11, 60);
}

void Player::Update()
{
    UpdateAnimation(&m_animation);

    if (IsKeyPressed(SDL_SCANCODE_LEFT)) m_position.x -= 5;
    if (IsKeyPressed(SDL_SCANCODE_RIGHT)) m_position.x += 5;
    if (IsKeyPressed(SDL_SCANCODE_UP)) m_position.y -= 5;
    if (IsKeyPressed(SDL_SCANCODE_DOWN)) m_position.y += 5;

}

void Player::Render()
{
    DrawAnimation(&m_animation, m_position.x, m_position.y, m_size.x, m_size.y, m_scale);
}