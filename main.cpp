#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Screen.hpp"




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

void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h, int offsetX, SDL_Rect* portion) {
    SDL_Rect renderQuad = {x + offsetX, y, w, h};
    SDL_RenderCopy(renderer, texture, portion, &renderQuad);
}

int main(int argc, char * argv[]) {


    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event e;
    SDL_Window * window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture * bg;
    bool running = true;
    double move_speed = 10;
    int strip_width = 4514/2;  
    int strip_height = 3009;  

    // Initialize player portion
    SDL_Rect imagestrip = {0, 0, strip_width, strip_height};

   

    //SDL_Rect r1{20, 700, 40, 40};

    SDL_Texture * player_f1 = loadTexture("assets\\player\\walk_right_1.png", renderer);
    SDL_Texture * player_f2 = loadTexture("assets\\player\\walk_right_2.png", renderer);
    SDL_Texture * player_f3 = loadTexture("assets\\player\\walk_left_1.png", renderer);
    SDL_Texture * player_f4 = loadTexture("assets\\player\\walk_left_2.png", renderer);

    SDL_Texture * current_texture_player = player_f1;

    SDL_Texture * enemy_f1 = loadTexture("assets\\player\\walk_right_1.png", renderer);
    SDL_Texture * enemy_f2 = loadTexture("assets\\player\\walk_right_2.png", renderer);
    SDL_Texture * enemy_f3 = loadTexture("assets\\player\\walk_left_1.png", renderer);
    SDL_Texture * enemy_f4 = loadTexture("assets\\player\\walk_left_2.png", renderer);

    SDL_Texture * current_texture_enemy = enemy_f1;


    Player main_player(0, 40);

    Enemy first_enemy(0,40);

    Screen main_screen;

    SDL_Texture * texture_main_screen[3] = {

    loadTexture("assets\\bg\\startscreen.png", renderer),
    loadTexture("assets\\bg\\startbuttonpress.png", renderer), 
    loadTexture("assets\\bg\\exitbuttonpress.png", renderer) 
    
    };

    running = main_screen.display(renderer, bg, running, e, texture_main_screen);

    bg = loadTexture("assets\\bg\\pexels-ömer-derinyar-17718121.jpg", renderer);

    //SDL_RenderDrawRect(renderer, &r1);
    // Define the number of keys
    const int NUM_KEYS = 256;
    bool keyState[NUM_KEYS] = {false};

    int backgroundX = 0;

    while (running) {



         while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }

            if (e.type == SDL_KEYDOWN) {
                keyState[e.key.keysym.scancode] = true;
            } else if (e.type == SDL_KEYUP) {
                keyState[e.key.keysym.scancode] = false;
            }
        }



            if (keyState[SDL_SCANCODE_A]) {
            main_player.movementleft();
            if (imagestrip.x > 1 && main_player.get_sprite()->x <= 20) {
                backgroundX -= 10;
                imagestrip.x -= 10;
            }
        }

        if (keyState[SDL_SCANCODE_D]) {
            main_player.movementright(imagestrip.x);
            if (imagestrip.x < 753) {
                backgroundX += 10;
                imagestrip.x += 10;
            }
        }

        if (keyState[SDL_SCANCODE_W]) {
            main_player.movementjump();
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

        //jump implementation
        main_player.jump();

        //SDL_SetRenderDrawColor(renderer, 0, 0,  0, 255);
        SDL_RenderClear(renderer);

        //SDL_SetRenderDrawColor(renderer, 255, 255,  255, 255);
        
        SDL_RenderCopy(renderer, bg, NULL, NULL);

        if (main_player.moving_forward) {
            
            if (current_texture_player == player_f1) {
        
                SDL_RenderCopy(renderer, current_texture_player, NULL, main_player.get_sprite());
                current_texture_player = player_f2;
                
            }

            else {
                
            SDL_RenderCopy(renderer, current_texture_player, NULL, main_player.get_sprite());
            current_texture_player = player_f1;
            
            }
        }

        else {

            if (current_texture_player == player_f3) {
        
                SDL_RenderCopy(renderer, current_texture_player, NULL, main_player.get_sprite());
                current_texture_player = player_f4;
                
            }

            else {
                
            SDL_RenderCopy(renderer, current_texture_player, NULL, main_player.get_sprite());
            current_texture_player = player_f3;




        }
    
        }
        

    first_enemy.movement();
        
    //SDL_RenderCopy(renderer, current_texture_enemy, NULL, first_enemy.get_sprite());
                
    if (main_player.iscolliding(first_enemy,backgroundX)){
        std::cout << "Collision Detected";
    }
        

    SDL_RenderClear(renderer);

    renderTexture(bg, renderer, 0, 0, 1200, 800, 0,&imagestrip);  
    renderTexture(current_texture_player, renderer, main_player.get_sprite()->x, main_player.get_sprite()->y, main_player.get_sprite()->w, main_player.get_sprite()->h, 0,NULL);

    renderTexture(current_texture_enemy, renderer, first_enemy.get_sprite()->x, first_enemy.get_sprite()->y, first_enemy.get_sprite()->w, first_enemy.get_sprite()->h, -backgroundX,NULL);

    SDL_RenderPresent(renderer);
    SDL_Delay(16);

    }


    return 0;
    } 
