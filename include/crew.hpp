//
// Created by fdiez on 8/29/21.
//

#ifndef SDL2TEST_CREW_HPP
#define SDL2TEST_CREW_HPP

#include "entity.hpp"

class Crew : public Entity {

public:
    Crew(float x, float y, SDL_Texture *tex);

    void deploy(int landY);

    void setDeboardX(int landingPlatformStart);

private:
    int crewHeight;
};

#endif //SDL2TEST_CREW_HPP
