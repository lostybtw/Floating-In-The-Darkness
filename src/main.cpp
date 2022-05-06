#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argv, char* argsz[]){
    
    if (SDL_Init(SDL_INIT_VIDEO) > 0){
        std::cout << "SDL INIT FAILED ERROR: " << SDL_GetError() << std::endl;
    }

    if ( ! IMG_Init(IMG_INIT_PNG)){
        std::cout << "IMAGE INIT FAILED ERROR: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("GAME" , 1280 , 720);

    SDL_Texture* sharptile = window.LoadTexture("res/gfx/tile1.png");
    SDL_Texture* character = window.LoadTexture("res/gfx/character.png"); 

    std::vector<Entity>entities = {
        Entity(250,200,2,2,sharptile),
        Entity(510,280,2,2,sharptile),
        Entity(510+260,350,2,2,sharptile),
        Entity(770+(510-250),350,2,2,sharptile),
        Entity(250,100,3,3,character),
    };

    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                gameRunning=false;
            }

           window.clear();


           for(Entity& e : entities){window.render(e);}

           window.display();
        }
    }

    

    window.rmWindow();
    SDL_Quit();

    return 0;
}
