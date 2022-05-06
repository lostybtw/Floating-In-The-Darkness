#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL){
        std::cout << "CREATING WINDOW FAILED ERROR: " << SDL_GetError() << std::endl; 
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

};

SDL_Texture* RenderWindow::LoadTexture(const char* file){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, file);

    if (texture == NULL)
    {
        std::cout << "FAILED TO LOAD A TEXTURE ERROR" << SDL_GetError()<< std::endl;
    }
}

void  RenderWindow::rmWindow(){
    SDL_DestroyWindow(window);
}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity){
    
    SDL_Rect src;
    src = entity.getCurrentFrame(); 

    SDL_Rect dst;
    dst.x = entity.getx();
    dst.y = entity.gety();
    dst.w = entity.getCurrentFrame().w;
    dst.h = entity.getCurrentFrame().h;
    
    SDL_RenderCopy(renderer, entity.getTex(), &src, &dst); 
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}
