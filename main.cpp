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
    SDL_Texture * bg = loadTexture("assets\\bg\\pexels-ömer-derinyar-17718121.jpg", renderer);
    bool running = true;
    double move_speed = 10;

    //SDL_Rect r1{20, 700, 40, 40};

    SDL_Texture * player_f1 = loadTexture("assets\\player\\walk_right_1.png", renderer);
    SDL_Texture * player_f2 = loadTexture("assets\\player\\walk_right_2.png", renderer);
    SDL_Texture * player_f3 = loadTexture("assets\\player\\walk_left_1.png", renderer);
    SDL_Texture * player_f4 = loadTexture("assets\\player\\walk_left_2.png", renderer);

    SDL_Texture * current_texture = player_f1;

    Player main_player(0, 40, 2);

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

        //jump implementation
        main_player.jump();

        //SDL_SetRenderDrawColor(renderer, 0, 0,  0, 255);
        SDL_RenderClear(renderer);

        //SDL_SetRenderDrawColor(renderer, 255, 255,  255, 255);
        
        SDL_RenderCopy(renderer, bg, NULL, NULL);

        if (main_player.moving_forward) {
            
            if (current_texture == player_f1) {
        
                SDL_RenderCopy(renderer, current_texture, NULL, main_player.get_sprite());
                current_texture = player_f2;
                
            }

            else {
                
            SDL_RenderCopy(renderer, current_texture, NULL, main_player.get_sprite());
            current_texture = player_f1;
            
            }
        }

        else {

            if (current_texture == player_f3) {
        
                SDL_RenderCopy(renderer, current_texture, NULL, main_player.get_sprite());
                current_texture = player_f4;
                
            }

            else {
                
            SDL_RenderCopy(renderer, current_texture, NULL, main_player.get_sprite());
            current_texture = player_f3;




        }
        }

        

        //SDL_RenderFillRect(renderer, main_player.get_sprite());
        SDL_SetRenderTarget(renderer, player_f1);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);

    }


    return 0;
    }
