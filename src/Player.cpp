#include "Player.h"

Player::Player(int x, int y, int width, int height)
  : x(x), y(y), width(width), height(height) {}

void Player::handleInput() {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);
  if (keystate[SDL_SCANCODE_W]) y -= 1;
  if (keystate[SDL_SCANCODE_S]) y += 1;
  if (keystate[SDL_SCANCODE_A]) x -= 1;
  if (keystate[SDL_SCANCODE_D]) x += 1;
}

void Player::render(SDL_Renderer* renderer) const {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
  SDL_Rect rect = {x, y, width, height};
  SDL_RenderFillRect(renderer, &rect);
}
