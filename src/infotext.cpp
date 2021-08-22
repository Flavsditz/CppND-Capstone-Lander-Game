//
// Created by fdiez on 8/22/21.
//

#include "../include/infotext.hpp"

SDL_Surface *InfoText::getSurfaceMessage() {
    return TTF_RenderText_Solid(font, text.c_str(), whiteColor);
}
