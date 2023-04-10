#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "subject.h"
#include "info.h"


class Building;
class Player;

enum class SpecialType {Academic, Residence, Gym, TimsLine, GoToTims, Osap, SLC, NH , Goose, Tuition, Coop };

class Square : public Subject<Info> {
    const int BuildingRow, BuildingCol, PlayerRow, PlayerCol; // rmb to construct
    std::vector<Player*> players;
    const SpecialType type;
    Building *b;
    public:
        Square(int BuildingRow, int BuildingCol, int PlayerRow, int PlayerCol, SpecialType type, Building *b) : BuildingRow{BuildingRow}, BuildingCol{BuildingCol}, PlayerRow{PlayerRow}, PlayerCol{PlayerCol}, type{type}, b{b} {}
        Square(int BuildingRow, int BuildingCol, int PlayerRow, int PlayerCol, SpecialType type): BuildingRow{BuildingRow}, BuildingCol{BuildingCol}, PlayerRow{PlayerRow}, PlayerCol{PlayerCol}, type{type}, b{nullptr} {}
        Building *getBuilding();
        SpecialType checkType();
        Info getInfo() const override;
        ~Square() override; 
};


#endif

