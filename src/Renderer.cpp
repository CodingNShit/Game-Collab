#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int screenWidth, int screenHeight) {
  // Initialize SDL. SDL_Init if it return -1 theres error.
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "Error Initialize SDL: " << SDL_GetError() << std::endl;
    exit(1);
  }

  // Creates a window for the program.
  window = SDL_CreateWindow("Top-Down Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
  // Check the Window Create if theres error end program.
  if (!window) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    exit(1);
  }

  // Creates a renderer for the program.
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  // Check the renderer if theres error end program.
  if (!renderer) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(1);
  }
}

// if the renderer goes out of scope it automatically freed up the ram.
Renderer::~Renderer() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// dunno what the fuck this is lol.
SDL_Renderer* Renderer::getRenderer() const {
  return renderer;
}

// Set the background Color to Black.
void Renderer::clear() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

// This render the Renderer makes sense at the same time it does not.
void Renderer::present() {
  SDL_RenderPresent(renderer);
}
