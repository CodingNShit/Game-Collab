#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

class Renderer {
public:
  Renderer(int screenWidth, int screenHeight);
  ~Renderer(void);
  SDL_Renderer* getRenderer() const;
  void clear(void);
  void present(void);
  
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif // RENDERER_H
