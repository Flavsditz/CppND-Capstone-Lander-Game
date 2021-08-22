//
// Created by fdiez on 8/22/21.
//

#include "../include/entity.hpp"
#include <SDL2/SDL.h>

Entity::Entity(int x, int y, int width, int height, SDL_Texture *tex)
        : x(x), y(y), tex(tex) {
    frame.x = 0;
    frame.y = 0;
    frame.w = width;
    frame.h = height;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

SDL_Texture *Entity::getTex() {
    return tex;
}

SDL_Rect Entity::getFrame() {
    return frame;
}