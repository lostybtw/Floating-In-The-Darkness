#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* LoadTexture(const char* file);
    void rmWindow();
    void clear();
    void render(Entity& entity);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
