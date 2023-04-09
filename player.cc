#include "player.h"
#include <vector>
#include <string>
using namespace std;

class Academic;
class Residence;
class Gym;

// new player construction
Player::Player(string name, char p): name{name}, money{1500}, square{0}, timsCups{0}, p{p}, place{0} {
    // initialize empty building pointer arrays for new players
    this->acb = new vector<Academic*>{};
    this->resb = new vector<Residence*>{};
    this->gymb = new vector<Gym*>{};
}

// player construction based of load
Player::Player(int money,
               int square,
               int timsCups,
               char p
               int place):
               money{money}, square{square}, timsCups{timsCups}, p{p}, place{place} {
    this->acb = new vector<vector<Academic*>>;
    this->resb = new vector<Residence*>;
    this->gymb = new vector<Gym*>;
}