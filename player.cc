#include "player.h"
#include <vector>
using namespace std;

class Piece;
class Academic;
class Residence;
class Gym;

// new player construction
Player::Player(Piece p): money{0}, square{0}, p{p} {
    // initialize empty building pointer arrays for new players
    this->acb = new vector<Academic*>{};
    this->resb = new vector<Residence*>{};
    this->gymb = new vector<Gym*>{};
}

// player construction based of load
Player::Player(int money,
               int square,
               Piece p,
               const vector<Academic*> acb,
               const vector<Residence*> resb,
               const vector<Gym*> gymb):
               money{money}, square{square}, p{p}, acb{acb}, resb{resb}, gymb{gymb} {}