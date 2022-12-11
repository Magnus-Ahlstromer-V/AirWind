#pragma once
#include <SDL2/SDL.h>
#include <string>

struct Animation
{
    int spriteRow, spriteFrame;
    int animSpeed, frameCouunt;
    std::string textureId;
    SDL_RendererFlip flip;
};

void SetAnimation(Animation* animation, const std::string& id, int row, int frameCount, int animSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);
void UpdateAnimation(Animation* animation);
void DrawAnimation(Animation* animation, float x, float y, int spriteWidth, int spriteHeight, uint8_t scale);