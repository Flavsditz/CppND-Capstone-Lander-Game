//
// Created by fdiez on 8/22/21.
//

#ifndef SDL2TEST_ENTITY_HPP
#define SDL2TEST_ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
    Entity(float x, float y, int width, int height, SDL_Texture *tex);

    void setSpriteNumber(int num);

    float getX() const;

    float getY() const;

    SDL_Texture *getTex();

    SDL_Rect getFrame();

    void hide();

private:
    SDL_Rect frame;
    SDL_Texture *tex;

protected:
    float x;
    float y;
};

#endif //SDL2TEST_ENTITY_HPP
