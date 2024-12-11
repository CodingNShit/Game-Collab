#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player {
public:
  Player(int x, int y, int width, int height);
  void handleInput();
  void render(SDL_Renderer* renderer) const;

private:
  int x, y, width, height;
};

#endif // PLAYER_H

