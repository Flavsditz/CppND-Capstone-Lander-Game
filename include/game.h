#ifndef GAME_H
#define GAME_H

#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"

class Game {
public:
    Game(size_t screenWidth, size_t screenHeight, SDL_Texture *landerTexture);

    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration, int screen_width);

private:
    Lander lander;
    size_t groundLevel;

    int score{0};

    void Update(Lander &pLander);
};

#endif