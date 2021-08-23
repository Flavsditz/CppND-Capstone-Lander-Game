//
// Created by fdiez on 8/22/21.
//

#ifndef SDL2TEST_LANDER_HPP
#define SDL2TEST_LANDER_HPP

#include <string>
#include <SDL_render.h>
#include "entity.hpp"

class Lander : public Entity {

public:
    Lander(float x, float y, SDL_Texture *tex);

    void update();

    std::string getSpeedInfo();

    void fireRocket();
    void fireLeftThrusterRocket();
    void fireRightThrusterRocket();


private:
    float speedY;
    float speedX;
};

#endif //SDL2TEST_LANDER_HPP
