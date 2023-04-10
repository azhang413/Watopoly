#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
#include "player.h"
#include "square.h"
#include "display.h"
#include "shuffle.h"

void Tokenize(string str, vector<string> &out, const string delim = " ");
int getInd(vector<string> v, string s);

class theBoard {
    std::vector<Square*> squares;
    std::vector<Player*> players;
    Display *td;
    void auction(Building *b);
    public:
        theBoard(vector<Player*> players);
        void init();
        void init(const string& name, int numPlayers);
        ~theBoard() { delete td; }
        // void move(Player *p, int steps);
        friend std::ostream &operator<<(std::ostream &out, const theBoard &b);
};




#endif