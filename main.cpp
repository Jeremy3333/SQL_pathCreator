// test sdl2

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Path.hpp"
#include "Utils.hpp"

int main(int argc, char *argv[])
{
    RenderWindow window("path", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Event event;
    bool quit = false;
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    Path path(PATH_WIDTH, PATH_HEIGHT, window);

    while (!quit)
    {
        float startTicks = SDL_GetTicks();
        float timeStepMs = 2000.0f / window.getRefreshRate();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
            {
                quit = true;
            }
        }

        window.clear();

        path.draw(window);

        window.display();

        float frameTicks = SDL_GetTicks() - startTicks;
        if (frameTicks < timeStepMs)
            SDL_Delay(timeStepMs - frameTicks);
    }
    window.cleanUp();
    return 0;
}