#include "Level.hpp"


void Level::Initializelevel1(Player& player)

{   
    player+=150;

    Enemy enemy1{0,4,703+497-60,703,703,680};
    Enemy enemy2{0,4,2818+783-150,2818,2818,585};
    Obstacles obs1 {0, 739, 192, 62};
    Obstacles obs2    {129, 640, 128, 63};
    Obstacles obs3     {256, 514, 128, 62};
    Obstacles obs4     {448, 322, 128, 62};
    Obstacles obs5    {703, 737, 497, 63};
    Obstacles obs6    {768, 448, 128, 64};
    Obstacles obs7     {1299, 578, 45, 62};
    Obstacles obs8   {1556, 643, 44, 62};
    Obstacles obs9   {1846, 647, 44, 63};
    Obstacles obs10    {2067, 651, 45, 61};
    Obstacles obs11   {2113, 528, 45, 62};
    Obstacles obs12    {2240, 705, 44, 63};
    Obstacles obs13    {2624, 578, 44, 62};
    Obstacles obs14   {2818, 641, 783, 64};

    obstaclevect.push_back(obs1);
    obstaclevect.push_back(obs2);
    obstaclevect.push_back(obs3);
    obstaclevect.push_back(obs4);
    obstaclevect.push_back(obs5);
    obstaclevect.push_back(obs6);
    obstaclevect.push_back(obs7);
    obstaclevect.push_back(obs8);
    obstaclevect.push_back(obs9);
    obstaclevect.push_back(obs10);
    obstaclevect.push_back(obs11);
    obstaclevect.push_back(obs12);
    obstaclevect.push_back(obs13);
    obstaclevect.push_back(obs14);

    enemyvect.push_back(new Enemy(enemy1));
    enemyvect.push_back(new Enemy(enemy2));

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level1bg.png";

    currentlevel = 1;
}

void Level::Initializelevel2(Player& player) {

    player+=150;

    obstaclevect.clear();
    enemyvect.clear();

    Enemy enemy1{0, 4, 611, 386 ,398, 450};
    Enemy enemy2{0, 8, 1185, 850, 850, 670};


    Obstacles obs1{68, 703, 53, 36};
    Obstacles obs2{250, 597, 54, 154};
    Obstacles obs3{383, 516, 234, 62};
    Obstacles obs4{670, 597, 53, 142};
    Obstacles obs5{810, 460, 54, 278};
    Obstacles obs6{937, 547, 235, 63};
    Obstacles obs7{1298, 633, 135, 63};
    Obstacles obs8{1531, 457, 136, 62};
    Obstacles obs9{1817, 353, 136, 63};
    Obstacles obs10{2060, 255, 135, 63};
    Obstacles obs11{2335, 172, 136, 62};
    Obstacles obs12{2654, 244, 135, 62};
    Obstacles obs13{2923, 160, 136, 62};
    Obstacles obs14{3157, 267, 136, 63};
    Obstacles obs15{3397, 154, 136, 62};
    Obstacles obs16{0, 739, 304, 61};
    Obstacles obs17{538, 738, 195, 62};
    Obstacles obs18{806, 737, 395, 63};

    obstaclevect.push_back(obs1);
    obstaclevect.push_back(obs2);
    obstaclevect.push_back(obs3);
    obstaclevect.push_back(obs4);
    obstaclevect.push_back(obs5);
    obstaclevect.push_back(obs6);
    obstaclevect.push_back(obs7);
    obstaclevect.push_back(obs8);
    obstaclevect.push_back(obs9);
    obstaclevect.push_back(obs10);
    obstaclevect.push_back(obs11);
    obstaclevect.push_back(obs12);
    obstaclevect.push_back(obs13);
    obstaclevect.push_back(obs14);
    obstaclevect.push_back(obs15);
    obstaclevect.push_back(obs16);
    obstaclevect.push_back(obs17);
    obstaclevect.push_back(obs18);

    nextlevelportal = 1100;


    enemyvect.push_back(new Enemy(enemy1));
    enemyvect.push_back(new Enemy(enemy2));

    currentlevel = 2;

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level2bg.png";


}

void Level::Initializelevel3(Player& player){

    player+=200;
    player.setspeed(18);
    obstaclevect = {
    {0, 738, 100, 62},
    {272, 738, 100, 62},
    {571, 738, 100, 62},
    {912, 738, 100, 62},
    {1261, 738, 100, 62},
    {1656, 738, 100, 62},
    {1940, 738, 100, 62},
    {2248, 738, 100, 62},
    {2782, 738, 100, 62},
    {3454, 738, 100, 62}
    };

    nextlevelportal = 1100;

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level3bg.png";

    currentlevel = 3;

}

void Level::Initializelevel4(Player& player){
     
    player+=200;

    obstaclevect = {
        {0, 742, 140, 58},
        {300, 655, 561, 58},
        {1051, 596, 119, 58},
        {1273, 398, 467, 59},
        {1887, 680, 119, 59},
        {2129, 582, 119, 59},  
        {2434, 627, 475, 58},
        {3123, 626, 477, 59}
    };

    nextlevelportal = 1100;

    Enemy enemy2{0,4,3123+477,3123,3123,580};

    enemyvect.push_back(new Enemy(enemy2));

    Spike ob1 = {2148, 481, 100, 100};
    Spike ob2 =   {300, 555, 100, 100};
    Spike ob3 =  {770, 557, 100, 100};

    spikevect.push_back(new Spike(ob1));
    spikevect.push_back(new Spike(ob2));
    spikevect.push_back(new Spike(ob3));
    
    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level4bg.png";

    currentlevel = 4;
}

void Level::Initializelevel5(Player& player) {

    player+=150;

    Obstacles obs1{0, 738, 3600, 82};

    Enemy enm1{0, 1, 856, 46, 200,655};
    Enemy enm2{0, 5, 2214, 1041, 1041, 655};
    Enemy enm3{0, 5, 2535, 1881, 1881, 655};
    Enemy enm4{0, 10, 3590, 20, 350, 655};

    nextlevelportal = 1099;

    obstaclevect.push_back(obs1);
    enemyvect.push_back(new Enemy(enm1));
    enemyvect.push_back(new Enemy(enm2));
    enemyvect.push_back(new Enemy(enm3));
    enemyvect.push_back(new Enemy(enm4));

    bgpath = "assets\\bg\\level5bg.png";

    currentlevel = 5;






}

void Level::Initializelevel6(Player& player){
    player+=150;
    obstaclevect = {
    {0,730,500,64},
    {606, 529, 602, 64},
    {1660, 530, 602, 62},
    {2450, 403, 601, 63},
    {3006, 222, 598, 63}
    };

    Enemy enemy1{0,4,1660+602,1660,1660,475};
    Enemy enemy2{0,4,606+602,606,606,457};
    Enemy enemy3{0,4,2450+601,2450,2450,348};
    Enemy enemy4{0,4,3006+598,3006,3006,165};

    enemyvect.push_back(new Enemy(enemy1));
    enemyvect.push_back(new Enemy(enemy2));
    enemyvect.push_back(new Enemy(enemy3));
    enemyvect.push_back(new Enemy(enemy4));

    nextlevelportal = 1100;

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level6bg.png";

    currentlevel = 6;
}

void Level::Initializelevel7(Player& player){
    player+=250;
    obstaclevect = {
    {0, 732, 100, 62},
    {488, 350, 100, 62},
    {980, 383, 100, 62},
    {1375, 598, 100, 62},
    {1775, 333, 100, 62},
    {2000, 748, 100, 62},
    {2335, 568, 100, 62},
    {2860, 303, 100, 62},
    {3410, 608, 100, 62}
    };

    nextlevelportal = 1100;

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level7bg.png";

    currentlevel = 7;

}

void Level::Initializelevel8(Player& player){
    player+=150;
    obstaclevect = {
    {0, 732, 301, 62},
    {308, 518, 301, 63},
    {623, 276, 301, 62},
    {1187, 151, 146, 62},
    {1483, 338, 146, 62},
    {1771, 493, 70, 62},
    {1973, 597, 70, 62},
    {2281, 564, 39, 63},
    {2654, 488, 39, 63},
    {2918, 630, 23, 62},
    {3325, 684, 25, 62}
    };

    nextlevelportal = 1100-150;

    Enemy enemy1{0,4,308+301,308,308,450};
    Enemy enemy2{0,4,623+301,623,623,214};

    enemyvect.push_back(new Enemy(enemy1));
    enemyvect.push_back(new Enemy(enemy2));

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level8bg.png";
    currentlevel = 8;
}

void Level::Initializelevel9(Player& player) {
    player+=210;


    Obstacles obs1{0, 738, 57, 62};
    Obstacles obs2{380, 533, 57, 62};
    Obstacles obs3{810, 251, 57, 62};
    Obstacles obs4{809, 413, 57, 62};
    Obstacles obs5{983, 680, 57, 62};
    Obstacles obs6{1300, 473, 57, 62};
    Obstacles obs7{1788, 357, 57, 62};
    Obstacles obs8{2153, 509, 57, 62};
    Obstacles obs9{2677, 365, 57, 62};
    Obstacles obs10{3219, 399, 57, 62};
    Obstacles obs11{3513, 577, 57, 62};

    nextlevelportal = 1099;


    Enemy fly_en1 {0, 4, 1755 , 42, 42, 366};
    Enemy fly_en2 {0, 4, 2655, 1849, 1849, 401};
    Enemy fly_en3 {0, 4,  3570 ,2223,  2223, 540};


    obstaclevect.push_back(obs1);
    obstaclevect.push_back(obs2);
    obstaclevect.push_back(obs3);
    obstaclevect.push_back(obs4);
    obstaclevect.push_back(obs5);
    obstaclevect.push_back(obs6);
    obstaclevect.push_back(obs7);
    obstaclevect.push_back(obs8);
    obstaclevect.push_back(obs9);
    obstaclevect.push_back(obs10);
    obstaclevect.push_back(obs11);

    enemyvect.push_back(new Enemy(fly_en1));
    enemyvect.push_back(new Enemy(fly_en2));
    enemyvect.push_back(new Enemy(fly_en3));

    bgpath = "C:\\Users\\Tahas\\OneDrive\\Documents\\GitHub\\OOPProjectGroup7\\assets\\bg\\level9bg.png";
    currentlevel = 9;
 
} 

void Level::Initializelevel10(Player& player) {

    player+=150;

    Obstacles obs1{0, 738, 3600, 82};

    nextlevelportal = 1099;

    Enemy enm1{0, 1, 856, 46, 300,655};
    Enemy enm2{0, 5, 2214, 1041, 1041, 655};
    Enemy enm3{0, 5, 2535, 1881, 1881, 655};
    Enemy enm4{0, 10, 3590, 20, 230, 655};
    Enemy enm5{0, 3, 406+ 500, 406, 406, 655};

    obstaclevect.push_back(obs1);

    enemyvect.push_back(new Enemy(enm1));
    enemyvect.push_back(new Enemy(enm2));
    enemyvect.push_back(new Enemy(enm3));
    enemyvect.push_back(new Enemy(enm4));
    enemyvect.push_back(new Enemy(enm5));

    bgpath = "assets\\bg\\level10bg.png";

    currentlevel = 10;


}

void Level::clear(){
    for (auto& enemy : enemyvect) {
        delete enemy; 
    }

    enemyvect.clear();
    nextlevelportal = 1099;

    obstaclevect.clear();
    spikevect.clear();

}


void Level::nextlevel(Player& player){
    int level = currentlevel;
    clear();
    switch (level) {
            case 1:
                Initializelevel2(player);
                break;
            case 2:
                Initializelevel3(player);
                break;
            case 3:
                Initializelevel4(player);
                break;
            case 4:
                Initializelevel5(player);
                break;
            case 5:
                Initializelevel6(player);
                break;
            case 6:
                Initializelevel7(player);
                break;
            case 7:
                Initializelevel8(player);
                break;
            case 8:
                Initializelevel9(player);
                break;
            case 9:
                Initializelevel10(player);
                break;
            default:
                Initializelevel1(player);
}

}

void Level::replay_current_level(Player& player) 

{
    int level = currentlevel;
    std::cout << level;
    clear();
    switch (level) {
            case 1:
                Initializelevel1(player);
                break;
            case 2:
                Initializelevel2(player);
                break;
            case 3:
                Initializelevel3(player);
                break;
            case 4:
                Initializelevel4(player);
                break;
            case 5:
                Initializelevel5(player);
                break;
            case 6:
                Initializelevel6(player);
                break;
            case 7:
                Initializelevel7(player);
                break;
            case 8:
                Initializelevel8(player);
                break;
            case 9:
                Initializelevel9(player);
                break;
            case 10:
                Initializelevel10(player);
                break;

    }



}

void Level::firstlevel(Player& player, int num){
    clear();
    switch (num) {
            case 0:
                Initializelevel1(player);
                break;
            case 1:
                Initializelevel2(player);
                break;
            case 2:
                Initializelevel3(player);
                break;
            case 3:
                Initializelevel4(player);
                break;
            case 4:
                Initializelevel5(player);
                break;
            case 5:
                Initializelevel6(player);
                break;
            case 6:
                Initializelevel7(player);
                break;
            case 7:
                Initializelevel8(player);
                break;
            case 8:
                Initializelevel9(player);
                break;
            case 9:
                Initializelevel10(player);
                break;
            default:
                Initializelevel1(player);
}

}