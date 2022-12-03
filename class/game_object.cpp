#include "game_object.hpp"
#include "texture_manager.hpp"

GameObject::GameObject(const char *textureSheet, int player)
{
    objectTexture = TextureManager::LoadTexture(textureSheet);
    if (player == 1)
        xPos = 0;
    if (player == 2)
        xPos = 700;
    yPos = 400;
    p1 = 0;
    p2 = 0;
}
void GameObject::Update(int player)
{
    if (player == 1)
    {
        if (xPos == 700)
        {
            p1 = 1;
        }
        if (xPos == 0)
        {
            p1 = 0;
        }
        if (p1 == 0)
        {
            xPos++;
        }
        if (p1 == 1)
        {
            xPos--;
        }
    }

    if (player == 2)
    {
        if (xPos == 700)
        {
            p2 = 1;
        }
        if (xPos == 0)
        {
            p2 = 0;
        }
        if (p2 == 0)
        {
            xPos++;
        }
        if (p2 == 1)
        {
            xPos--;
        }
    }

    destRect.h = 200;
    destRect.w = 100;
    destRect.x = xPos;
    destRect.y = yPos;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objectTexture, NULL, &destRect);
}