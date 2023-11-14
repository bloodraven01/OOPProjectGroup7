#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "Player.hpp"


SDL_Texture* loadTexture( std::string path, SDL_Renderer * rend)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( rend, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}



int main(int argc, char * argv[]) {


    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event e;
    SDL_Window * window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture * bg = loadTexture("pexels-ahmad-18536470.jpg", renderer);
    bool running = true;
    double move_speed = 10;

    //SDL_Rect r1{20, 700, 40, 40};
    Player main_player(0, 40);
    //SDL_RenderDrawRect(renderer, &r1);



    while (running) {

        while (SDL_PollEvent(&e)) {

            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {


                running = false;

            }



            if (e.type == SDL_KEYDOWN) {

                main_player.movement(e);
            }
/*
                std::cout << "key "  <<  e.key.keysym.sym <<" was pressed! \n";

                if (e.key.keysym.sym == SDLK_a) {

                    r1.x -= move_speed;

                }

                else if (e.key.keysym.sym == SDLK_d) {

                    r1.x += move_speed;
                }



            }
*/


        }

        //SDL_SetRenderDrawColor(renderer, 0, 0,  0, 255);
        SDL_RenderClear(renderer);

        //SDL_SetRenderDrawColor(renderer, 255, 255,  255, 255);
        
        SDL_RenderCopy(renderer, bg, NULL, NULL);
        SDL_RenderFillRect(renderer, main_player.get_sprite());
        SDL_RenderPresent(renderer);
        SDL_Delay(10);

    }


    return 0;
    }