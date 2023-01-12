#include "Animation.h"
#include "RenderWindow.h"

void SetAnimation(Animation* animation, const std::string& id, int row, int frameCount, int animSpeed, SDL_RendererFlip flip)
{
    animation->textureId = id;
    animation->spriteRow = row;
    animation->frameCouunt = frameCount;
    animation->animSpeed = animSpeed;
    animation->flip = flip;
}

void UpdateAnimation(Animation* animation)
{
    animation->spriteFrame = (SDL_GetTicks() / animation->animSpeed) % animation->frameCouunt;
}

void DrawAnimation(Animation* animation, float x, float y, int spriteWidth, int spriteHeight, uint8_t scale)
{
    RenderWindow::Get().DrawFrameEx(animation->textureId, x, y, spriteWidth, spriteHeight, animation->spriteRow, animation->spriteFrame, scale, animation->flip);
}