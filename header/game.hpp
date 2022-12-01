#define SDL_main_h_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include<iostream>
class Game{
  public:
  Game();
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height ,bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running(){return isRunning;}
  private:
  bool isRunning;
  int x=0,y=0,f=0;
  SDL_Window *window;
  SDL_Renderer *renderer;
};