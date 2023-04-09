#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "subject.h"

class Building;
class Player;
struct Info;

enum class SpecialType {Academic, Residence, Gym, TimsLine, GoToTims, Osap, SLC, NH , Goose, Tuition, Coop };

class Square : public Subject<Info> {
    Building *b;
    public:
    SpecialType type;
    int BuildingRow, BuildingCol, PlayerRow, PlayerCol; 
    std::vector<Player> players;
    Square(SpecialType type, Building *b) : type{type}, b{b} {}
    Building *getBuilding();
    SpecialType checkType();
    Info getInfo() const override;
};


#endif

