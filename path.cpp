#include "Path.hpp"
#include "Utils.hpp"

#include <iostream>

Path::Path(int p_width, int p_height, const RenderWindow &window)
{
    width = p_width;
    height = p_height;
    possiblePaths = new int *[width];
    pathID = new int *[width];
    for (int i = 0; i < width; i++)
    {
        possiblePaths[i] = new int[height];
        pathID[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            possiblePaths[i][j] = 5;
            pathID[i][j] = -1;
        }
    }

    pathTexture[0] = window.loadTexture("include/img/blank.png");
    pathTexture[1] = window.loadTexture("include/img/up.png");
    pathTexture[2] = window.loadTexture("include/img/down.png");
    pathTexture[3] = window.loadTexture("include/img/left.png");
    pathTexture[4] = window.loadTexture("include/img/right.png");
}

Path::~Path()
{
    for (int i = 0; i < width; i++)
    {
        delete[] possiblePaths[i];
        delete[] pathID[i];
    }
    delete[] possiblePaths;
    delete[] pathID;

    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(pathTexture[i]);
    }
}

void Path::draw(RenderWindow &window)
{
    int x, y;
    SDL_QueryTexture(pathTexture[0], NULL, NULL, &x, &y);
    float heightModifier = ((float)SCREEN_WIDTH / (float)PATH_WIDTH) / x;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            window.drawTexture(pathTexture[pathID[i][j]], ((float)SCREEN_WIDTH / (float)PATH_WIDTH) * (float)i, ((float)SCREEN_HEIGHT / (float)PATH_HEIGHT) * (float)j, heightModifier);
        }
    }
}