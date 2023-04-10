#include "player.h"
#include "building.h"
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
               money{money}, square{square}, timsCups{timsCups}, p{p}, place{place} {
                this->acb = vector<vector<Academic*>>(8);
               }

bool Player::removeBuilding(Building* b) {
    bool found = false;
    for (size_t i = 0; i < acb.size(); ++i) {
        for (auto ac = acb[i].begin(); ac != acb[i].end(); ++ac) {
            if (*ac == b) {
                found = true;
                acb[i].erase(ac);
            }
        }
    }
    for (auto res = resb.begin(); res != resb.end(); ++res) {
        if (*res == b) {
            found = true;
            resb.erase(res);
        }
    }
    for (auto gym = gymb.begin(); gym != gymb.end(); ++gym) {
        if (*gym == b) {
            found = true;
            gymb.erase(gym);
        }
    }
    return found;
}
