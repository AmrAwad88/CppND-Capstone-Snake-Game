#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "environment.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(Environment & environment, 
           const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  Environment *_environment;
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif