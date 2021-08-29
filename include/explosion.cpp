//
// Created by fdiez on 8/29/21.
//

#include "explosion.hpp"

Explosion::Explosion(float x, float y, SDL_Texture *tex) : Entity(x, y, 84, 50, tex) {
}

void Explosion::show(float pX, float groundLevel) {
    x = pX - 42;
    y = groundLevel - 50;
}
