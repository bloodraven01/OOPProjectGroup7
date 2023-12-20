#include "SDL_mixer.h"
#include <iostream>


class AudioPlayer{

    public:

        void load_music(const char * file);
        void play_music(int loops);
        void pause_music();
        ~AudioPlayer() { Mix_FreeMusic(music);}

    private:

        Mix_Music * music;
};