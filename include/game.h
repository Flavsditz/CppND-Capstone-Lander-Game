#ifndef GAME_H
#define GAME_H

#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "crew.hpp"
#include "explosion.hpp"

class Game {
public:
    Game(size_t screenWidth, size_t screenHeight, SDL_Texture *landerTexture, SDL_Texture *crewTexture, SDL_Texture *explosionTexture);

    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration, int screen_width);

private:
    Crew crew;
    Lander lander;
    Explosion explosion;
    size_t groundLevel;

    int score{0};

    void Update(int landingAreaStart, int landingAreaEnd);
};

#endif