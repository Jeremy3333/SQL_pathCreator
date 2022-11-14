#pragma once

#include <SDL2/SDL.h>

#include "RenderWindow.hpp"

class Path
{
private:
    int **possiblePaths;
    int **pathId;
    int width;
    int height;
    SDL_Texture *pathTexture[5];

public:
    Path(int p_width, int p_height, const RenderWindow &window);
    ~Path();
    void draw(RenderWindow &window);
};