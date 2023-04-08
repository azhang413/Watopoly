#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <vector>

class Academic;
class Residence;
class Gym;

struct Player {
    int money;
    int square;
    int timsCups;
    char p;
    int place;
    std::vector<std::vector<Academic*>> acb;
    std::vector<Residence*> resb;
    std::vector<Gym*> gymb;
    // construct new player
    Player(char p);
    // construct player based off load
    Player(int money, 
           int square, 
           int timCups;
           char p, 
           int place);
};

#endif