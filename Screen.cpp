#include "Screen.hpp"

bool Screen::display(SDL_Renderer * rend, SDL_Texture * background, bool& running, SDL_Event& e, SDL_Texture ** tex_arr) {

    while (running) {

        SDL_RenderClear(rend);  
        SDL_RenderCopy(rend, background, nullptr, nullptr);
        SDL_RenderPresent(rend);  

        int x = 0;
        int y = 0;

        if (SDL_PollEvent(&e)) {

                if (e.type == SDL_MOUSEMOTION) {

                    x = e.motion.x;
                    y = e.motion.y;

                    if (x >= 486 && x <= 716 && y >= 166 && y <= 282) {

                        //SDL_DestroyTexture(background);
                        background = tex_arr[1];
                        //bg = loadTexture("assets\\bg\\startbuttonpress.png", renderer);  
                    

                    }

                    else if (x >= 520 && x <= 680 && y >= 344 && y <= 462) {

                        //SDL_DestroyTexture(background);
                        background = tex_arr[2];
                        //bg = loadTexture("assets\\bg\\exitbuttonpress.png", renderer);


                    }

                    else {

                        //SDL_DestroyTexture(background);
                        background = tex_arr[0];
                        //bg = loadTexture("assets\\bg\\startscreen.png", renderer);

                    }


                }

                if (e.type == SDL_MOUSEBUTTONDOWN) {

                    x = e.motion.x;
                    y = e.motion.y;

                    if (x >= 486 && x <= 716 && y >= 166 && y <= 282) {

                        return true;
                    
                    }

                    else if (x >= 520 && x <= 680 && y >= 344 && y <= 462) {

                        std::exit(0);

                    }


                }


        }

 

    }

    return false;
}

/*
    while (!running) {

        SDL_RenderClear(renderer);  
        SDL_RenderCopy(renderer, bg, nullptr, nullptr);
        SDL_RenderPresent(renderer);  

        int x = 0;
        int y = 0;

        if (SDL_PollEvent(&e)) {

                if (e.type == SDL_MOUSEMOTION) {

                    x = e.motion.x;
                    y = e.motion.y;

                    if (x >= 486 && x <= 716 && y >= 166 && y <= 282) {

                        SDL_DestroyTexture(bg);
                        bg = loadTexture("assets\\bg\\startbuttonpress.png", renderer);  
                    

                    }

                    else if (x >= 520 && x <= 680 && y >= 344 && y <= 462) {

                        SDL_DestroyTexture(bg);
                        bg = loadTexture("assets\\bg\\exitbuttonpress.png", renderer);


                    }

                    else {

                        SDL_DestroyTexture(bg);
                        bg = loadTexture("assets\\bg\\startscreen.png", renderer);

                    }


                }

                if (e.type == SDL_MOUSEBUTTONDOWN) {

                    x = e.motion.x;
                    y = e.motion.y;

                    if (x >= 486 && x <= 716 && y >= 166 && y <= 282) {

                        //std::cout << "bg changed \n";
                        SDL_DestroyTexture(bg);
                        bg = loadTexture("assets\\bg\\pexels-grafixartphoto-samir-belhamra-4254547.jpg", renderer);
                        running = true;
                    
                    }

                    else if (x >= 520 && x <= 680 && y >= 344 && y <= 462) {

                        std::exit(0);

                    }


                }


        }

 

    }
*/