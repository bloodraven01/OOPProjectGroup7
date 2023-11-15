#include "SDL_mixer.h"
#include <iostream>

class AudioPlayer{

    public:

        void load_music(const char * file);
        void play_music(int loops);

    private:

        Mix_Music * music;
};