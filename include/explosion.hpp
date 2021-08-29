//
// Created by fdiez on 8/29/21.
//

#ifndef SDL2TEST_EXPLOSION_HPP
#define SDL2TEST_EXPLOSION_HPP


#include <SDL_render.h>
#include "entity.hpp"

class Explosion : public Entity {

public:
    Explosion(float x, float y, SDL_Texture *tex);

    void show(float pX, float groundLevel);

private:
    int explosionHeight;
};


#endif //SDL2TEST_EXPLOSION_HPP
