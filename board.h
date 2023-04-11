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
    std::vector<int> calcCoords(int order);
    public:
        theBoard(std::vector<Player*> players);
        void init();
        void init(const std::string& name, int numPlayers);
        Square* move(Player* p, int steps);
        void save(std::string file);
        void trade(Player* cur, Player* other, std::string give, std::string receive);
        void mortgage(Player* cur, std::string b);
        void unmortgage(Player* cur, std::string b);
        void assets(Player* cur);
        void buyImprovements(Player* cur, std::string building);
        void sellImprovements(Player* cur, std::string building);
        void all();
        void auction(Building *b);
        void bankrupt(Player* cur, Player* owed);
        ~theBoard() { delete td; }
        void collectOsap(Player* cur);
        void goTims(Player* cur);
        void gooseNest(Player* cur);
        void tuition(Player* cur);
        void coopFee(Player* cur);
        void SLC(Player* cur);
        void NH(Player* cur);
        void rollTheRim(Player* cur);
        void auction(std::string name);
        friend std::ostream &operator<<(std::ostream &out, const theBoard &b);
};




#endif