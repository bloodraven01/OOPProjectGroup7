#include "AudioPlayer.hpp"


void AudioPlayer::load_music(const char * file) {


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cerr << "SDL_Mixer could not initialize! SDL_Mixer Error: " << Mix_GetError() << std::endl;
    // Handle initialization error
    }
    
    music = Mix_LoadMUS(file);

}

void AudioPlayer::play_music(int loops) {

    if (music == NULL) {std::cout << "Music file not loaded!\n";}
    else {Mix_PlayMusic(music, loops);}
    

}


void AudioPlayer::pause_music() {
    
    Mix_PauseMusic();
    

}