#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

Entity::Entity(float x, float y, float w, float h, SDL_Texture* texture)
:x(x),y(y),texture(texture)
{
   currentframe.x = 0;
   currentframe.y = 0;
   currentframe.w = 100*w;
   currentframe.h = 100*h; 
}

float Entity::getx(){return x;}
float Entity::gety(){return y;}
SDL_Texture* Entity::getTex(){return texture;}
SDL_Rect Entity::getCurrentFrame(){return currentframe;}
