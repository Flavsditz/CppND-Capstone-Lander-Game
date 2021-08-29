#include "../include/game.h"
#include "SDL.h"
#include "../include/numbergenerator.hpp"

Game::Game(size_t screenWidth, size_t screenHeight, SDL_Texture *landerTexture, SDL_Texture *crewTexture,
           SDL_Texture *explosionTexture)
        : lander(screenWidth / 2, 0, landerTexture), crew(-50, -50, crewTexture),
          explosion(-100, -100, explosionTexture), groundLevel(screenHeight - 20) {}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration, int screen_width) {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    int landingSize = 50;
    int landingStart = NumberGenerator::randomInt(0, screen_width - landingSize);

    crew.setDeboardX(landingStart);

    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, lander);
        Update(landingStart, landingStart + landingSize);

        // Lander information to be displayed
        std::vector<InfoText> hud{
                InfoText(lander.getHorizontalSpeedInfo()),
                InfoText(lander.getVerticalSpeedInfo()),
                InfoText(lander.getAltitudeInfo(groundLevel))
        };

        std::vector<Entity> entities{
                lander,
                crew,
                explosion
        };
        renderer.Render(entities, hud, landingStart, landingSize, groundLevel);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::Update(int landingAreaStart, int landingAreaEnd) {
    lander.update();

    //Check for impact with the ground
    if (lander.getY() >= groundLevel - lander.getLanderHeight()) {
        if (lander.isLandingSpeed() && lander.getX() >= landingAreaStart && lander.getX() <= landingAreaEnd) {
            lander.land(groundLevel);
            crew.deploy(groundLevel);
        } else {
            lander.land(groundLevel);
            lander.hide();
            explosion.show(lander.getX(), groundLevel);
        }
    }
}