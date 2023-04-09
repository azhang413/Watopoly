#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
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
        void init(string file = "");
        ~theBoard() { delete td; }
        void move(Player *p, int steps);
        friend std::ostream &operator<<(std::ostream out, const theBoard &b);
};



#endif