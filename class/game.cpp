#include "game.hpp"
SDL_Texture *PlayerTexture;
SDL_Rect srcRect, destRect;
Game::Game() {}
Game::~Game() {}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  int flags = 0;
  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsytem Inititalized..." << std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window)
    {
      std::cout << "Window Created!" << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Created!" << std::endl;
    }
    isRunning = true;
  }
  else
    isRunning = false;

  SDL_Surface *tempSurface = IMG_Load("assets/stick_man.png");

  if (tempSurface == NULL)
  std::cout << SDL_GetError() << std::endl;

  PlayerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
  SDL_FreeSurface(tempSurface);
}
void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}
void Game::update()
{

  if (x == 700)
  {
    f = 1;
  }
  if (x == 0)
  {
    f = 0;
  }
  destRect.h = 200;
  destRect.w = 200;
  destRect.x = x;
  destRect.y = 400;

  if (f == 0)
  {
    x++;
  }
  if (f == 1)
  {
    x--;
  }
  std::cout<<"Renderer Updated!"<<std::endl;
}
void Game::render()
{
  SDL_RenderClear(renderer);
  // Adding Stuff to renderer
  SDL_RenderCopy(renderer, PlayerTexture, NULL, &destRect);
  SDL_RenderPresent(renderer);
}
void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned." << std::endl;
}