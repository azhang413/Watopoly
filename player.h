#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <vector>

class Academic;
class Residence;
class Gym;

enum class Piece{Goose, Bus, Doughnut, Prof, Student, Money, Laptop, Tie};

struct Player {
    int money;
    int square;
    Piece p;
    std::vector<Academic*> acb;
    std::vector<Residence*> resb;
    std::vector<Gym*> gymb;
    // construct new player
    Player(Piece p);
    // construct player based off load
    Player(int money, 
           int square, 
           Piece p, 
           const std::vector<Academic*> &acb, 
           const std::vector<Residence*> &resb,
           const std::vector<Gym*> gymb);
};

#endif