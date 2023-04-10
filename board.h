#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
#include "player.h"
#include "square.h"
#include "display.h"
#include "shuffle.h"

class Building;

std::vector<std::string> Tokenize(std::string str);
int getInd(std::vector<std::string> v, std::string s);

class theBoard {
    std::vector<Square*> squares;
    std::vector<Player*> players;
    Player* bank;
    Display *td;
    void auction(Building *b);
    std::vector<int> calcCoords(int order);
    public:
        theBoard(std::vector<Player*> players);
        void init();
        void init(const std::string& name, int numPlayers);
        Building* move(Player* p, int steps);
        void save(std::string file);
        void trade(Player* cur, Player* other, std::string give, std::string receive);
        void mortgage(Player* cur, std::string b);
        void unmortgage(Player* cur, std::string b);
        void assets(Player* cur);
        void all();
        void bankrupt(Player* cur);
        ~theBoard() { delete td; }
        // void move(Player *p, int steps);
        friend std::ostream &operator<<(std::ostream &out, const theBoard &b);
};




#endif