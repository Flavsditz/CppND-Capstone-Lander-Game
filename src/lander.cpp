//
// Created by fdiez on 8/22/21.
//

#include <sstream>
#include "../include/lander.hpp"

Lander::Lander(float x, float y, SDL_Texture *tex) : Entity(x, y, 20, 21, tex), speedY(0.1f), speedX(0) {};

void Lander::update() {
    speedY += 0.02f;

    y += speedY;
}

std::string Lander::getSpeedInfo() {
    std::ostringstream os;

    char bufferY[256];
    sprintf(bufferY, "%.1f", speedY);

    char bufferX[256];
    sprintf(bufferX, "%.1f", speedX);

    os << "Speed (Y): " << bufferY;
    os << " - Speed (X): " << bufferX;
    return os.str();
}

void Lander::fireRocket() {
    speedY -= 0.1f;
}

void Lander::fireLeftThrusterRocket() {

}

void Lander::fireRightThrusterRocket() {

}
