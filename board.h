#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
#include "player.h"
#include "square.h"
#include "display.h"
#include "shuffle.h"

void Tokenize(std::string str, std::vector<std::string> &out, const std::string delim = " ");
int getInd(std::vector<std::string> v, std::string s);

class theBoard {
    std::vector<Square*> squares;
    std::vector<Player*> players;
    Display *td;
    void auction(Building *b);
    std::vector<int> calcCoords(int order);
    public:
        theBoard(std::vector<Player*> players);
        void init();
        void init(const std::string& name, int numPlayers);
        ~theBoard() { delete td; }
        // void move(Player *p, int steps);
        friend std::ostream &operator<<(std::ostream &out, const theBoard &b);
};




#endif