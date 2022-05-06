#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>



class Entity
{
public:
    Entity(float x , float y, float w, float h, SDL_Texture* texture);
    float getx();
    float gety();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
private:
    float x,y;
    SDL_Rect currentframe;   
    SDL_Texture* texture; 
}; 
