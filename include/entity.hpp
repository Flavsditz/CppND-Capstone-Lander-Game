//
// Created by fdiez on 8/22/21.
//

#ifndef SDL2TEST_ENTITY_HPP
#define SDL2TEST_ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
    Entity(float p_x, float p_y, SDL_Texture *p_tex);

    float getX();

    float getY();

    SDL_Texture *getTex();

    SDL_Rect getCurrentFrame();

private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture *tex;
};

#endif //SDL2TEST_ENTITY_HPP
