//
// Created by fdiez on 8/22/21.
//

#ifndef SDL2TEST_INFOTEXT_HPP
#define SDL2TEST_INFOTEXT_HPP

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class InfoText{
public:
    InfoText(std::string text) : text(text) {};

    SDL_Surface *getSurfaceMessage();

private:
    TTF_Font* font = TTF_OpenFont("../res/fonts/OpenSans-Regular.ttf", 12);
    SDL_Color whiteColor = {255, 255, 255};

    std::string text;

};

#endif //SDL2TEST_INFOTEXT_HPP
