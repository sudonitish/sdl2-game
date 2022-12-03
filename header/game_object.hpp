#pragma once
#include "game.hpp"

class GameObject
{
public:
    GameObject(const char *textureSheet, int player);
    ~GameObject();

    void Update(int);
    void Render();

private:
    int xPos;
    int yPos;
    int p1;
    int p2;

    SDL_Texture *objectTexture;
    SDL_Rect srcRect, destRect;
};