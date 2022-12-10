#include "Animation.h"
#include "RenderWindow.h"

void SetAnimationProperties(Animation* animation, const std::string& id, int row, int frameCount, int animSpeed)
{
    animation->textureId = id;
    animation->spriteRow = row;
    animation->frameCouunt = frameCount;
    animation->animSpeed = animSpeed;
}

void UpdateAnimation(Animation* animation)
{
    animation->spriteFrame = (SDL_GetTicks() / animation->animSpeed) % animation->frameCouunt;
}

void DrawAnimation(Animation* animation, float x, float y, int spriteWidth, int spriteHeight, uint8_t scale)
{
    RenderWindow::Get().DrawFrame(animation->textureId, x, y, spriteWidth, spriteHeight, animation->spriteRow, animation->spriteFrame, scale);
}