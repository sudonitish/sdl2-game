#include "texture_manager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *texture, SDL_Renderer *ren)
{
    SDL_Surface *tempSurface = IMG_Load(texture);
    if (tempSurface == NULL)
        std::cout << SDL_GetError() << std::endl;
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
};