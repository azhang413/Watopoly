#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <vector>
#include <string>

class Academic;
class Residence;
class Gym;

struct Player {
    const std::string name;
    int money;
    int square;
    int timsCups;
    const char p;
    int place;
    std::vector<std::vector<Academic*>> acb;
    std::vector<Residence*> resb;
    std::vector<Gym*> gymb;
    // construct new player
    Player(std::string name, char p);
    // construct player based off load
    Player(std::string name,
           int money, 
           int square, 
           int timCups,
           char p, 
           int place);
};

#endif