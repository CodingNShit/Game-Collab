#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

class Renderer {
public:
  Renderer(int screenWidth, int screenHeight);
  ~Renderer();
  SDL_Renderer* getRenderer() const;
  void clear();
  void present();
  
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif // RENDERER_H
