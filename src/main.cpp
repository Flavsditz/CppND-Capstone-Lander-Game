#include <iostream>
#include "../include/controller.h"
#include "../include/game.h"
#include "../include/renderer.h"

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};

    Renderer renderer(kScreenWidth, kScreenHeight);
    Controller controller;

    SDL_Texture *landerTexture = renderer.loadTexture("../res/gfx/lander_sprite.png");
    Game game(kScreenWidth, kScreenHeight, landerTexture);
    game.Run(controller, renderer, kMsPerFrame, kScreenWidth);
    std::cout << "Game has terminated successfully!\n";
    return 0;
}