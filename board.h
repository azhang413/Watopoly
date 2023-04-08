#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include "player.h"
#include "square.h"
#include "display.h"
#include "shuffle.h"

class theBoard {
    std::vector<Square> squares;
    std::vector<Player*> players;
    Display *td;
    void auction(Building *b);
    public:
        theBoard();
        ~theBoard() { delete td; }
        void move(Player *p, int steps);
};

#endif