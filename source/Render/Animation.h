#pragma once
#include <string>

struct Animation
{
    int spriteRow, spriteFrame;
    int animSpeed, frameCouunt;
    std::string textureId;
};

void SetAnimationProperties(Animation* animation, const std::string& id, int row, int frameCount, int animSpeed);
void UpdateAnimation(Animation* animation);
void DrawAnimation(Animation* animation, float x, float y, int spriteWidth, int spriteHeight, uint8_t scale);