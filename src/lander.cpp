//
// Created by fdiez on 8/22/21.
//

#include <sstream>
#include "../include/lander.hpp"

Lander::Lander(float x, float y, SDL_Texture *tex) : Entity(x, y, 20, 21, tex), speed(0.1f) {};

void Lander::update() {
    speed += 0.02f;

    y += speed;
}

std::string Lander::getSpeedInfo() {
    std::ostringstream os;

    char buffer[256];
    sprintf(buffer, "%.1f", speed);

    os << "Speed: " << buffer;
    return os.str();
}
