//
// Created by fdiez on 8/29/21.
//

#include "../include/crew.hpp"

Crew::Crew(float x, float y, SDL_Texture *tex) : Entity(x, y, 24, 10, tex), crewHeight(10) {

}

void Crew::deploy(int landY) {
    y = landY - crewHeight;
}

void Crew::setDeboardX(int landingPlatformStart) {
    x = landingPlatformStart;
}
