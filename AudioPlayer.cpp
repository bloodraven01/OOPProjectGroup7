#include "AudioPlayer.hpp"


void AudioPlayer::load_music(const char * file) {

    music = Mix_LoadMUS(file);

}

void AudioPlayer::play_music(int loops) {

    if (music == NULL) {std::cout << "Music file not loaded!\n";}
    else {Mix_PlayMusic(music, 2);}
    

}