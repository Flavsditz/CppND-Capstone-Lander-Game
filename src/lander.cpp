//
// Created by fdiez on 8/22/21.
//

#include <sstream>
#include "../include/lander.hpp"
#include "../include/numbergenerator.hpp"

Lander::Lander(float x, float y, SDL_Texture *tex) : Entity(x, y, 20, 22, tex),
                                                     landerHeight(21) {
    speedX = NumberGenerator::randomFloat(-1.5f, 1.5f);
    speedY = 0.0f;
}

void Lander::update() {
    speedY += 0.01f;

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

void Lander::land(size_t groundLevel) {
    speedY = 0;
    speedX = 0;
    y = floor(groundLevel - landerHeight);
}

void Lander::fireRocket() {
    speedY -= 0.1f;
    setSpriteNumber(2);
}

void Lander::fireLeftThrusterRocket() {
    speedX += 0.1f;
}

void Lander::fireRightThrusterRocket() {
    speedX -= 0.1f;
}

void Lander::noThruster() {
    setSpriteNumber(0);
}

std::string Lander::getAltitudeInfo(size_t groundLevel) {
    std::ostringstream os;

    char buffer[256];
    sprintf(buffer, "%d", int(groundLevel) - int(y) - landerHeight);

    os << " Altitude (m): " << buffer;
    return os.str();
}

bool Lander::isLandingSpeed() {
    bool horizSpeedOk = speedX <= 0.1f;
    bool vertSpeedOk = speedY < 1.0f;

    return horizSpeedOk && vertSpeedOk;
}
