#include "SDL.h"
#include <iostream>

class Screen {


    public:

        bool display(SDL_Renderer * rend, SDL_Texture * background, bool& running, SDL_Event& e, SDL_Texture ** tex_arr);

    private:

        int x;
        int y;


}; 


