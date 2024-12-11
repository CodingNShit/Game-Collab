#include "Player.h"
#include "Renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main() {
  Renderer renderer(1280, 720);
  Player player(640, 360, 40, 40);

  bool running = true;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) running = false;
    }
    
    player.handleInput();

    renderer.clear();
    player.render(renderer.getRenderer());
    renderer.present();
  }
}
