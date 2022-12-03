#pragma once
#define SDL_main_h_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
class Game
{
public:
  Game();
  ~Game();
  void init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);
  void handleEvents();
  void update();
  bool running() { return isRunning; }
  void render();
  void clean();

  static SDL_Renderer *renderer;

private:
  bool isRunning;
  int x = 0, y = 0, f = 0;
  SDL_Window *window;
};