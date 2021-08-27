#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "snake.h"
#include "entity.hpp"
#include "lander.hpp"
#include "infotext.hpp"

class Renderer {
public:
    Renderer(std::size_t screen_width, std::size_t screen_height,
             std::size_t grid_width, std::size_t grid_height);

    ~Renderer();

    void Render(Lander &lander, std::vector<InfoText> hud);

    void UpdateWindowTitle(int score, int fps);

    SDL_Texture *loadTexture(const char *filePath);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;

    void RenderEntity(Entity &entity);
    void RenderLanderInfo(std::vector<InfoText> hud);
    SDL_Point getSize(SDL_Texture *texture);
};

#endif