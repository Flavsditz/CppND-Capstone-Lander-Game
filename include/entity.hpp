//
// Created by fdiez on 8/22/21.
//

#ifndef SDL2TEST_ENTITY_HPP
#define SDL2TEST_ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
    Entity(int x, int y, int width, int height, SDL_Texture *tex);

    int getX() const;

    int getY() const;

    SDL_Texture *getTex();

    SDL_Rect getFrame();

private:
    SDL_Rect frame;
    SDL_Texture *tex;

protected:
    int x;
    int y;
};

#endif //SDL2TEST_ENTITY_HPP
