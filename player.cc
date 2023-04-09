#include "player.h"
#include <vector>
using namespace std;

class Academic;
class Residence;
class Gym;

// new player construction
Player::Player(string name, char p): name{name}, money{0}, square{0}, p{p} {
    // initialize empty building pointer arrays for new players
    this->acb = vector<vector<Academic*>>(8); 
}

// player construction based of load
Player::Player(string name,
               int money,
               int square,
               int timsCups,
               char p,
               int place): name{name}, 
               money{money}, square{square}, timsCups{timsCups}, p{p}, place{place} {}

