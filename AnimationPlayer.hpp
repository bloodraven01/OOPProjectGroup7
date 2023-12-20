#ifndef ANIMATIONPLAYER_H
#define ANIMATIONPLAYER_H
#include <iostream>
#include "SDL.h"
#include "Character.hpp"

class AnimationPlayer: public Character{

    public:
        AnimationPlayer(double health_val, double speed_val):Character(health_val, speed_val){}
        virtual void changeframe(){}
        void stop();
        virtual void setcurrent(SDL_Texture* frame){currentframe = frame;}
        virtual SDL_Texture* getframe(){return currentframe;}

    protected:
        SDL_Texture* currentframe;
        

};

#endif /* ANIMATIONPLAYER_H */