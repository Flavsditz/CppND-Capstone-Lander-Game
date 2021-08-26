#include "../include/renderer.h"
#include "../include/entity.hpp"
#include "../include/lander.hpp"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
        : screen_width(screen_width),
          screen_height(screen_height),
          grid_width(grid_width),
          grid_height(grid_height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Initialize SDL_image
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cerr << "IMG_Init could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Initialize SDL_image
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init could not initialize.\n";
        std::cerr << "SDL_Error: " << TTF_GetError() << "\n";
        exit(2);
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Lander Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(Lander *lander, std::vector<InfoText> hud) {
    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    RenderEntity(*lander);
    RenderLanderInfo(hud);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}


SDL_Texture *Renderer::loadTexture(const char *filePath) {
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(sdl_renderer, filePath);

    if (texture == nullptr)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void Renderer::RenderEntity(Entity &entity) {
    SDL_Rect src;
    src.x = entity.getFrame().x;
    src.y = entity.getFrame().y;
    src.w = entity.getFrame().w;
    src.h = entity.getFrame().h;

    SDL_Rect dst;
    dst.x = entity.getX();
    dst.y = entity.getY();
    dst.w = entity.getFrame().w;
    dst.h = entity.getFrame().h;

    SDL_RenderCopy(sdl_renderer, entity.getTex(), &src, &dst);

}

void Renderer::RenderLanderInfo(std::vector<InfoText> hud) {

    for (int i = 0; i < hud.size(); ++i) {
        SDL_Texture *message = SDL_CreateTextureFromSurface(sdl_renderer, hud[i].getSurfaceMessage());

        SDL_Point size = getSize(message);

        SDL_Rect messageRect; //create a rect
        messageRect.x = screen_width - size.x - 20;  //controls the rect's x coordinate
        messageRect.y = 20 * (i + 1); // controls the rect's y coordinte
        messageRect.w = size.x; // controls the width of the rect
        messageRect.h = size.y; // controls the height of the rect

        SDL_RenderCopy(sdl_renderer, message, nullptr, &messageRect);
    }

}

SDL_Point Renderer::getSize(SDL_Texture *texture) {
    SDL_Point size;
    SDL_QueryTexture(texture, nullptr, nullptr, &size.x, &size.y);
    return size;
}

void Renderer::UpdateWindowTitle(int score, int fps) {
    std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
