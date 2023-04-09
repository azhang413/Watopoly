#include "square.h"
#include "info.h"

Building *Square::getBuilding() {
    return b;
}

SpecialType Square::checkType() {
    return type;
}

Info Square::getInfo() const {
    Info i{BuildingRow, BuildingCol, PlayerRow, PlayerCol, players};
    return i;
}
