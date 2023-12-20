#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Screen.hpp"
#include "AudioPlayer.hpp"
#include "Obstacles.hpp"
#include "vector"
#include "Level.hpp"
#include "LevelScreen.hpp"
#include "SaveFile.hpp"



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

void cleanup(SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h, int offsetX, SDL_Rect* portion) {
    SDL_Rect renderQuad = {x + offsetX, y, w, h};
    SDL_RenderCopy(renderer, texture, portion, &renderQuad);
}

void freeTextures(SDL_Texture* textures[], int numTextures) {
    for (int i = 0; i < numTextures; ++i) {
        if (textures[i] != nullptr) {
            SDL_DestroyTexture(textures[i]);
            textures[i] = nullptr; // Set to nullptr after destruction to avoid double-free
        }
    }
}

int main(int argc, char * argv[]) {


    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event e;
    SDL_Window * window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture * bg;
    bool running = true;
    double move_speed = 15;
    int strip_width = 3600/3;  
    int strip_height = 800;  
    
    AudioPlayer audplay;
    audplay.load_music("assets\\music\\Initial D - Killing My Love.mp3");
    audplay.play_music(2);

    // Initialize player portion
    SDL_Rect imagestrip = {0, 0, strip_width, strip_height};

    SDL_Texture * f1 = loadTexture("assets\\player\\walk_right_1.png", renderer);
    SDL_Texture * f2 = loadTexture("assets\\player\\walk_right_2.png", renderer);
    SDL_Texture * f3 = loadTexture("assets\\player\\walk_left_1.png", renderer);
    SDL_Texture * f4 = loadTexture("assets\\player\\walk_left_2.png", renderer);

    Player main_player(0, 15);
    main_player.setcurrent(f1);
   
    std::vector<bool> lock_array(10);
   
    BaseScreen* level_screen = new LevelScreen;

    SDL_Texture  * level_screeen_textures[22] = {

        loadTexture("assets\\bg\\emptyscreen.png", renderer),
        loadTexture("assets\\bg\\levellock.png", renderer),
        loadTexture("assets\\bg\\level1.png", renderer),
        loadTexture("assets\\bg\\level2.png", renderer),
        loadTexture("assets\\bg\\level3.png", renderer),
        loadTexture("assets\\bg\\level4.png", renderer),
        loadTexture("assets\\bg\\level5.png", renderer),
        loadTexture("assets\\bg\\level6.png", renderer),
        loadTexture("assets\\bg\\level7.png", renderer),
        loadTexture("assets\\bg\\level8.png", renderer),
        loadTexture("assets\\bg\\level9.png", renderer),
        loadTexture("assets\\bg\\level10.png", renderer),
        loadTexture("assets\\bg\\level1hover.png", renderer),
        loadTexture("assets\\bg\\level2hover.png", renderer),
        loadTexture("assets\\bg\\level3hover.png", renderer),
        loadTexture("assets\\bg\\level4hover.png", renderer),
        loadTexture("assets\\bg\\level5hover.png", renderer),
        loadTexture("assets\\bg\\level6hover.png", renderer),
        loadTexture("assets\\bg\\level7hover.png", renderer),
        loadTexture("assets\\bg\\level8hover.png", renderer),
        loadTexture("assets\\bg\\level9hover.png", renderer),
        loadTexture("assets\\bg\\level10hover.png", renderer)


    }; 

    SaveFile game_save;
    game_save.load_save(lock_array);

    BaseScreen* main_screen = new Screen;

    SDL_Texture * texture_main_screen[3] = {

    loadTexture("assets\\bg\\startscreen.png", renderer),
    loadTexture("assets\\bg\\startbuttonpress.png", renderer), 
    loadTexture("assets\\bg\\exitbuttonpress.png", renderer) 
    
    };

    Level level;

    running = main_screen->display(renderer, bg, running, e, texture_main_screen,lock_array, level, main_player);

    level_screen->display(renderer, bg, running, e, level_screeen_textures, lock_array, level, main_player);
    


    bg = loadTexture(level.bgpath, renderer);

    if (level.enemyvect.size()>0){
    for (int i = 0; i < level.enemyvect.size(); ++i){
        level.enemyvect[i]->setcurrent(f1);
    }
    }  

    if (bg == NULL) {
        std::cerr << "Failed to load background texture." << std::endl;
        return -1;
    }

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

        if (level.enemyvect.size()>0){
            for (int i = 0; i < level.enemyvect.size(); ++i){
                level.enemyvect[i]->movement();
            }
        }  

        if (!main_player.isjumping() && !main_player.isCollidingWithObstaclesBelow(level.obstaclevect,level.spikevect, backgroundX)) {
            main_player.setfalling();
        }

        if (!main_player.isDead()){     
            if (keyState[SDL_SCANCODE_A]) {
                bool obstacleCollision = false;
                SDL_Rect* sprite = main_player.get_sprite();
                main_player.movementleft(level.obstaclevect, level.spikevect,backgroundX);

                // Check for collisions with obstacles when moving left
                for (int i = 0; i < level.obstaclevect.size(); ++i) {
                    SDL_Rect obstacleSprite = level.obstaclevect[i].get_sprite();
                    if (sprite->x - move_speed < obstacleSprite.x + obstacleSprite.w &&
                        sprite->x > obstacleSprite.x &&
                        sprite->y + sprite->h > obstacleSprite.y &&
                        sprite->y < obstacleSprite.y + obstacleSprite.h) {
                        obstacleCollision = true;
                        break;
                    }
                }

                for (int x = 0; x<level.spikevect.size();x++){
                    if (level.spikevect[x]->check_collision(main_player.get_sprite())){
                        main_player.setisDead();
                    }
                }

                // Move only if there is no collision with obstacles
                if (!obstacleCollision && imagestrip.x > 1 && main_player.get_sprite()->x <= 20 ) {
                    backgroundX -= move_speed;
                    imagestrip.x -= move_speed;
                    for (int i = 0; i < level.obstaclevect.size(); ++i) {
                        level.obstaclevect[i].offsetting(-move_speed);
                    }
                    for (int i = 0; i < level.spikevect.size() ; ++i) {
                            level.spikevect[i]->offsetting(-move_speed);
                        }
                }
            }

        

            if (keyState[SDL_SCANCODE_D]) {
                bool obstacleCollision = false;;
                SDL_Rect* sprite = main_player.get_sprite();
                main_player.movementright(imagestrip.x,level.obstaclevect,level.spikevect,backgroundX);
                if (imagestrip.x < 2400) {
                    for (int i = 0; i < level.obstaclevect.size(); ++i) {
                        SDL_Rect obstacleSprite = level.obstaclevect[i].get_sprite();
                        if (sprite->x + sprite->w + move_speed > obstacleSprite.x && sprite->x < obstacleSprite.x + obstacleSprite.w &&
                            sprite->y + sprite->h > obstacleSprite.y && sprite->y < obstacleSprite.y + obstacleSprite.h) {
                            obstacleCollision = true;
                            break;
                        }
                    }

                    for (int x = 0; x<level.spikevect.size();x++){
                        if (level.spikevect[x]->check_collision(main_player.get_sprite())){
                            main_player.setisDead();
                        }
                    }

                    if (!obstacleCollision){  
                        backgroundX += move_speed;
                        imagestrip.x += move_speed;
                        for (int i = 0; i < level.obstaclevect.size() ; ++i) {
                            level.obstaclevect[i].offsetting(move_speed);
                        }
                        for (int i = 0; i < level.spikevect.size() ; ++i) {
                            level.spikevect[i]->offsetting(move_speed);
                        }
                    }
                }
            }

            if (keyState[SDL_SCANCODE_W]) {
                main_player.movementjump();
            }
            if (keyState[SDL_SCANCODE_P]) {
                level.clear();
                main_player.reset();
                backgroundX = 0;
                imagestrip = {0, 0, strip_width, strip_height};

                level_screen->display(renderer, bg, running, e, level_screeen_textures, lock_array, level, main_player);

                bg = loadTexture(level.bgpath, renderer);
                if (level.enemyvect.size()>0){
                    for (int i = 0; i < level.enemyvect.size(); ++i){
                        level.enemyvect[i]->setcurrent(f1);
                    }
                }  

            }
            
            keyState[SDL_SCANCODE_P] = false;
            
            //jump implementation
            main_player.jump(level.obstaclevect,level.spikevect,backgroundX);

            //SDL_SetRenderDrawColor(renderer, 0, 0,  0, 255);
            SDL_RenderClear(renderer);

            //SDL_SetRenderDrawColor(renderer, 255, 255,  255, 255);
            
            SDL_RenderCopy(renderer, bg, NULL, NULL);

            main_player.changeframe(f1,f2,f3,f4);
            SDL_RenderCopy(renderer, main_player.getframe(), NULL, main_player.get_sprite());

            if (level.enemyvect.size()>0){          
                if (main_player.iscolliding(level.enemyvect,backgroundX)){
                    main_player.setisDead();
                }
            }

            if (main_player.get_sprite()->y>750)main_player.setisDead();
        }   

        
        //SDL_RenderCopy(renderer, current_texture_enemy, NULL, first_enemy.get_sprite());
        

        if(main_player.get_sprite()->x >= level.nextlevelportal){
            level.nextlevel(main_player);
            main_player.reset();
            backgroundX = 0;
            imagestrip = {0, 0, strip_width, strip_height};
            bg = loadTexture(level.bgpath, renderer);

            lock_array[level.currentlevel-1] = true; //once player goes to a new level that level is unlcoked.

            game_save.save_game(lock_array);

            if (bg == NULL) {
                std::cerr << "Failed to load background texture." << std::endl;
                return -1;
            }
            if (level.enemyvect.size()>0){
                for (int i = 0; i < level.enemyvect.size(); ++i){
                    level.enemyvect[i]->setcurrent(f1);
                }
            }  
        }        

    

        renderTexture(bg, renderer, 0, 0, 1200, 800, 0,&imagestrip);  
        renderTexture(main_player.getframe(), renderer, main_player.get_sprite()->x, main_player.get_sprite()->y, main_player.get_sprite()->w, main_player.get_sprite()->h, 0,NULL);

        if (level.enemyvect.size()>0){
            for (int i = 0; i < level.enemyvect.size(); ++i){
                level.enemyvect[i]->changeframe(f1,f2,f3,f4);
                renderTexture(level.enemyvect[i]->getframe(), renderer, level.enemyvect[i]->get_sprite()->x, level.enemyvect[i]->get_sprite()->y, level.enemyvect[i]->get_sprite()->w,level.enemyvect[i]->get_sprite()->h, -backgroundX,NULL);
            }
        }
        //renderTexture(current_texture_enemy, renderer, second_enemy.get_sprite()->x, second_enemy.get_sprite()->y, second_enemy.get_sprite()->w, second_enemy.get_sprite()->h, -backgroundX,NULL);

        if (main_player.isDead()) {
            // Reset the game state for replaying the current level
            level.replay_current_level(main_player);
            main_player.reset();
            backgroundX = 0;
            imagestrip = {0, 0, strip_width, strip_height};
            bg = loadTexture(level.bgpath, renderer);

            if (bg == NULL) {
                std::cerr << "Failed to load background texture." << std::endl;
                return -1;
            }

            main_player.set_dead_val(false);
            // Clear the event queue to avoid interference
            SDL_FlushEvent(SDL_LASTEVENT);
        }

        SDL_RenderPresent(renderer);
        if (SDL_GetError() && *SDL_GetError()) {
        std::cerr << "SDL Render Error: " << SDL_GetError() << std::endl;
        SDL_ClearError(); // Clear the error to avoid confusion
        }
        SDL_Delay(16);

        main_player.moving = false;
        

        
    }
    freeTextures(level_screeen_textures, 22);
    freeTextures(texture_main_screen, 3);
    SDL_DestroyTexture(bg);
    cleanup(renderer, window);
    return 0;
    } 
