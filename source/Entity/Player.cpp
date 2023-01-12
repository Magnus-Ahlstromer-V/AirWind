#include "Player.h"
#include "../Util/Input.h"

#include <stdio.h>

Player::Player(const std::string& id, int x, int y, int w, int h) : Entity(id, x, y, w, h)
{
    // Set entity attributes
    SetScale(2);
    SetVelocity(0.f, 0.f);

    // Set player attributes
    m_jumping = false;


    // Load textures
    RenderWindow::Get().LoadTexture("player_idle", "assets/player/idle.png");
    RenderWindow::Get().LoadTexture("player_run", "assets/player/run.png");
    RenderWindow::Get().LoadTexture("player_jump", "assets/player/jump.png");
    RenderWindow::Get().LoadTexture("player_fall", "assets/player/fall.png");
    
    // Set startup animation
    SetAnimation(&m_animation, m_textureId, 0, 11, 60);
}

Player::~Player()
{
    // Drop all textures
    RenderWindow::Get().DropTexture("player_idle");
    RenderWindow::Get().DropTexture("player_run");
    RenderWindow::Get().DropTexture("player_jump");
    RenderWindow::Get().DropTexture("player_fall");
}

void Player::CycleAnimations(int8_t direction)
{
    // Handle animations based on direction
    if (direction == RIGHT)
    {
        SetFlip(SDL_FLIP_NONE);
        SetAnimation(&m_animation, "player_run", 0, 11, 45);
    }
    else if (direction == LEFT)
    {
        SetFlip(SDL_FLIP_HORIZONTAL);
        SetAnimation(&m_animation, "player_run", 0, 11, 45, SDL_FLIP_HORIZONTAL);
    }

    // Handle jump and fall animations
    if (m_jumping)
    {
        SetAnimation(&m_animation, "player_jump", 0, 1, 20, m_flip);

        if (m_velocity.y > -2.f)
            SetAnimation(&m_animation, "player_fall", 0, 1, 20, m_flip);
    }
}

void Player::Update()
{
    SetAnimation(&m_animation, "player_idle", 0, 11, 50, m_flip);

    // Set velocity on the x axis
    int8_t direction = GetInputAxis("Horizontal");
    m_velocity.x = direction * 7.f;
    CycleAnimations(direction);

    // Gravity
    m_velocity.y += 0.5f;

    // Constrain player
    if (m_position.y >= 512-64)
    {
        m_jumping = false;
        m_velocity.y = 0.f;
        m_position.y = 512-64;
    }

    // Jumping
    if (IsKeyPressed(SDL_SCANCODE_UP) && !m_jumping)
    {
        m_jumping = true;
        m_velocity.y = -12.f;
    }

    // Actually move the player's position
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
    
    // Call to update the animation
    UpdateAnimation(&m_animation);
}

void Player::Render()
{
    // Call to draw animation to the screen
    DrawAnimation(&m_animation, m_position.x, m_position.y, m_size.x, m_size.y, m_scale);
}
