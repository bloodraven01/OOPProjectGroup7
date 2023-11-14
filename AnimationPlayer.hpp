#include <iostream>
#include "SDL.h"


class AnimationPlayer{

    public:

        void play();
        void stop();

    private:

        int framenum;
        SDL_Rect current_frame;
        SDL_Rect * frames = new SDL_Rect[framenum];

};