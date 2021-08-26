//
// Created by fdiez on 8/22/21.
//

#include <sstream>
#include "../include/lander.hpp"

Lander::Lander(float x, float y, SDL_Texture *tex) : Entity(x, y, 20, 21, tex), speedY(0.1f), speedX(0),
                                                     landerHeight(21) {};

void Lander::update() {
    speedY += 0.02f;

    y += speedY;

    x += speedX;
}

int Lander::getLanderHeight() {
    return landerHeight;
}

std::string Lander::getVerticalSpeedInfo() {
    std::ostringstream os;

    char buffer[256];
    sprintf(buffer, "%.1f", speedY);

    os << "Speed (Y): " << buffer;
    return os.str();
}

std::string Lander::getHorizontalSpeedInfo() {
    std::ostringstream os;

    char buffer[256];
    sprintf(buffer, "%.1f", speedX);

    os << " Speed (X): " << buffer;
    return os.str();
}

void Lander::land() {
    speedY = 0;
}

void Lander::fireRocket() {
    speedY -= 0.1f;
}

void Lander::fireLeftThrusterRocket() {
    speedX += 0.1f;
}

void Lander::fireRightThrusterRocket() {
    speedX -= 0.1f;
}
