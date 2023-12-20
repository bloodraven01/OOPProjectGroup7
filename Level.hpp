#ifndef LEVEL_H
#define LEVEL_H


#include <iostream>
#include <vector>
#include <SDL.h>
#include "Obstacles.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Spike.hpp"

class Level {
public:
    std::string bgpath;
    std::vector<Obstacles> obstaclevect;
    std::vector<Enemy*> enemyvect;
    std::vector<Obstacles*> spikevect;
    int nextlevelportal;
    int currentlevel;
    
    void nextlevel(Player& player);
    void firstlevel(Player& player,int num);
    void replay_current_level(Player& player);
    ~Level(){clear();}
    void clear();
    void Initializelevel1(Player& player);
    void Initializelevel2(Player& player);
    void Initializelevel3(Player& player);
    void Initializelevel4(Player& player);
    void Initializelevel5(Player& player);
    void Initializelevel6(Player& player);
    void Initializelevel7(Player& player);
    void Initializelevel8(Player& player);
    void Initializelevel9(Player& player);
    void Initializelevel10(Player& player);
};


#endif /* LEVEL_H */