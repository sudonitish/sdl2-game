#include "game.hpp"
#include "texture_manager.hpp"
#include "game_object.hpp"
GameObject *player1;
GameObject *player2;
Game::Game() {}
Game::~Game() {}
void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen)
{
  int flags = 0;
  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsytem Inititalized..." << std::endl;
    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
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
  player1 = new GameObject("assets/player1.png", renderer, 1);
  player2 = new GameObject("assets/player2.png", renderer, 2);
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

  player1->Update(1);
  player2->Update(2);
  std::cout << "Renderer Updated!" << std::endl;
}
void Game::render()
{
  SDL_RenderClear(renderer);
  // Adding Stuff to renderer
  player1->Render();
  player2->Render();
  SDL_RenderPresent(renderer);
}
void Game::clean()
{
  SDL_DestroyWindow(window);
  std::cout << "Window Destroyed." << std::endl;
  SDL_DestroyRenderer(renderer);
  std::cout << "Renderer Destroyed." << std::endl;
  SDL_Quit();
  std::cout << "Game Exited." << std::endl;
}