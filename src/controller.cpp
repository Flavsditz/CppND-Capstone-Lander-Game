#include "../include/controller.h"
#include <iostream>
#include "SDL.h"
#include "../include/snake.h"

void Controller::HandleInput(bool &running, Lander &lander) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    lander.fireRocket();
                    break;

                case SDLK_LEFT:
                    lander.fireLeftThrusterRocket();
                    break;

                case SDLK_RIGHT:
                    lander.fireRightThrusterRocket();
                    break;
            }
        }
    }
}