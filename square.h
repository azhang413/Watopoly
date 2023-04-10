#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "subject.h"


class Building;
class Player;

enum class SpecialType {Academic, Residence, Gym, TimsLine, GoToTims, Osap, SLC, NH , Goose, Tuition, Coop };

class Square : public Subject<Info> {
    SpecialType type;
    Building *b;
    public:
        Square(SpecialType type, Building *b) : type{type}, b{b} {}
        Square(SpecialType type): type{type}, b{nullptr} {}
        Building *getBuilding();
        SpecialType checkType();
};


#endif

