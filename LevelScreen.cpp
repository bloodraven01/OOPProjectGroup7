#include "LevelScreen.hpp"
#include <vector>



bool LevelScreen::display(SDL_Renderer * rend, SDL_Texture * background, bool& running, SDL_Event& e, SDL_Texture ** tex_arr, std::vector<bool>& lock_arr, Level& level,Player& player) {

    bool level_selected = false;

    while (!level_selected) {

        SDL_RenderClear(rend);  
        SDL_RenderCopy(rend, background, nullptr, nullptr);
        //SDL_RenderPresent(rend);  

        int x = 0;
        int y = 0;

        int offset_x = 300;
        int offset_y = 200;

        SDL_Rect source = {0,0,100,100};
        SDL_Rect dest = {100, 100, 100, 100};

        for (int i = 0; i < 10; i++) {

            
            if (!lock_arr[i]) { SDL_RenderCopy(rend, tex_arr[1], &source, &dest);}
       
            else{ SDL_RenderCopy(rend, tex_arr[i+2], &source, &dest);}
            
            dest.x += offset_x; // Update destination for the next lock

           
            if ( (i+1) % 4 == 0) {  // Move to the next row after the fourth lock
                dest.x = 100;
                dest.y += offset_y; // Set different heights and y-coordinates for specific lock
                
            }
            

       
       }


    


        source = {0,0,100,100};

        if (SDL_PollEvent(&e)) {

            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                std::exit(0);
            }



        }
                

            if (e.type == SDL_MOUSEBUTTONDOWN) {

                x = e.motion.x;
                y = e.motion.y;

                std::cout << x << ' ' << y << '\n'; 

                for (int i = 0; i < 10; ++i) {
                    int startX, startY;

                    if (i < 4) {
                        startX = 100 + i * 300;
                        startY = 100;

                    } 
                    
                    else if (i < 8) {
                        startX = 100 + (i - 4) * 300;
                        startY = 300;
                    } 
                    
                    else {
                        startX = 100 + (i - 8) * 300;
                        startY = 500;
                    }

                    if (x >= startX && x <= startX + 100 && y >= startY && y <= startY + 100) {
                        if (lock_arr[i] == true){
                        SDL_Rect dest_rect = {startX, startY, 100, 100};
                        SDL_RenderCopy(rend, tex_arr[12 + i], &source, &dest_rect);
                        level_selected = true;
                        level.firstlevel(player,i);
                        }
    
                        
                    
                }
}

            }


        background = tex_arr[0];
        SDL_RenderPresent(rend);

    }

    return false;
}




/*
                if (x >= 100 && x <= 200 && y >= 100 && y <= 200) {

                    SDL_Rect dest_rect = {100,100,100,100};
                    SDL_RenderCopy(rend, tex_arr[12], &source,  &dest_rect);
                    level_selected = true; //since user has clicked the level they want to play level selected becomes true.
                    lock_arr[0] = true; // since this is the condition for level 1 level 1 becomes true;
                
                }

                else if (x >= 400 && x <= 500 && y >= 100 && y <= 200) {

                    SDL_Rect dest_rect = {400,100,100,100};
                    SDL_RenderCopy(rend, tex_arr[13], &source,  &dest_rect);
                    level_selected = true; //since user has clicked the level they want to play level selected becomes true.
                    lock_arr[1] = true; // since this is the condition for level 1 level 1 becomes true;

                }

                else if (x >= 700 && x <= 800 && y >= 100 && y <= 200) {

                    SDL_Rect dest_rect = {700,100,100,100};
                    SDL_RenderCopy(rend, tex_arr[14], &source,  &dest_rect);
                    level_selected = true; //since user has clicked the level they want to play level selected becomes true.
                    lock_arr[2] = true; // since this is the condition for level 1 level 1 becomes true;
                    

                }

                else if (x >= 1000 && x <= 1100 && y >= 100 && y <= 200) {

                    SDL_Rect dest_rect = {1000,100,100,100};
                    SDL_RenderCopy(rend, tex_arr[15], &source,  &dest_rect);
                    level_selected = true; //since user has clicked the level they want to play level selected becomes true.
                    lock_arr[3] = true; // since this is the condition for level 1 level 1 becomes true;
                    

                }

                else if (x >= 100 && x <= 200 && y >= 300 && y <= 400) {

                    SDL_Rect dest_rect = {100,300,100,100};
                    SDL_RenderCopy(rend, tex_arr[16], &source,  &dest_rect);
                    level_selected = true; //since user has clicked the level they want to play level selected becomes true.
                    lock_arr[4] = true; // since this is the condition for level 1 level 1 becomes true;
                    

                }
            }


        }*/