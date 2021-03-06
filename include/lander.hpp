//
// Created by fdiez on 8/22/21.
//

#ifndef SDL2TEST_LANDER_HPP
#define SDL2TEST_LANDER_HPP

#include <string>
#include <cstdlib>
#include <ctime>
#include <SDL_render.h>
#include "entity.hpp"

class Lander : public Entity {

public:
    Lander(float x, float y, SDL_Texture *tex);


    void update();

    std::string getVerticalSpeedInfo();
    std::string getHorizontalSpeedInfo();
    int getLanderHeight();

    void land(size_t i);
    void fireRocket();
    void fireLeftThrusterRocket();
    void fireRightThrusterRocket();
    void noThruster();


    std::string  getAltitudeInfo(size_t groundLevel);

    bool isLandingSpeed();

private:
    float speedY;
    float speedX;
    int landerHeight;
};

#endif //SDL2TEST_LANDER_HPP
